//Author: Devon Hurt
//CPSC 121 Lab 8
//04/10/17

//Libraries used
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Struct to store user and NPC data about their individual characters
struct Gladiator
{
	string name;
	double healthMax;
	double healthCurrent;
	double evasion;
	double crit;
	int minDamage;
	int rangeDamage;

}userGlad, fighterGlad;

//Functions used and defined outside of main
void createGladiator(string);
void showStats(Gladiator);
void createGladiatorNPC(string);
void showStatsNPC(Gladiator);
void takeTurn(Gladiator, Gladiator);

int main()
{
	//Variables used in main to store names and maintain loops
	string fighter = "Bob";
	string nameGlad;
	srand(time(NULL));
	char happyGlad;
	char happyfighter;
	char rematch;
	char replay;
	
	//Loop to run the entire program again
	do
	{
		//Prompt the user for their character name
		cout << "Player name: " << endl;
		cin >> nameGlad;

		//Loop to recreate user character if not satisfied
		do
		{
			createGladiator(nameGlad);
			showStats(userGlad);
			cin >> happyGlad;
		} while (happyGlad == 'n');

		//Loop to recreate NPC if not satisfied
		do
		{
			createGladiatorNPC(fighter);
			showStatsNPC(fighterGlad);
			cin >> happyfighter;
		} while (happyfighter == 'n');

		//Loop to fight again using the same characters
		do
		{
			cout << "------------------------------------" << endl;
			cout << "Ready?" << endl;
			cout << "FIGHT!!!" << endl;
			takeTurn(userGlad, fighterGlad);
			cin >> rematch;
		} while (rematch == 'y');

		cout << "Would you like to set up another fight? (Yes = y, No = n)" << endl;
		cin >> replay;
	} while (replay == 'y');


	system("pause");
	return 0;
}

//Function to create user gladiator
void createGladiator(string nameGlad)
{
	//Variables used to create user gladiator
	int health = 0;
	int evasion = 0;
	int crit = 0;
	userGlad.name = nameGlad;

	//Generate a random value to assign health to the gladiator
	health = rand() % 3 + 1;

	if (health == 1)
	{
		userGlad.healthMax = 150;
	}
	if (health == 2)
	{
		userGlad.healthMax = 200;
	}
	if (health == 3)
	{
		userGlad.healthMax = 250;
	}
	userGlad.healthCurrent = userGlad.healthMax;

	//Generate a random value to assign evasion to the gladiator
	evasion = rand() % 5 + 1;

	if (evasion == 1)
	{
		userGlad.evasion = 5;
	}
	if (evasion == 2)
	{
		userGlad.evasion = 7.5;
	}
	if (evasion == 3)
	{
		userGlad.evasion = 10;
	}
	if (evasion == 4)
	{
		userGlad.evasion = 12.5;
	}
	if (evasion == 5)
	{
		userGlad.evasion = 15;
	}

	//Generate a random value to assign critical strike chance to the gladiator
	crit = rand() % 5 + 1;

	if (crit == 1)
	{
		userGlad.crit = 5;
	}
	if (crit == 2)
	{
		userGlad.crit = 7.5;
	}
	if (crit == 3)
	{
		userGlad.crit = 1;
	}
	if (crit == 4)
	{
		userGlad.crit = 12.5;
	}
	if (crit == 5)
	{
		userGlad.crit = 15;
	}

	//Generate random values to assign minimum and maximum damage to the gladiator
	userGlad.minDamage = rand() % 7 + 8;
	userGlad.rangeDamage = rand() % 7 + 16;
}

//Function to create NPC gladiator
void createGladiatorNPC(string fighter)
{
	//Variables used to create user gladiator
	int health = 0;
	int evasion = 0;
	int crit = 0;
	fighterGlad.name = fighter;

	//Generate a random value to assign health to the gladiator
	health = rand() % 3 + 1;

	if (health == 1)
	{
		fighterGlad.healthMax = 150;
	}
	if (health == 2)
	{
		fighterGlad.healthMax = 200;
	}
	if (health == 3)
	{
		fighterGlad.healthMax = 250;
	}
	fighterGlad.healthCurrent = fighterGlad.healthMax;

	//Generate a random value to assign evasion to the gladiator
	evasion = rand() % 5 + 1;

	if (evasion == 1)
	{
		fighterGlad.evasion = 5;
	}
	if (evasion == 2)
	{
		fighterGlad.evasion = 7.5;
	}
	if (evasion == 3)
	{
		fighterGlad.evasion = 10;
	}
	if (evasion == 4)
	{
		fighterGlad.evasion = 12.5;
	}
	if (evasion == 5)
	{
		fighterGlad.evasion = 15;
	}

	//Generate a random value to assign critical strike chance to the gladiator
	crit = rand() % 5 + 1;

	if (crit == 1)
	{
		fighterGlad.crit = 5;
	}
	if (crit == 2)
	{
		fighterGlad.crit = 7.5;
	}
	if (crit == 3)
	{
		fighterGlad.crit = 10;
	}
	if (crit == 4)
	{
		fighterGlad.crit = 12.5;
	}
	if (crit == 5)
	{
		fighterGlad.crit = 15;
	}

	//Generate random values to assign minimum and maximum damage to the gladiator
	fighterGlad.minDamage = rand() % 7 + 8;
	fighterGlad.rangeDamage = rand() % 7 + 16;
}

