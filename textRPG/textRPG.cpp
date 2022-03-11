
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

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

#define NAME_SIZE	32

struct _tagInventory
{
	int	iGold;
};

struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
	_tagInventory	tInventory;
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

int main()
{
	srand((unsigned int)time(0));

	// Make player
	_tagPlayer	tPlayer = {};

	cout << "Name : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. Knight" << endl;
		cout << "2. Archer" << endl;
		cout << "3. Wizard" << endl;
		cout << "Choose a job : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob < JOB_END)
			iJob = JOB_NONE;
	}
	
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "Knight");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "Archer");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "Wizard");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}
	
	// Make monster
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// Make Goblin.
	strcpy_s(tMonsterArr[0].strName, "Goblin");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iHPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[1].iGoldMax = 1500;

	// Make Troll.
	strcpy_s(tMonsterArr[1].strName, "Troll");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iHPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// Make Dragon.
	strcpy_s(tMonsterArr[2].strName, "Dragon");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iHPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	while (true)
	{
		system("cls");
		cout << "********************** Lobby ***********************" << endl;
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
				
				// Menu number - 1 = monster index.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					switch (iMenu)
					{
					case MT_EASY:
						cout << "********************** Easy ***********************" << endl;
						break;
					case MT_NORMAL:
						cout << "********************** Normal ***********************" << endl;
						break;
					case MT_HARD:
						cout << "********************** Hard ***********************" << endl;
						break;
					}

					// Output player info.
					cout << "======================== Player ========================" << endl;
					cout << "Name : " << tPlayer.strJobName << "\tJob : " <<
						tPlayer.strJobName << endl;
					cout << "Level : " << tPlayer.iLevel << "\tExp : " <<
						tPlayer.iExp << endl;
					cout << "Attack : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\tArmor : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "Gold : " << tPlayer.tInventory.iGold << " Gold" << endl;

					// Monster info.
					cout << "======================== Monster ========================" << endl;
					cout << "Level : " << tMonster.iLevel << "\tExp : " <<
						tMonster.iExp << endl;
					cout << "Attack : " << tPlayer.iAttackMin << " - " <<
						tMonster.iAttackMax << "\tArmor : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "HP : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\tMP : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "Gold : " << tMonster.tInventory.iGold << " Gold" << endl;

				}
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