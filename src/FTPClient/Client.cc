/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of DataBase class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "Client.h"

#include <windows.h>
#include <wininet.h>

#pragma comment( lib, "wininet" )


////////////////////////////////////////////////////////////////////////////////////////////////////
namespace ftp {
////////////////////////////////////////////////////////////////////////////////////////////////////

Client::Client(std::string userName
               , std::string password
               , std::string ftpHost
               , std::string remotePath
               , uint32_t ftpPort)
    : m_userName(std::move(userName))
    , m_password(std::move(password))
    , m_ftpHost(std::move(ftpHost))
    , m_remotePath(std::move(remotePath))
    , m_ftpPort(ftpPort)
{
}

void Client::upload(std::string_view filePath)
{
    HINTERNET hInternet = InternetOpen(nullptr, INTERNET_OPEN_TYPE_DIRECT, nullptr, nullptr, 0);

	HINTERNET hFtpSession = InternetConnect(hInternet
		, m_ftpHost.c_str()
		, m_ftpPort
		, m_userName.c_str()
		, m_password.c_str()
		, INTERNET_SERVICE_FTP
		, INTERNET_FLAG_PASSIVE
		, 0);

	FtpPutFile(hFtpSession
		, filePath.data()
		, m_remotePath.data()
		, FTP_TRANSFER_TYPE_BINARY
		, 0);

	InternetCloseHandle(hFtpSession);
	InternetCloseHandle(hInternet);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace ftp
////////////////////////////////////////////////////////////////////////////////////////////////////
