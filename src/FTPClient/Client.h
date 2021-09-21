#ifndef SQLBACKUPTOFTPSERVER_CLIENT_H
#define SQLBACKUPTOFTPSERVER_CLIENT_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of DataBase class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace ftp {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Client
 * @brief The class Client provides a file sending interface to the FTP server.
 *
 * @details The Client implemented based on Windows wininet APIs.
 */
class Client
{
public:
    Client(std::string userName
           , std::string password
           , std::string ftpHost
           , std::string remotePath
           , uint32_t ftpPort);

    /**
     * @brief Uploads the given file to the FTP server.
     * @param filePath The file path.
     */
    void upload(std::string_view filePath);

private:
    std::string m_userName;
    std::string m_password;
    std::string m_ftpHost;
    std::string m_remotePath;
    uint32_t m_ftpPort;
}; // class Client

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace ftp
////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SQLBACKUPTOFTPSERVER_CLIENT_H
