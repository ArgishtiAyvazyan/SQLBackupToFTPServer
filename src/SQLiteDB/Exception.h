#ifndef SQLBACKUPTOFTPSERVER_EXCEPTION_H
#define SQLBACKUPTOFTPSERVER_EXCEPTION_H

/**
 * @file        DataBase.h
 * @author      Argishti Ayvazyan (ayvazyan.argishti@gmail.com)
 * @brief       Declaration of Exception class.
 * @date        9/20/2021
 * @copyright   Copyright (c) 2021
 */


#include <exception>

////////////////////////////////////////////////////////////////////////////////////////////////////
namespace sqlite {
////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Exception
 *
 * @brief The exception class for handling SQLite errors.
 */
class Exception : public std::runtime_error
{
    using error_t = int32_t;
public:
    Exception() = default;
    ~Exception() override = default;
    Exception(Exception&&) = default;
    Exception(const Exception&) = default;
    Exception& operator=(Exception&&) = default;
    Exception& operator=(const Exception&) = default;

    explicit Exception(const std::string& massage, error_t errorCode) noexcept
        : std::runtime_error(massage)
        , m_errorCode(errorCode)
    { }

    error_t getErrorCode() const noexcept
    {
        return m_errorCode;
    }

private:
    error_t m_errorCode;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace sqlite
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // SQLBACKUPTOFTPSERVER_EXCEPTION_H
