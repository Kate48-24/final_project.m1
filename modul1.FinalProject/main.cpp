#include <iostream>
#include "Chat.h"
using namespace std;

int main()
{
	system("chcp 1251");
	Chat chat;

	chat.registration("l123", "123", "Kate");   //��� ��� �������, ����� �� ��������� ������ ��� ������������� ��� ��������
	chat.registration("l234", "234", "Andy");	//����� ������ ������� �� ����������������	
	chat.registration("l345", "345", "Kit");
	/**/

	bool chatWork = true;

	while (chatWork)
	{
		cout << "����� ���������� � ���! �������� ��������: 1 - �����������; 2 - ����; 0 - �����" << endl;
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
			cout << "������! �������� 1 ��� 2, ��� 0 ��� ������" << endl;
			break;
		}
	}

	return 0;
}