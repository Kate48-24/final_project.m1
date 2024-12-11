#include <iostream>
#include "Chat.h"
#include "Exception.h"

void Chat::registration()
{
    std::string login, password, name;
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;
    std::cout << "Enter your username: ";
    std::cin >> name;

    for (const auto& user : _users)
    {
        if (user.getUserLogin() == login)
        {
            throw LoginException();
        }
    }

    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "Registration is completed!" << std::endl;
}

void Chat::registration(std::string login, std::string password, std::string name)
{
    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "login: " << login << ", password: " << password << ", username: " << name << std::endl;
}

User Chat::login()
{
    std::string login, password;

    std::cout << "login: ";
    std::cin >> login;
    std::cout << "password: ";
    std::cin >> password;

    for (auto& user : _users)
    {
        if (login == user.getUserLogin() && password == user.getUserPassword())
        {
            std::cout << "Hello, " << user.getUserName() << "!" << std::endl;
            _currentUser = std::make_shared <User>(user);
            return user;
        }
    }
    std::cout << "Error: Incorrect name or password!" << std::endl;
}

void Chat::userMenu()
{
    bool status_of_user = true;

    while (status_of_user)
    {
        std::cout << "Menu: 1. View messages, 2. Send message, 0. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            getMessage();
            break;
        case 2:
            addMessage();
            break;
        case 0:
            status_of_user = false;
            break;
        default:
            std::cout << "Error, choose 1-2 or 0 for exit to main menu!" << std::endl;
        }
    }
}

void Chat::addMessage()
{
    std::string to, text;
    std::cout << "To: (Login of user or 'all' to send a message to all chat users)" << std::endl;
    std::cin >> to;
    std::string toLogin = "";
    if (to == "all")
    {
        toLogin = "all";
    }
    else
    {
        for (auto& user : _users)
        {
            if (to == user.getUserLogin())
            {
                toLogin = to;
            }
        }
    }
    if (toLogin == "")
    {
        std::cout << "Error: the user's login was not found!" << std::endl;
        return;
    }

    std::cout << "Text: ";

    std::cin.ignore(sizeof(text) / sizeof(text[0]), '\n'); //чтобы можно было вывести все слова в сообщении
    std::getline(std::cin, text);
    std::cin.ignore(0);

    Message message = Message(_currentUser->getUserLogin(), toLogin, text);
    _messages.push_back(message);
    std::cout << "Your message has been sent" << std::endl;
}
void Chat::getMessage()
{
    for (auto& message : _messages)
    {
        if ((message.getTo() == _currentUser->getUserLogin()) || (message.getTo() == "all"))
        {
            std::cout << "---------------------" << std::endl;
            std::cout << "From: " << message.getFrom() << "; To: " << message.getTo() << std::endl;
            std::cout << message.getText() << std::endl;
            std::cout << std::endl;
        }
    }
}