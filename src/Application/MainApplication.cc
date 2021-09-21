/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of IDataBase class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <cassert>
#include <iostream>
#include <fstream>
#include <ranges>

#include "MainApplication.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

MainApplication::MainApplication(TDataBasePtr pDataBase, TClientPtr pClient,
                                 TLoginInfoAssessorPtr pLoginInfoAcc, TUserDataAccessorPtr pUserDataAcc)
    : m_pDataBase(std::move(pDataBase))
    , m_pClient(std::move(pClient))
    , m_pLoginInfoAcc(std::move(pLoginInfoAcc))
    , m_pUserDataAcc(std::move(pUserDataAcc))
{
    assert(nullptr != m_pDataBase);
    assert(nullptr != m_pClient);
    assert(nullptr != m_pLoginInfoAcc);
    assert(nullptr != m_pUserDataAcc);
}

int MainApplication::execute()
{
    try
    {
        createDB();
        backup();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void MainApplication::createDB()
{
    auto userData = m_pUserDataAcc->loadUserData();
    m_pDataBase->connect(m_pLoginInfoAcc->getDataBasePath());
    m_pDataBase->storeData(userData);
}

void MainApplication::backup()
{
    const auto arrUserData = m_pDataBase->loadData();
    std::fstream fOut { sm_backupFileName, std::ios_base::app };
    std::ostream_iterator<UserData> outIt(fOut, "\n");
    std::ranges::copy(arrUserData, outIt);
}

void MainApplication::sendBackup()
{
    m_pClient->connect(m_pLoginInfoAcc->getUserName(), m_pLoginInfoAcc->getPassword(),
                       m_pLoginInfoAcc->getFTPHost(), m_pLoginInfoAcc->getRemotePath(),
                       m_pLoginInfoAcc->getFTPPort());
    m_pClient->upload(sm_backupFileName);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////////////////////////
