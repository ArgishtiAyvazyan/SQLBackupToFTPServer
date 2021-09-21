#ifndef SQLBACKUPTOFTPSERVER_ICLIENT_H
#define SQLBACKUPTOFTPSERVER_ICLIENT_H

/**
 * @file        IClient.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of IClient class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <filesystem>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @interface IClient
 * @brief     The interface declaration for working with clients.
 */
class IClient
{
public:
    IClient() = default;
    IClient(const IClient&) = default;
    IClient(IClient&&) noexcept = default;
    IClient& operator=(const IClient&) = default;
    IClient& operator=(IClient&&) noexcept = default;
    virtual ~IClient() = default;

    /**
     * @brief               Connects to the FTP server.
     * @param userName      The user name.
     * @param password      The password.
     * @param ftpHost       The FTP host.
     * @param remotePath    The FTP remote path.
     * @param ftpPort       The FTP port.
     */
    virtual void connect(const std::string& userName
           , const std::string& password
           , const std::string& ftpHost
           , const std::string& remotePath
           , uint32_t ftpPort) = 0;

    /**
     * @brief Sends the file to the FTP server.
     * @param path The path to the file.
     */
    virtual void upload(std::filesystem::path path) = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_ICLIENT_H
