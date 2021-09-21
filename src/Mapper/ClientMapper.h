#ifndef SQLBACKUPTOFTPSERVER_CLIENTMAPPER_H
#define SQLBACKUPTOFTPSERVER_CLIENTMAPPER_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of ClientMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "IClient.h"

namespace ftp {
class Client;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////


class ClientMapper : public app::IClient
{
public:
    ClientMapper();
    ~ClientMapper();

    ClientMapper(const ClientMapper&) = delete;
    ClientMapper(ClientMapper&&) noexcept = delete;
    ClientMapper& operator=(const ClientMapper&) = delete;
    ClientMapper& operator=(ClientMapper&&) noexcept = delete;

    /**
     * @brief               Connects to the FTP server.
     * @param userName      The user name.
     * @param password      The password.
     * @param ftpHost       The FTP host.
     * @param remotePath    The FTP remote path.
     * @param ftpPort       The FTP port.
     */
    void connect(const std::string& userName
           , const std::string& password
           , const std::string& ftpHost
           , const std::string& remotePath
           , uint32_t ftpPort) override;

    /**
     * @brief Sends the file to the FTP server.
     * @param path The path to the file.
     */
    void upload(std::filesystem::path path) override;

private:
    std::unique_ptr<ftp::Client> m_pClient;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////



#endif // SQLBACKUPTOFTPSERVER_CLIENTMAPPER_H
