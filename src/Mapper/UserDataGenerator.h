#ifndef SQLBACKUPTOFTPSERVER_USERDATAGENERATOR_H
#define SQLBACKUPTOFTPSERVER_USERDATAGENERATOR_H

/**
 * @file        UserDataGenerator.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of UserDataGenerator class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <vector>


namespace app {
class UserData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping::utils {
////////////////////////////////////////////////////////////////////////////////////////////////////


class UserDataGenerator
{
public:
    UserDataGenerator() = default;
    ~UserDataGenerator() = default;
    UserDataGenerator(const UserDataGenerator&) = delete;
    UserDataGenerator(UserDataGenerator&&) noexcept = delete;
    UserDataGenerator& operator=(const UserDataGenerator&) = delete;
    UserDataGenerator& operator=(UserDataGenerator&&) noexcept = delete;

    [[nodiscard]] std::vector<app::UserData> generate() const;
}; // class UserDataGenerator

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping::utils
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_USERDATAGENERATOR_H
