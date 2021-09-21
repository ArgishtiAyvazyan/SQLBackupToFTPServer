#include <iostream>

#include "MainApplication.h"
#include "DataBaseMapper.h"
#include "LoginInfoAssessorMapper.h"
#include "UserDataAccessorMapper.h"
#include "ClientMapper.h"

int main(int argc, char** argv)
try
{
    app::MainApplication app
    {
        std::make_unique<mapping::DataBaseMapper>()
        , std::make_unique<mapping::ClientMapper>()
        , std::make_unique<mapping::LoginInfoAssessorMapper>()
        , std::make_unique<mapping::UserDataAccessorMapper>()
    };
    return app.execute();
}
catch (const std::exception& e)
{
    std::cout << "ERROR: " << e.what() << std::endl;
    return -2;
}
catch (...)
{
    std::cout << "UNKNOWN ERROR." << std::endl;
    return -3;
}
