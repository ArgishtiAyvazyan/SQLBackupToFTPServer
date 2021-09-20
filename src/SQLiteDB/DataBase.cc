/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of DataBase class.
 * @date        9/20/2021
 * @copyright   Copyright (c) 2021
 */


#include "DataBase.h"

#include <sqlite3.h>


sqlite::DataBase::DataBase(std::string_view dbName)
{
    sqlite3* db = nullptr;
    const auto exit = sqlite3_open(dbName.data(), &db);

    if (exit != SQLITE_OK)
    {
        throw Exception{sqlite3_errmsg(m_db.get()), exit};
    }

    m_db.reset(db, sqlite3_close);
}
void sqlite::DataBase::execute(std::string_view query)
{
    executeImpl(query, nullptr, nullptr);
}

void sqlite::DataBase::executeImpl(std::string_view query, DataBase::callback_t callBack, void* dataProcessor)
{
    char *errorMessage = nullptr;
    const auto exit = sqlite3_exec(m_db.get(), query.data(), callBack, dataProcessor, &errorMessage);
    std::unique_ptr<char, void (*)(void *)> errMsg(errorMessage, sqlite3_free);
    if (exit != SQLITE_OK)
    {
        throw Exception {std::string{errMsg.get()}, exit};
    }
}
