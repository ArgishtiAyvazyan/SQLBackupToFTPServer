/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of LoginInfoAssessorMapper class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <iostream>

#include "LoginInfoAssessorMapper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string mapping::LoginInfoAssessorMapper::getDataBasePath() const noexcept
{
    std::string dbPath;
    std::cout << "Enter DataBase path: ";
    std::cin >> dbPath;
    return dbPath;
}

std::string LoginInfoAssessorMapper::getUserName() const noexcept
{
    std::string userName;
    std::cout << "Enter username: ";
    std::cin >> userName;
    return userName;
}

std::string LoginInfoAssessorMapper::getPassword() const noexcept
{
    std::string Password;
    std::cout << "Enter password: ";
    std::cin >> Password;
    return Password;
}

std::string LoginInfoAssessorMapper::getFTPHost() const noexcept
{
    std::string ftpHost;
    std::cout << "Enter FTP host: ";
    std::cin >> ftpHost;
    return ftpHost;
}

std::string LoginInfoAssessorMapper::getRemotePath() const noexcept
{
    std::string remotePath;
    std::cout << "Enter remote path: ";
    std::cin >> remotePath;
    return remotePath;
}

int32_t LoginInfoAssessorMapper::getFTPPort() const noexcept
{
    int32_t port;
    std::cout << "Enter FTP port: ";
    std::cin >> port;
    return port;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////
