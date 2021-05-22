#include "Object.h"
#include <string>
#include <vector>
#include <iostream>

std::string InputString;
std::string InputName;
int InputWeight = 0;
int InputHealth = 0;
bool bInputDamage = false;
bool bIsRunning = true;
std::vector<Object*> Objects;

bool isStringValid(std::string StringToCheck);
bool isIntValid(int IntToCheck);

int main()
{
	std::cout << "Welcome to the Generic RPG Object Creator!\n";

	while (bIsRunning)
	{
		bool isLoop = true;

#pragma region Name
		while (isLoop)
		{
			system("cls");
			std::cout << "Please Enter Object Name: ";
			std::cin >> InputName;

			isLoop = false;
		}
#pragma endregion Name

		system("cls");

		isLoop = true;

#pragma region Health
		while (isLoop)
		{
			std::cout << "Please Enter Object Health: ";
			std::cin >> InputHealth;

			if (isIntValid(InputHealth))
			{
				isLoop = false;
			}
			else
			{
				std::cout << "\nError: Invalid Format";
			}
		}
#pragma endregion Health

		system("cls");

		isLoop = true;

#pragma region Weight
		while (isLoop)
		{
			std::cout << "Please Enter Object Weight: ";
			std::cin >> InputWeight;

			if (isIntValid(InputWeight))
			{
				isLoop = false;
			}
			else
			{
				std::cout << "\nError: Invalid Format";
			}
		}
#pragma endregion Weight

		system("cls");

		isLoop = true;

#pragma region Damage
		while (isLoop)
		{
			std::cout << "Please Identify if this object can be Damaged (Y/N): ";
			std::cin >> InputString;

			if (isStringValid(InputString))
			{
				if (InputString == "Y"
					|| InputString == "y")
				{
					bInputDamage = true;
				}
				else if (InputString == "N"
					|| InputString == "n")
				{
					bInputDamage = false;
				}
				isLoop = false;
			}
			else
			{
				std::cout << "\nError: Invalid Format";
			}
		}
#pragma endregion Damage

		Object* newObject = new Object(InputName, InputHealth, InputWeight, bInputDamage);

		Objects.push_back(newObject);

		system("cls");

		std::cout << "Would you like to create another Object? (Y/N): ";
		std::cin >> InputString;

		if (InputString == "N"
			|| InputString == "n")
		{
			bIsRunning = false;
		}

	}

	system("cls");

	std::cout << "\t\t\t\t\t\t[Generated Objects]\n";
	
	for (int i = 0; i < Objects.size(); i++)
	{
		std::cout << "\nObject #" << i + 1 << "\tName:" << Objects[i]->GetName() << "\tHealth: " << Objects[i]->GetHealth() << "\tWeight: " << Objects[i]->GetWeight();
		bool bCBD = Objects[i]->GetCanBeDamaged();
		std::cout << "\tCan Be Damaged: " << bCBD;
	}

	system("pause");

	return 0;
}

bool isStringValid(std::string StringToCheck)
{
	if (StringToCheck == "Y"
		|| StringToCheck == "y"
		|| StringToCheck == "N"
		|| StringToCheck == "n")
	{
		return true;
	}
	return false;
}

bool isIntValid(int IntToCheck)
{
	if (IntToCheck > 0)
	{
		return true;
	}
	return false;
}
