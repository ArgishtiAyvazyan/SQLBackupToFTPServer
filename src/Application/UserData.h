#ifndef SQLBACKUPTOFTPSERVER_USERDATA_H
#define SQLBACKUPTOFTPSERVER_USERDATA_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of UserData class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class UserData
 * @brief The declaration of user data.
 */
class UserData
{
public:
    UserData() = delete;
    UserData(const UserData&) = default;
    UserData(UserData&&) noexcept = default;
    UserData& operator=(const UserData&) = default;
    UserData& operator=(UserData&&) noexcept = default;
    ~UserData() = default;
    UserData(std::string name, std::string surname, int age)
        : m_name(std::move(name))
        , m_surname(std::move(surname))
        , m_age(age)
    {
    }

    [[nodiscard]] std::string_view getName() const noexcept
    {
        return m_name;
    }

    [[nodiscard]] std::string_view getSurname() const noexcept
    {
        return m_surname;
    }

    [[nodiscard]] auto getAge() const noexcept
    {
        return m_age;
    }

private:
    std::string m_name;
    std::string m_surname;
    int m_age;
};

std::ostream& operator<<(std::ostream& os, const UserData& data)
{
    os << data.getName() << ", " << data.getSurname() << ", " << data.getAge();
    return os;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_USERDATA_H
