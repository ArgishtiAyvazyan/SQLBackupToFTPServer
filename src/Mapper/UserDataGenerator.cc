/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Implementation of UserDataGenerator class.
 * @date        9/21/2021
 * @copyright   Copyright (c) 2021
 */

#include "UserDataGenerator.h"

#include "UserData.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
namespace mapping::utils {
////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<app::UserData> UserDataGenerator::generate() const
{
    using namespace std::string_literals;

    constexpr size_t dataCount = 100;
    std::vector<app::UserData> result;
    result.reserve(dataCount);

    for(size_t i = 0; i < dataCount; ++i)
    {
        result.emplace_back(std::string { "name_"s + std::to_string(i) },
                            std::string { "surname_"s + std::to_string(i) }, i);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace mapping::utils
////////////////////////////////////////////////////////////////////////////////////////////////////

