/**
 * @file        UserDataAccessorMapper.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of UserDataAccessorMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#ifndef SQLBACKUPTOFTPSERVER_USERDATAACCESSORMAPPER_H
#define SQLBACKUPTOFTPSERVER_USERDATAACCESSORMAPPER_H

#include <vector>

#include "IUserDataAccessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////

class UserDataAccessorMapper : public app::IUserDataAccessor
{
public:
    UserDataAccessorMapper() = default;
    UserDataAccessorMapper(const UserDataAccessorMapper&) = default;
    UserDataAccessorMapper(UserDataAccessorMapper&&) noexcept = default;
    UserDataAccessorMapper& operator=(const UserDataAccessorMapper&) = default;
    UserDataAccessorMapper& operator=(UserDataAccessorMapper&&) noexcept = default;
    ~UserDataAccessorMapper() override = default;

    /**
     * @brief Gets the user data.
     * @return The vector with user data.
     */
    [[nodiscard]] std::vector<app::UserData> loadUserData() const override;
};


////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SQLBACKUPTOFTPSERVER_USERDATAACCESSORMAPPER_H
