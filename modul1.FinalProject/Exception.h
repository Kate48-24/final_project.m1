#pragma once
#include <exception>
using namespace std;

class LoginException: public exception
{
public:
    const char* what() const noexcept override
{
        return "Error: Login is already in use!";
}
};