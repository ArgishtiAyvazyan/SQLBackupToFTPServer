//
// Created by argis on 9/21/2021.
//

#ifndef SQLBACKUPTOFTPSERVER_DATABASEMAPPER_H
#define SQLBACKUPTOFTPSERVER_DATABASEMAPPER_H

#include "IDataBase.h"

namespace sqlite {
class DataBase;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping {
////////////////////////////////////////////////////////////////////////////////////////////////////


class DataBaseMapper : public app::IDataBase
{
public:

    DataBaseMapper();
    ~DataBaseMapper();

    DataBaseMapper(const DataBaseMapper&) = delete;
    DataBaseMapper(DataBaseMapper&&) noexcept = delete;
    DataBaseMapper& operator=(const DataBaseMapper&) = delete;
    DataBaseMapper& operator=(DataBaseMapper&&) noexcept = delete;

    /**
     * @brief           Instantiate a new DataBase object and try to open a new database connection.
     * @param dbName    The Database filename.
     */
    void connect(std::string_view dbName) override;

    /**
     * @brief Stores the user data to the Database.
     * @param userData The user data.
     */
    void storeData(const std::vector<app::UserData>& userData) override;

    /**
     * @brief  Loads the user data from the database.
     * @return The collection of user data.
     */
    [[nodiscard]] std::vector<app::UserData> loadData() const override;

private:

    std::unique_ptr<sqlite::DataBase> m_pDataBase;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping
////////////////////////////////////////////////////////////////////////////////////////////////////


#endif // SQLBACKUPTOFTPSERVER_DATABASEMAPPER_H
