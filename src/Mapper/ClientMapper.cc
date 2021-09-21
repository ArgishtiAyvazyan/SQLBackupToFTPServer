/**
 * @file        ClientMapper.cc
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of ClientMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "ClientMapper.h"

#include "Client.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////

ClientMapper::ClientMapper() = default;
ClientMapper::~ClientMapper() = default;

void ClientMapper::connect(const std::string& userName, const std::string& password
                           , const std::string& ftpHost, const std::string& remotePath
                           , uint32_t ftpPort)
{
    m_pClient = std::make_unique<ftp::Client>(userName, password, ftpHost, remotePath, ftpPort);
}

void ClientMapper::upload(std::filesystem::path path)
{
    m_pClient->upload(path.string());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////


