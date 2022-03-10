
#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVETORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

int main()
{
	while (true)
	{
		system("cls");
		cout << "********************** Game Lobby ***********************" << endl;
		cout << "1. Map" << endl;
		cout << "2. Store" << endl;
		cout << "3. Invetory" << endl;
		cout << "4. Exit" << endl;
		cout << "Choose a menu : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break; 

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");

				cout << "********************** Map ***********************" << endl;
				cout << "1. Easy" << endl;
				cout << "2. Normal" << endl;
				cout << "3. Hard" << endl;
				cout << "4. Back" << endl;
				cout << "Choose Map : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MT_BACK)
					break;
			}
			break;
		case MM_STORE:
			break;
		case MM_INVETORY:
			break;
		default:
			cout << "Wrong number. check please" << endl;
			break;
		}
	}

	return 0;
}