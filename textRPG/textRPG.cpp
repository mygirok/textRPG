
#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
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

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
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
	int		iMin;
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
	_tagItem	tEquip[EQ_MAX];
	bool		bEquip[EQ_MAX];
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

	// Weapon info
	strcpy_s(tStoreWeapon[0].strName, "Wooden sword");
	strcpy_s(tStoreWeapon[0].strTypeName, "Weapon");
	strcpy_s(tStoreWeapon[0].strDesc, "Basic sword.");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "Longbow");
	strcpy_s(tStoreWeapon[1].strTypeName, "Weapon");
	strcpy_s(tStoreWeapon[1].strDesc, "Long range attack possible");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "Magic wand");
	strcpy_s(tStoreWeapon[2].strTypeName, "Weapon");
	strcpy_s(tStoreWeapon[2].strDesc, "Wooden wand");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	// ================ Armor info =================
	strcpy_s(tStoreArmor[0].strName, "Cloth armor");
	strcpy_s(tStoreArmor[0].strTypeName, "Armor");
	strcpy_s(tStoreArmor[0].strDesc, "Armor made of cloth.");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "Leather armor");
	strcpy_s(tStoreArmor[1].strTypeName, "Armor");
	strcpy_s(tStoreArmor[1].strDesc, "Armor made of animal leather.");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "Steel armor");
	strcpy_s(tStoreArmor[2].strTypeName, "Armor");
	strcpy_s(tStoreArmor[2].strDesc, "Armor made of steel");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;


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

					/*
					cout << "Attack : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\tArmor : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					*/
 
					// Add item attack to player. 
					if (tPlayer.bEquip[EQ_WEAPON] == true)
					{
						cout << "Attack : " << tPlayer.iAttackMin << " + " <<
							tPlayer.tEquip[EQ_WEAPON].iMin << " - " <<
							tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
					}
					else
					{

						cout << "Attack : " << tPlayer.iAttackMin << " - " <<
							tPlayer.iAttackMax;
					}

					// Add item armor to player. 
					if (tPlayer.bEquip[EQ_ARMOR] == true)
					{
						cout << "\tArmor : " << tPlayer.iArmorMin << " + " <<
							tPlayer.tEquip[EQ_ARMOR].iMin << " - " <<
							tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}
					else
					{

						cout << "\tArmor : " << tPlayer.iArmorMin << " - " <<
							tPlayer.iArmorMax << endl;
					}

					cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					if (tPlayer.bEquip[EQ_WEAPON])
						cout << "Equip Weapon : " << tPlayer.tEquip[EQ_WEAPON].strName;

					else
						cout << "Equip Weapon : None";

					if (tPlayer.bEquip[EQ_ARMOR])
						cout << "\tEquip Armor : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

					else
						cout << "\tEquip Armor : None" << endl;

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
						int iAttackMin = tPlayer.iAttackMin;
						int iAttackMax = tPlayer.iAttackMax;

						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}

						int iAttack = rand() % (iAttackMax - iAttackMin + 1) +
							iAttackMin;
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
						iAttack = rand() % (iAttackMax - iAttackMin + 1) +
							tMonster.iAttackMin;

						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}

						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) +
							iArmorMin;

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
						for (int i = 0; i < STORE_WEAPON_MAX; ++i)
						{
							cout << i + 1 << ". Name : " << tStoreWeapon[i].strName <<
								"\tType : " << tStoreWeapon[i].strTypeName << endl;
							cout << "Attack : " << tStoreWeapon[i].iMin << "-" <<
								tStoreWeapon[i].iMax << endl;
							cout << "Buy : " << tStoreWeapon[i].iPrice <<
								"\tSell : " << tStoreWeapon[i].iSell << endl;
							cout << "Desc : " << tStoreWeapon[i].strDesc << endl << endl;
						}

						cout << STORE_WEAPON_MAX + 1 << ". Back" << endl;
						cout << "Holding Gold : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "Remaining space : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "Choose a item : ";
						cin >> iMenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "Wrong item." << endl;
							system("pause");
							continue;
						}

						// list index
						int iWeaponIdex = iMenu - 1;

						// Check the inventory space
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "Inventory is full" << endl;
							system("pause");
							continue;
						}

						// Check Gold
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIdex].iPrice)
						{
							cout << "Don't have enough Gold." << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreWeapon[iWeaponIdex];
						++tPlayer.tInventory.iItemCount;

						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIdex].iPrice;

						cout << "Bought	" << tStoreWeapon[iWeaponIdex].strName << endl;
						system("pause");

					}
					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "********************** Armor Store ***********************" << endl;

						// Weapon list
						for (int i = 0; i < STORE_ARMOR_MAX; ++i)
						{
							cout << i + 1 << ". Name : " << tStoreArmor[i].strName <<
								"\tType : " << tStoreArmor[i].strTypeName << endl;
							cout << "Attack : " << tStoreArmor[i].iMin << "-" <<
								tStoreArmor[i].iMax << endl;
							cout << "Buy : " << tStoreArmor[i].iPrice <<
								"\tSell : " << tStoreArmor[i].iSell << endl;
							cout << "Desc : " << tStoreArmor[i].strDesc << endl << endl;
						}

						cout << STORE_ARMOR_MAX + 1 << ". Back" << endl;
						cout << "Holding Gold : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "Remaining space : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "Choose a item : ";
						cin >> iMenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
						{
							cout << "Wrong item." << endl;
							system("pause");
							continue;
						}

						// list index
						int iArmorIdex = iMenu - 1;

						// Check the inventory space
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "Inventory is full" << endl;
							system("pause");
							continue;
						}

						// Check Gold
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIdex].iPrice)
						{
							cout << "Don't have enough Gold." << endl;
							system("pause");
							continue;
						}

						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] =
							tStoreArmor[iArmorIdex];
						++tPlayer.tInventory.iItemCount;

						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIdex].iPrice;

						cout << "Bought	" << tStoreArmor[iArmorIdex].strName << endl;
						system("pause");

					}
					break;

				}
			}
			break;
		case MM_INVENTORY:
			while (true)
			{

				system("cls");
				cout << "********************** Inventory ***********************" << endl;
				cout << "Name : " << tPlayer.strName << "\tJob : " <<
					tPlayer.strJobName << endl;
				cout << "Level : " << tPlayer.iLevel << "\tExp : " <<
					tPlayer.iExp << endl;

				// Add item attack to player.
				if (tPlayer.bEquip[EQ_WEAPON] == true)
				{
					cout << "Attack : " << tPlayer.iAttackMin << " + " <<
						tPlayer.tEquip[EQ_WEAPON].iMin << " - " <<
						tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
				}
				else
				{

					cout << "Attack : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax;
				}

				// Add item armor to player. 
				if (tPlayer.bEquip[EQ_ARMOR] == true)
				{
					cout << "\tArmor : " << tPlayer.iArmorMin << " + " <<
						tPlayer.tEquip[EQ_ARMOR].iMin << " - " <<
						tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else
				{

					cout << "\tArmor : " << tPlayer.iArmorMin << " - " <<
						tPlayer.iArmorMax << endl;
				}

				cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
					"\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON])
					cout << "Equip Weapon : " << tPlayer.tEquip[EQ_WEAPON].strName;

				else
					cout << "Equip Weapon : None";

				if (tPlayer.bEquip[EQ_ARMOR])
					cout << "\tEquip Armor : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;

				else
					cout << "\tEquip Armor : None" << endl;

				cout << "Gold : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i)
				{
					cout << i + 1 << ". Name : " << tPlayer.tInventory.tItem[i].strName <<
						"\tType : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "Attack : " << tPlayer.tInventory.tItem[i].iMin << "-" <<
						tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "Buy : " << tPlayer.tInventory.tItem[i].iPrice <<
						"\tSell : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "Desc : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;

				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". Back" << endl;
				cout << "Choose item to equip : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == tPlayer.tInventory.iItemCount + 1)
					break;

				else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemCount + 1)
				{
					cout << "Worng number. check please." << endl;
					system("pause");
					continue;
				}

				// Item index
				int idx = iMenu - 1;

				// Equip item
				EQUIP	eq;

				switch (tPlayer.tInventory.tItem[idx].eType)
				{
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;
				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				// If item is already equipped, swap with selected item.
				if (tPlayer.bEquip[eq] == true)
				{
					_tagItem	tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				// if item is not equipped.
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					for (int i = idx; tPlayer.tInventory.iItemCount - 1; ++i)
					{
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}

					--tPlayer.tInventory.iItemCount;

					tPlayer.bEquip[eq] = true;
				}

				cout << "Equipped with " << tPlayer.tEquip[eq].strName << endl;
				system("pause");
			}
			break;
		default:
			cout << "Wrong number. check please" << endl;
			break;
		}
	}

	return 0;
}