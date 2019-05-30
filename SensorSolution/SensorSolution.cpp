#include "pch.h"
#include "SuperSensorProduct.h"
#include <iostream>

// Our main product
SuperSensorProduct superSensorProduct;

void listMainMenu();
void selectOperation();
void addSensor();
void listSensorConnectionTypeMenu();
void listSensorMenu();
int selectSensor();
int selectSensorConnectionType();

int main()
{
	while (true)
	{
		// First list main menu
		listMainMenu();

		// Redirect to operation or close, restart
		selectOperation();

		// Clear last token GUI
		system("CLS");
	}
}

void listMainMenu()
{
	std::cout << "MAIN MENU" << std::endl;
	std::cout << std::endl;
	std::cout << "0: Quit Program" << std::endl;
	std::cout << "1: Add Sensor (Not Available)" << std::endl;
	std::cout << "2: Add SuperSensor" << std::endl;
	std::cout << "3: Print SuperSensor Product Details" << std::endl;

	std::cout << std::endl;
	std::cout << "Please make a selection [0 to 3]: ";
}

void selectOperation()
{
	// Make a selection, store select
	char selector = -1;
	std::cin >> selector;

	switch (selector)
	{
	case '0':
		exit(1);

	case '2':
		addSensor();
		break;

	case '3':
		superSensorProduct.printProperties();
		break;

	case '1':
	default:
		break;
	}
}

void addSensor()
{
	// Clear last token GUI
	system("CLS");

	std::cout << "Enter a name for SuperSensor: ";
	std::string name;
	std::cin.get();
	std::getline(std::cin, name);

	superSensorProduct.addSensor();
}