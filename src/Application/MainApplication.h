#ifndef SQLBACKUPTOFTPSERVER_MAINAPPLICATION_H
#define SQLBACKUPTOFTPSERVER_MAINAPPLICATION_H

/**
 * @file        MainApplication.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of IDataBase class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <memory>

#include "IDataBase.h"
#include "IClient.h"
#include "ILoginInfoAssessor.h"
#include "IUserDataAccessor.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class       MainApplication
 * @brief       The main class of application.
 *
 * @details     The MainApplication class manages the application control flow and main settings.
 *              MainApplication is an entry point.
 */
class MainApplication
{
    static constexpr std::string_view sm_backupFileName = "backupFile.txt";

public:
    using TDataBasePtr = std::unique_ptr<IDataBase>;
    using TClientPtr = std::unique_ptr<IClient>;
    using TLoginInfoAssessorPtr = std::unique_ptr<ILoginInfoAssessor>;
    using TUserDataAccessorPtr = std::unique_ptr<IUserDataAccessor>;

    MainApplication() = delete;
    ~MainApplication() = default;
    MainApplication(const MainApplication&) = delete;
    MainApplication(MainApplication&&) noexcept = delete;
    MainApplication& operator=(const MainApplication&) = delete;
    MainApplication& operator=(MainApplication&&) noexcept = delete;

    MainApplication(TDataBasePtr pDataBase, TClientPtr pClient, TLoginInfoAssessorPtr pLoginInfoAcc,
                    TUserDataAccessorPtr pUserDataAcc);

    /**
     * @brief   Runs execute application.
     *
     * @return  The execution status, 0 if the application executes successfully.
     */
    int execute();

private:

    /**
     * @brief Creates a database and stores user data into DB.
     */
    void createDB();

    /**
     * @brief Creates backup file for DataBase.
     */
    void backup();

    /**
     * @brief Sends the backup file to the FTP server.
     */
    void sendBackup();

private:
    TDataBasePtr m_pDataBase;
    TClientPtr m_pClient;
    TLoginInfoAssessorPtr m_pLoginInfoAcc;
    TUserDataAccessorPtr m_pUserDataAcc;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SQLBACKUPTOFTPSERVER_MAINAPPLICATION_H
