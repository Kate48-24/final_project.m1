#include <iostream>
#include "Chat.h"
#include "Exception.h"

using namespace std;

int main()
{
	
	Chat chat;

	/*chat.registration("l123", "123", "Kate");   //to test the program
	chat.registration("l234", "234", "Andy");	//at the end, put it in a comment
	chat.registration("l345", "345", "Kit");
	/**/

	bool chatWork = true;

	while (chatWork)
	{
		cout << "Welcome to the chat! Choose the action: 1 - registration; 2 - login; 0 - exit" << endl;
		int choice_1;
		cin >> choice_1;
		switch (choice_1)
		{
		case 1:
			try {
				chat.registration();
			}
			catch (const LoginException& e)
			{
				cout << e.what() << endl;
			}
			break;

		case 2:
			chat.login();
			chat.userMenu();
			break;

		case 0:
			chatWork = false;
			break;
		default:
			cout << "Error! Choose 1 or 2, or 0 for exit." << endl;
			break;
		}
	}

	return 0;
}