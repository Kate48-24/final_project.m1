#include <iostream>
#include "Chat.h"

void Chat::registration()
{
    std::string login, password, name;
    std::cout << "Введите логин: ";
    std::cin >> login;
    std::cout << "Введите пароль: ";
    std::cin >> password;
    std::cout << "Введите имя: ";
    std::cin >> name;

    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "Регистрация завершена!" << std::endl;
}

void Chat::registration(std::string login, std::string password, std::string name)
{
    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "логин: " << login << ", пароль: " << password << ", имя: " << name << std::endl;
}

User Chat::login()
{
    std::string login, password;

    std::cout << "логин: ";
    std::cin >> login;
    std::cout << "пароль: ";
    std::cin >> password;

    for (auto& user : _users)
    {
        if (login == user.getUserLogin() && password == user.getUserPassword())
        {
            std::cout << "Привет, " << user.getUserName() << "!" << std::endl;
            _currentUser = std::make_shared <User>(user);
            return user;
        }
    }
    std::cout << "Неправильные имя или пароль!" << std::endl;
}

void Chat::userMenu()
{
    bool status_of_user = true;

    while (status_of_user)
    {
        std::cout << "Меню: 1. Просмотреть сообщения, 2. Отправить сообщения, 0. Выход" << std::endl;
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
    std::cout << "Кому: (Логин пользователя или 'all' для отправки всем пользователям чата)" << std::endl;
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
        std::cout << "Ошибка: не найден логин пользователя!" << std::endl;
        return;
    }

    std::cout << "Текст: ";

    std::cin.ignore(sizeof(text) / sizeof(text[0]), '\n'); //чтобы можно было вывести все слова в сообщении
    std::getline(std::cin, text);
    std::cin.ignore(0);

    Message message = Message(toLogin, _currentUser->getUserLogin(), text);
    _messages.push_back(message);
    std::cout << "Ваше сообщение отправлено" << std::endl;
}
void Chat::getMessage()
{
    for (auto& message : _messages)
    {
        if ((message.getTo() == _currentUser->getUserLogin()) || (message.getTo() == "all"))
        {
            std::cout << "От кого: " << message.getFrom() << "; Кому: " << message.getTo() << std::endl;
            std::cout << message.getText() << std::endl;
            std::cout << std::endl;
        }
    }
}