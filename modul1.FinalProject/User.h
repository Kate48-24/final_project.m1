#pragma once
#include <string>

class User
{
public:
	User(const std::string login, std::string password, std::string name);

	const std::string getUserLogin() const;
	std::string getUserPassword()const;
	void setUserPassword(std::string password);
	std::string getUserName()const;
	void setUserName(std::string name);

private:
	const std::string _login;
	std::string _password;
	std::string _name;
};