
/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of DataBaseMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "DataBase.h"
#include <cassert>

#include "databasemapper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace sqlite {
////////////////////////////////////////////////////////////////////////////////////////////////////

template <>
struct SqlDBTraits<app::UserData>
{
    static constexpr std::string_view descriptor = "("
                      "NAME           TEXT     NOT NULL, "
                      "SURNAME        TEXT     NOT NULL, "
                      "AGE            INT      NOT NULL);";

    static std::string toValue(const app::UserData& person)
    {
        std::stringstream ss;
        ss << "VALUES('"
            << person.getName() << "', '"
            << person.getSurname() << "', "
            << person.getAge() << ");";
        return ss.str();
    }

    static app::UserData fromValue(int argc, char** argv)
    {
        assert(argc == 3);
        return { argv[0], argv[1], std::stoi(argv[2]) };
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace sqlite
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////

DataBaseMapper::DataBaseMapper() = default;
DataBaseMapper::~DataBaseMapper() = default;

void DataBaseMapper::connect(std::string_view dbName)
{
    m_pDataBase = std::make_unique<sqlite::DataBase>(dbName);
}

void DataBaseMapper::storeData(const std::vector<app::UserData>& userData)
{
    m_pDataBase->creatTableFor<app::UserData>("UserDataTable");
    m_pDataBase->execute("INSERT INTO UserDataTable", std::begin(userData), std::end(userData));
}

std::vector<app::UserData> DataBaseMapper::loadData() const
{
    std::vector<app::UserData> userData;
    m_pDataBase->execute<app::UserData>("SELECT * FROM UserDataTable", std::back_inserter(userData));
    return userData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////
