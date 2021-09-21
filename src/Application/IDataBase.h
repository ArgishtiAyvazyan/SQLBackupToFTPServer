#ifndef SQLBACKUPTOFTPSERVER_IDATABASE_H
#define SQLBACKUPTOFTPSERVER_IDATABASE_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of IDataBase class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include <vector>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace app {
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UserData.h"

/**
 * @interface   IDataBase
 * @brief       The interface declaration for working with DataBase.
 */
class IDataBase
{
public:

    /**
     * @brief           Instantiate a new DataBase object and try to open a new database connection.
     * @param dbName    The Database filename.
     */
    virtual void connect(std::string_view dbName) = 0;

    /**
     * @brief Stores the user data to the Database.
     * @param userData The user data.
     */
    virtual void storeData(const std::vector<UserData>& userData) = 0;

    /**
     * @brief  Loads the user data from the database.
     * @return The collection of user data.
     */
    [[nodiscard]] virtual std::vector<UserData> loadData() const  = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace app
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_IDATABASE_H
