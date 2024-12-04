#include <iostream>
#include "Chat.h"
using namespace std;

int main()
{
	system("chcp 1251");
	Chat chat;

	chat.registration("l123", "123", "Kate");   //эти три строчки, чтобы не создавать каждый раз пользователей для проверки
	chat.registration("l234", "234", "Andy");	//перед сдачей проекта их закомментировать	
	chat.registration("l345", "345", "Kit");
	/**/

	bool chatWork = true;

	while (chatWork)
	{
		cout << "Добро пожаловать в чат! Выберите действие: 1 - регистрация; 2 - вход; 0 - выход" << endl;
		int choice_1;
		cin >> choice_1;
		switch (choice_1)
		{
		case 1:
			chat.registration();
			break;

		case 2:
			chat.login();
			chat.userMenu();
			break;

		case 0:
			chatWork = false;
			break;
		default:
			cout << "Ошибка! Выберите 1 или 2, или 0 для выхода" << endl;
			break;
		}
	}

	return 0;
}