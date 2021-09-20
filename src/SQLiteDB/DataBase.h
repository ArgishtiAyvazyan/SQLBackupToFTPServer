#ifndef SQLBACKUPTOFTPSERVER_DATABASE_H
#define SQLBACKUPTOFTPSERVER_DATABASE_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of DataBase class.
 * @date        9/20/2021
 * @copyright   Copyright (c) 2021
 */

#include <algorithm>
#include <string_view>
#include <exception>
#include <memory>
#include <sstream>

#include "Exception.h"

struct sqlite3;

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace sqlite {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief  To serialize and deserialize objects into DataBase, for the type of object should be
 *         implemented specialization for  SqlDBTraits.
 *
 * @details The specialization should have static method toValue, fromValue methods, and descriptor
 *          static string variable.
 *          The method toValue should convert the object to the DataBase row value and return it
 *          as a string.
 *          The method fromValue should convert the DataBase row value the object to and return it.
 *          The static variable descriptor should describe the table structure for given type.
 *
 * @example
 *          class Person
 *          {
 *          public:
 *              Person() = delete;
 *              Person(std::string name, std::string surname, int age)
 *                  : m_name (std::move(name))
 *                  , m_surname (std::move(surname))
 *                  , m_age(age)
 *              { }
 *
 *              [[nodiscard]] std::string_view getName() const noexcept { return m_name; }
 *
 *              [[nodiscard]] std::string_view getSurname() const noexcept { return m_surname; }
 *
 *              [[nodiscard]] auto getAge() const noexcept { return m_age; }
 *
 *          private:
 *              std::string m_name;
 *              std::string m_surname;
 *              int m_age;
 *          };
 *          template <>
 *          struct SqlDBTraits<Person>
 *          {
 *              static constexpr std::string_view descriptor = "("
 *                                "NAME           TEXT     NOT NULL, "
 *                                "SURNAME        TEXT     NOT NULL, "
 *                                "AGE            INT      NOT NULL);";
 *
 *              static std::string toValue(const Person& person)
 *              {
 *                  std::stringstream ss;
 *                  ss << "VALUES('"
 *                      << person.getName() << "', '"
 *                      << person.getSurname() << "', "
 *                      << person.getAge() << ");";
 *                  return ss.str();
 *              }
 *
 *              static Person fromValue(int argc, char** argv)
 *              {
 *                  assert(argc == 3);
 *                  return { argv[0], argv[1], std::stoi(argv[2]) };
 *              }
 *          };
 *
 * @tparam T The type of serializable object.
 */
template <typename T>
struct SqlDBTraits;

template <typename TIt, typename TValue>
concept isOutIterator = requires(TIt it, TValue value)
{
    *it = value;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class   DataBase
 * @brief   This is a simple type safe SQLite wrapper written in c++. SQLite is an embedded SQL
 *          database engine. SQLite does not have a separate server process. SQLite reads and writes
 *          directly to ordinary disk files.
 *
 * @note    The database wrapper provides the type-safe interface for serializing and deserializing
 *          objects. For working with custom types, they should have to implement SqlDBTraits Traits.
 *
 * @details The DataBase implemented based on sqlite3.
 */
class DataBase
{
    /**
     * The type of callback function pointer.
     */
    using callback_t = std::add_pointer_t<int(void*, int, char**, char**)>;

public:

    /**
     * @brief   Instantiate a new DataBase object and try to open a new database connection.
     *
     * @throws  sqlite::Exception if connection opening failed.
     * @param dbName The Database filename.
     */
    explicit DataBase(std::string_view dbName);

    ~DataBase() = default;
    DataBase(const DataBase&) = default;
    DataBase(DataBase&&) noexcept = default;
    DataBase& operator=(const DataBase&) = default;
    DataBase& operator=(DataBase&&) noexcept = default;

    /**
     * @brief   Creates the table for the specified types.
     *
     * @tparam TValue   Prototype of the table.
     * @param tableName The name of table.
     */
    template <typename TValue>
    void creatTableFor(std::string_view tableName);

    /**
     * @brief One-Step Query Execution Interface.
     * @param query  The Query string.
     */
    void execute(std::string_view query);

    /**
     * @brief Inserts the specified object into the database.
     *
     * @throws sqlite::Exception if insertion failed.
     * @tparam TValue The type of object which should be serialized.
     * @param query   The query.
     * @param value   The object which should be serialized.
     */
    template <typename TValue>
    void execute(std::string query, TValue value);

    /**
     * @brief Insert the specified objects range into the database.
     *
     * @throws sqlite::Exception if insertion failed.
     * @tparam TIter    The type of range iterator.
     * @param query     The query.
     * @param start     The begin of range.
     * @param end       The end of range.
     */
    template <typename TIter>
    void execute(std::string query, TIter start, TIter end);

    /**
     * @brief   Gets the objects by specific query and insert into output iterator.
     *
     * @tparam TOutValue The type of value.
     * @tparam TOutIter  The type of output iterator.
     * @param query      The specific query.
     * @param it         The output iterator.
     */
    template <typename TOutValue, typename TOutIter>
    void execute(std::string_view query, TOutIter it) requires(isOutIterator<TOutIter, TOutValue>);


private:
    template <typename TOutValue, typename TOutIter>
    static int dataOutCallBack(void* data, int argc, char** argv, char** colName);
    void executeImpl(std::string_view query, callback_t callBack, void* dataProcessor);


private:
    std::shared_ptr<sqlite3> m_db;
}; // class DataBase
////////////////////////////////////////////////////////////////////////////////////////////////////


template <typename TOutValue, typename TOutIter>
int sqlite::DataBase::dataOutCallBack(void* data, int argc, char** argv, char** colName)
{
    auto* outIt = static_cast<TOutIter*>(data);
    outIt->operator=(SqlDBTraits<TOutValue>::fromValue(argc, argv));
    return 0;
}

template <typename TValue>
void sqlite::DataBase::execute(std::string query, TValue value)
{
    using namespace std::string_literals;
    query += " "s;
    query += SqlDBTraits<TValue>::toValue(value);
    executeImpl(query, nullptr, nullptr);
}

template <typename TIter>
void sqlite::DataBase::execute(std::string query, TIter start, TIter end)
{
    using namespace std::string_literals;
    using value_t = typename std::iterator_traits<TIter>::value_type;
    query += " "s;
    std::for_each(start, end, [this, &query](const auto& value) {
        executeImpl(query + SqlDBTraits<value_t>::toValue(value), nullptr, nullptr);
    });
}

template <typename TValue>
void DataBase::creatTableFor(std::string_view tableName)
{
    std::stringstream ss;
    ss << "CREATE TABLE " << tableName << SqlDBTraits<TValue>::descriptor;

    execute(ss.str());
}

template <typename TOutValue, typename TOutIter>
void DataBase::execute(std::string_view query, TOutIter it) requires(isOutIterator<TOutIter, TOutValue>)
{
    executeImpl(query, dataOutCallBack<TOutValue, TOutIter>, &it);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace sqlite
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //SQLBACKUPTOFTPSERVER_DATABASE_H
