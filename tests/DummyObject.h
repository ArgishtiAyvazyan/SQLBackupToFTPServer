#ifndef SQLBACKUPTOFTPSERVER_DUMMYOBJECT_H
#define SQLBACKUPTOFTPSERVER_DUMMYOBJECT_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of DummyObject class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */


#include "DataBase.h"

constexpr std::string_view test_db_path = "dummy.db";

struct DummyObject
{
    std::string name;
    int value;

    auto operator<=>(const DummyObject&) const noexcept = default;
};

namespace sqlite {

template <>
struct SqlDBTraits<DummyObject>
{
    static constexpr std::string_view descriptor = "("
                                                   "NAME           TEXT     NOT NULL, "
                                                   "VALUE          INT      NOT NULL);";

    static std::string toValue(const DummyObject& person)
    {
        std::stringstream ss;
        ss << "VALUES('" << person.name << "', " << person.value << ");";
        return ss.str();
    }

    static DummyObject fromValue(int argc, char** argv)
    {
        assert(argc == 2);
        return { argv[0], std::stoi(argv[1]) };
    }
};

} // namespace sqlite


#endif // SQLBACKUPTOFTPSERVER_DUMMYOBJECT_H
