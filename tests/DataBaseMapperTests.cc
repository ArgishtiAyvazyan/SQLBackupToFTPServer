/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of unit tests for DataBaseMapper.
 * @date        9/20/2021
 * @copyright   Copyright (c) 2021
 */

#include <gtest/gtest.h>
#include <filesystem>

#include "DummyObject.h"
#include <DataBaseMapper.h>


TEST(data_base_mapper_testing, query_data)
{
    using namespace std::string_literals;
    try
    {
        mapping::DataBaseMapper db;
        db.connect(test_db_path);

        constexpr int32_t testCount = 100;
        std::vector<app::UserData> target;
        target.reserve(testCount);

        for (int32_t i = 0; i < testCount; ++i)
        {
            target.emplace_back(std::string{"name_"s + std::to_string(i)}
                                , std::string{"surname_"s + std::to_string(i)}
                                , i);
        }

        db.storeData(target);

        std::vector<app::UserData> objects = db.loadData();

        ASSERT_EQ(objects, target);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    ASSERT_TRUE(std::filesystem::exists(test_db_path));
    std::filesystem::remove(test_db_path);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