//Function to display stats for user gladiator
void showStats(Gladiator userGlad)
{
	cout << "---------------------" << endl;
	cout << "Your character: " <<  userGlad.name << endl;
	cout << "Health: " << userGlad.healthMax << endl;
	cout << "Evasion: " << userGlad.evasion << endl;
	cout << "Critical Chance: " << userGlad.crit << endl;
	cout << "Minimum Damage: " << userGlad.minDamage << endl;
	cout << "Maximum Damage: " << userGlad.rangeDamage << endl;
	cout << "Would you like to continue with this character? (Yes = y, No = n)" << endl;
}

//Function to display stats for NPC gladiator
void showStatsNPC(Gladiator fighterGlad)
{
	cout << "---------------------" << endl;
	cout << "Your opponent: " << fighterGlad.name << endl;
	cout << "Health: " << fighterGlad.healthMax << endl;
	cout << "Evasion: " << fighterGlad.evasion << endl;
	cout << "Critical Chance: " << fighterGlad.crit << endl;
	cout << "Minimum Damage: " << fighterGlad.minDamage << endl;
	cout << "Maximum Damage: " << fighterGlad.rangeDamage << endl;
	cout << "Do you think can beat him? (Yes = y, No = n)" << endl;
}

//Function to simulate the fight scenario on a turn-based system
void takeTurn(Gladiator userGlad, Gladiator fighterGlad)
{
	//Variables used to determine if either the user or NPC evade, do double damage, or how much damage is done during that turn
	int usercrit;
	int fightercrit;
	int userdamage;
	int fighterdamage;
	int userevasion;
	int fighterevasion;

		//Loop to keep the simulation continuing until a character's health reaches 0
		do
		{
			//Variables are assigned a random value based on user stats
			userdamage = rand() % (userGlad.rangeDamage - userGlad.minDamage + 1) + userGlad.minDamage;
			usercrit = rand() % 100 + 1;
			userevasion = rand() % 100 + 1;

			//Variables are assigned a random value based on NPC stats
			fighterdamage = rand() % (fighterGlad.rangeDamage - fighterGlad.minDamage + 1) + fighterGlad.minDamage;
			fightercrit = rand() % 100 + 1;
			fighterevasion = rand() % 100 + 1;

			//If the value generated is larger than the statistic assigned to the gladiator, the NPC does not evade the attack
			if (fighterevasion > fighterGlad.evasion)
			{
				//If the value generated is smaller than the statistic assigned to the gladiator, the user deals double damage
				if (usercrit < userGlad.crit)
				{
					fighterGlad.healthCurrent = fighterGlad.healthCurrent - userdamage * 2;
					cout << userGlad.name << " landed a critical strike!" << endl;
					cout << userGlad.name << "'s damage: " << userdamage * 2 << endl;
				}
				else
				{
					fighterGlad.healthCurrent = fighterGlad.healthCurrent - userdamage;
					cout << userGlad.name << "'s damage: " << userdamage << endl;
				}
			}

			//If the value generated is smaller than the statistic assigned to the gladiator, the NPC evades the attack
			else if (fighterevasion < fighterGlad.evasion)
			{
				cout << "Your opponent dodged your attack!" << endl;
			}

			//Display of current health
			cout << "Player Health: " << userGlad.healthCurrent << endl;
			cout << "Opponent Health: " << fighterGlad.healthCurrent << endl;
			cout << "------------------------------------" << endl;

			//Condition stops the NPC from taking a turn if their health reaches 0 or below
			if (fighterGlad.healthCurrent > 0)
			{
				//If the value generated is larger than the statistic assigned to the gladiator, the user does not evade the attack
				if (userevasion > userGlad.evasion)
				{
					//If the value generated is smaller than the statistic assigned to the gladiator, the NPC deals double damage
					if (fightercrit < fighterGlad.crit)
					{
						userGlad.healthCurrent = userGlad.healthCurrent - fighterdamage * 2;
						cout << fighterGlad.name << " landed a critical strike!" << endl;
						cout << fighterGlad.name << "'s damage: " << fighterdamage * 2 << endl;
					}
					else
					{
						userGlad.healthCurrent = userGlad.healthCurrent - fighterdamage;
						cout << fighterGlad.name << "'s damage: " << fighterdamage << endl;
					}
				}

				//If the value generated is smaller than the statistic assigned to the gladiator, the user evades the attack
				else if (userevasion < userGlad.evasion)
				{
					cout << "You dodged your opponent's attack!" << endl;
				}

				//Display of current health
				cout << "Player Health: " << userGlad.healthCurrent << endl;
				cout << "Opponent Health: " << fighterGlad.healthCurrent << endl;
				cout << "------------------------------------" << endl;
			}

			//When a character reaches 0 health, the winner is anounced
			if (userGlad.healthCurrent <= 0)
			{
				cout << fighterGlad.name << " wins!" << endl;
			}
			else if (fighterGlad.healthCurrent <= 0)
			{
				cout << userGlad.name << " wins!" << endl;
			}

		}while (userGlad.healthCurrent > 0 && fighterGlad.healthCurrent > 0);

		cout << "Would you like a rematch? (Yes = y, No = n)" << endl;
}