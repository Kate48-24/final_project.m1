#pragma once
#include <vector>
#include "Message.h"


class Chat
{
public:
	void registration();
	void registration(std::string login, std::string password, std::string name); //for testing the program
	bool login();
	void userMenu();
	void addMessage();
	void showMessage();
	std::shared_ptr <User> _currentUser = nullptr;

private:
	std::vector <User> _users;			//to store user logins
	std::vector <Message> _messages;	//to store all messages


};
