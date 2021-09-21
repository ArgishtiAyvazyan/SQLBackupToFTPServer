#ifndef SQLBACKUPTOFTPSERVER_ILOGININFOASSESSOR_H
#define SQLBACKUPTOFTPSERVER_ILOGININFOASSESSOR_H

/**
 * @file        ILoginInfoAssessor.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of ILoginInfoAssessor class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <string_view>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @interface ILoginInfoAssessor
 * @brief     The interface declaration for login data loader.
 */
class ILoginInfoAssessor
{
public:
    ILoginInfoAssessor() = default;
    ILoginInfoAssessor(const ILoginInfoAssessor&) = default;
    ILoginInfoAssessor(ILoginInfoAssessor&&) noexcept = default;
    ILoginInfoAssessor& operator=(const ILoginInfoAssessor&) = default;
    ILoginInfoAssessor& operator=(ILoginInfoAssessor&&) noexcept = default;
    virtual ~ILoginInfoAssessor() = default;

    /**
     * @brief  Gets the user set the DataBase path.
     * @return The string representation of path.
     */
    [[nodiscard]] virtual std::string getDataBasePath() const noexcept = 0;

    /**
     * @brief  Gets the user name.
     * @return The string representation of user name.
     */
    [[nodiscard]] virtual std::string getUserName() const noexcept = 0;

    /**
     * @brief  Gets the password.
     * @return The string representation of user password.
     */
    [[nodiscard]] virtual std::string getPassword() const noexcept = 0;

    /**
     * @brief  Gets the user set the FTP host.
     * @return The string representation of FTP host.
     */
    [[nodiscard]] virtual std::string getFTPHost() const noexcept = 0;

    /**
     * @brief  Gets the user set the FTP server remote path.
     * @return The string representation of remote path.
     */
    [[nodiscard]] virtual std::string getRemotePath() const noexcept = 0;

    /**
     * @brief  Gets the user set the FTP port.
     * @return The string representation of FTP port.
     */
    [[nodiscard]] virtual int32_t getFTPPort() const noexcept = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_ILOGININFOASSESSOR_H
