#pragma once
#include <vector>
#include "Message.h"


class Chat
{
public:
	void registration();
	void registration(std::string login, std::string password, std::string name); //to the test of programm
	User login();
	void userMenu();
	void addMessage();
	void getMessage();
	std::shared_ptr <User> _currentUser = nullptr;

private:
	std::vector <User> _users;			//to store user logins
	std::vector <Message> _messages;	//to store all messages


};
