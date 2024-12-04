#include <iostream>
#include "Chat.h"

void Chat::registration()
{
    std::string login, password, name;
    std::cout << "������� �����: ";
    std::cin >> login;
    std::cout << "������� ������: ";
    std::cin >> password;
    std::cout << "������� ���: ";
    std::cin >> name;

    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "����������� ���������!" << std::endl;
}

void Chat::registration(std::string login, std::string password, std::string name)
{
    User user = User(login, password, name);
    _users.push_back(user);

    std::cout << "�����: " << login << ", ������: " << password << ", ���: " << name << std::endl;
}

User Chat::login()
{
    std::string login, password;

    std::cout << "�����: ";
    std::cin >> login;
    std::cout << "������: ";
    std::cin >> password;

    for (auto& user : _users)
    {
        if (login == user.getUserLogin() && password == user.getUserPassword())
        {
            std::cout << "������, " << user.getUserName() << "!" << std::endl;
            _currentUser = std::make_shared <User>(user);
            return user;
        }
    }
    std::cout << "������������ ��� ��� ������!" << std::endl;
}

void Chat::userMenu()
{
    bool status_of_user = true;

    while (status_of_user)
    {
        std::cout << "����: 1. ����������� ���������, 2. ��������� ���������, 0. �����" << std::endl;
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
    std::cout << "����: (����� ������������ ��� 'all' ��� �������� ���� ������������� ����)" << std::endl;
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
        std::cout << "������: �� ������ ����� ������������!" << std::endl;
        return;
    }

    std::cout << "�����: ";

    std::cin.ignore(sizeof(text) / sizeof(text[0]), '\n'); //����� ����� ���� ������� ��� ����� � ���������
    std::getline(std::cin, text);
    std::cin.ignore(0);

    Message message = Message(toLogin, _currentUser->getUserLogin(), text);
    _messages.push_back(message);
    std::cout << "���� ��������� ����������" << std::endl;
}
void Chat::getMessage()
{
    for (auto& message : _messages)
    {
        if ((message.getTo() == _currentUser->getUserLogin()) || (message.getTo() == "all"))
        {
            std::cout << "�� ����: " << message.getFrom() << "; ����: " << message.getTo() << std::endl;
            std::cout << message.getText() << std::endl;
            std::cout << std::endl;
        }
    }
}