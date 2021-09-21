/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of unit tests for DataBase.
 * @date        9/20/2021
 * @copyright   Copyright (c) 2021
 */


#include <gtest/gtest.h>

#include <DataBase.h>
#include <filesystem>

#include "DummyObject.h"

TEST(data_base_testing, open_conection)
{
    try
    {
        sqlite::DataBase db { test_db_path };
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, create_table)
{
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, double_create_table)
{
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");
        EXPECT_THROW(db.creatTableFor<DummyObject>("DummyTable"), sqlite::Exception);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, wrong_query)
{
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");
        EXPECT_THROW(db.execute("wrong query"), sqlite::Exception);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, insert_data)
{
    using namespace std::string_literals;
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");

        for (int32_t i = 0; i < 100; ++i)
        {
            DummyObject obj { "name_"s + std::to_string(i), i };
            db.execute("INSERT INTO DummyTable", obj);
        }

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, insert_data_range)
{
    using namespace std::string_literals;
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");

        constexpr int32_t testCount = 100;
        std::vector<DummyObject> objects;
        objects.reserve(testCount);

        for (int32_t i = 0; i < testCount; ++i)
        {
            objects.emplace_back(std::string{"name_"s + std::to_string(i)}, i);
        }
        db.execute("INSERT INTO DummyTable", std::begin(objects), std::end(objects));
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

TEST(data_base_testing, query_data)
{
    using namespace std::string_literals;
    try
    {
        sqlite::DataBase db { test_db_path };
        db.creatTableFor<DummyObject>("DummyTable");

        constexpr int32_t testCount = 100;
        std::vector<DummyObject> target;
        target.reserve(testCount);

        for (int32_t i = 0; i < testCount; ++i)
        {
            target.emplace_back(std::string{"name_"s + std::to_string(i)}, i);
        }
        db.execute("INSERT INTO DummyTable", std::begin(target), std::end(target));

        std::vector<DummyObject> objects;
        db.execute<DummyObject>("SELECT * FROM DummyTable", std::back_inserter(objects));

        ASSERT_EQ(objects, target);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        ASSERT_TRUE(false);
    }
    ASSERT_TRUE(true);
    std::filesystem::remove(test_db_path);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
