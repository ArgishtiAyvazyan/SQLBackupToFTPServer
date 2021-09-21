#ifndef SQLBACKUPTOFTPSERVER_LOGININFOASSESSORMAPPER_H
#define SQLBACKUPTOFTPSERVER_LOGININFOASSESSORMAPPER_H

/**
 * @file        LoginInfoAssessorMapper.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of LoginInfoAssessorMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "ILoginInfoAssessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////

class LoginInfoAssessorMapper : public app::ILoginInfoAssessor
{
public:

    LoginInfoAssessorMapper() = default;
    ~LoginInfoAssessorMapper() override = default;
    LoginInfoAssessorMapper(const LoginInfoAssessorMapper&) = delete;
    LoginInfoAssessorMapper(LoginInfoAssessorMapper&&) noexcept = delete;
    LoginInfoAssessorMapper& operator=(const LoginInfoAssessorMapper&) = delete;
    LoginInfoAssessorMapper& operator=(LoginInfoAssessorMapper&&) noexcept = delete;

    /**
     * @brief  Gets the user set the DataBase path.
     * @return The string representation of path.
     */
    [[nodiscard]] std::string getDataBasePath() const noexcept override;

    /**
     * @brief  Gets the user name.
     * @return The string representation of user name.
     */
    [[nodiscard]] std::string getUserName() const noexcept override;

    /**
     * @brief  Gets the password.
     * @return The string representation of user password.
     */
    [[nodiscard]] std::string getPassword() const noexcept override;

    /**
     * @brief  Gets the user set the FTP host.
     * @return The string representation of FTP host.
     */
    [[nodiscard]] std::string getFTPHost() const noexcept override;

    /**
     * @brief  Gets the user set the FTP server remote path.
     * @return The string representation of remote path.
     */
    [[nodiscard]] std::string getRemotePath() const noexcept override;

    /**
     * @brief  Gets the user set the FTP port.
     * @return The string representation of FTP port.
     */
    [[nodiscard]] int32_t getFTPPort() const noexcept override;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_LOGININFOASSESSORMAPPER_H
