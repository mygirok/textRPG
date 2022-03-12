
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

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK 
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

#define NAME_SIZE	32
#define ITEM_DESC_LENGTH	512
#define INVENTORY_MAX		20
#define STORE_WEAPON_MAX	3
#define STORE_ARMOR_MAX		3

struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int		iMIn;
	int		iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem	tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
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

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
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
	tMonsterArr[0].iMP = 100;
	tMonsterArr[0].iMPMax = 100;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// Make Troll.
	strcpy_s(tMonsterArr[1].strName, "Troll");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
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
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;
	

	// list of items for sale
	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};
	


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
					system("cls");
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
					cout << "Name : " << tPlayer.strName << "\tJob : " <<
						tPlayer.strJobName << endl;
					cout << "Level : " << tPlayer.iLevel << "\tExp : " <<
						tPlayer.iExp << endl;
					cout << "Attack : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\tArmor : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "Gold : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;

					// Monster info.
					cout << "======================== Monster ========================" << endl;
					cout << "Name : " << tMonster.strName << "\tLevel : " << 
						tMonster.iLevel << endl;
					cout << "Attack : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\tArmor : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "HP : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\tMP : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "Exp : " << tMonster.iExp << "\tGold : " <<
						tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << endl;

					cout << "1. Attack" << endl;
					cout << "2. Run away" << endl;
					cout << "Choose a menu : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					 {
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) +
							tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) +
							tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// Monster HP after attacked.
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " deals " << iDamage <<
							" damage to " << tMonster.strName << endl;

						// if Monster dies.
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << " is dead." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax = tMonster.iGoldMin + 1) +
								tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << "You gained " << tMonster.iExp << " EXP" << endl;
							cout << "You gained " << iGold << " Gold" << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}

						// Monster attack player.
						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) +
							tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) +
							tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;


						// Plyaer HP after attacked.
						tPlayer.iHP -= iDamage;
						cout << tMonster.strName << " deals " << iDamage <<
							" damage to " << tPlayer.strName << endl;


						// if player dies.
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " is dead." << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << "You lost " << tMonster.iExp << " EXP" << endl;
							cout << "You lost " << iGold << " Gold" << endl;

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;

						}
						system("pause");
					}
					break;
					}
				}
			}
			break;
		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "********************** Store ***********************" << endl;
				cout << "1. Weapon store" << endl;
				cout << "2. Armor store" << endl;
				cout << "3. Back" << endl;
				cout << "Choose a store : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");
						cout << "********************** Weapon Store ***********************" << endl;

						// Weapon list
					}
					break;
				case SM_ARMOR:
					break;

				}
			}
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