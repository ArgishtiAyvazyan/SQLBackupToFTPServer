#ifndef SQLBACKUPTOFTPSERVER_IUSERDATAACCESSOR_H
#define SQLBACKUPTOFTPSERVER_IUSERDATAACCESSOR_H

/**
 * @file        IUserDataAccessor.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of IUserDataAccessor class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "UserData.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @interface IUserDataAccessor
 * @brief     The interface declaration for user data loader.
 */
class IUserDataAccessor
{
public:
    IUserDataAccessor() = default;
    IUserDataAccessor(const IUserDataAccessor&) = default;
    IUserDataAccessor(IUserDataAccessor&&) noexcept = default;
    IUserDataAccessor& operator=(const IUserDataAccessor&) = default;
    IUserDataAccessor& operator=(IUserDataAccessor&&) noexcept = default;
    virtual ~IUserDataAccessor() = default;

    /**
     * @brief Gets the user data.
     * @return The vector with user data.
     */
    [[nodiscard]] virtual std::vector<UserData> loadUserData() const = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SQLBACKUPTOFTPSERVER_IUSERDATAACCESSOR_H
