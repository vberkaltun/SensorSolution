#include "pch.h"
#include "ISensorBase.h"
#include "SuperSensorProduct.h"

#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "PressureSensor.h"
#include "WindSpeedSensor.h"
#include "WindDirectionSensor.h"

#include <iostream>
#include <vector> 

// Our main product list
std::vector<SuperSensorProduct> superSensorList;

void selectMenuItem(char selector);
ISensorBase::connectionType selectConnectionType();

ISensorBase generateSensor(char selector);
void generateSuperSensor();
std::string generateSuperSensorName();

void listMenuItem();
void listSensorItem();
void listConnectionType();

bool checkConnectionTypeValue(char selector);
bool checkSensorValue(char selector);
std::string getUserInput();

// -----

int main()
{
	// List menu items
	selectMenuItem('4');

	while (true)
	{
		std::cout << std::endl;
		std::cout << "> Please make a selection [0 to 4]: ";
		std::string input = getUserInput();

		// Redirect to operation or close, restart
		if (input.length() > 1)
			continue;
		else
			selectMenuItem(input[0]);
	}
}

void selectMenuItem(char selector)
{
	switch (selector)
	{
	case '0':
		exit(1);

	case '2':
		// Add new super sensor
		generateSuperSensor();
		selectMenuItem('4');
		break;

	case '3':
		// List super sensor data
		if (superSensorList.size() == 0)
			std::cout << "  SuperSensor list is empty!" << std::endl;
		else for (int index = 0; index < superSensorList.size(); index++)
			superSensorList[index].printProperties();
		break;

	case '4':
		// List main menu
		listMenuItem();
		break;

	case '1':
	default:
		break;
	}

}

ISensorBase::connectionType selectConnectionType()
{
	// Store all input data at the here temporarily
	std::string input;

	// Show available connection types
	listConnectionType();

	while (input.length() == 0)
	{
		// Reset last token
		input = "";

		std::cout << "> Please choose a connection type [0 to 4]: ";
		input = getUserInput();

		if (!checkConnectionTypeValue(input[0]))
			continue;
		else
			break;
	}

	// -----

	// Detect selection and return it to caller method
	switch (input[0])
	{
	case '1':
		return ISensorBase::I2C;
	case '2':
		return ISensorBase::RS232;
	case '3':
		return ISensorBase::TCP;
	case '4':
		return ISensorBase::UDP;

	case '0':
	default:
		return ISensorBase::Idle;
	}
}

// -----

ISensorBase generateSensor(char selector)
{
	// Store all input data at the here temporarily
	std::string name;

	while (name.length() == 0)
	{
		// Reset last token
		name = "";

		std::cout << "> Please enter a Sensor name: ";
		name = getUserInput();
	}

	// -----

	ISensorBase::connectionType type = selectConnectionType();

	if(type == ISensorBase::Idle)
	{
		switch (selector)
		{
		case '1':
			return TemperatureSensor(name);
		case '2':
			return HumiditySensor(name);
		case '3':
			return PressureSensor(name);
		case '4':
			return WindSpeedSensor(name);
		case '5':
			return WindDirectionSensor(name);

		default:
			return ISensorBase();
		}
	}
	else
	{
		switch (selector)
		{
		case '1':
			return TemperatureSensor(name, type);
		case '2':
			return HumiditySensor(name, type);
		case '3':
			return PressureSensor(name, type);
		case '4':
			return WindSpeedSensor(name, type);
		case '5':
			return WindDirectionSensor(name, type);

		default:
			return ISensorBase();
		}
	}
}

void generateSuperSensor()
{
	// Store all input data at the here temporarily
	std::string sensor;
	SuperSensorProduct superSensor(generateSuperSensorName());

	// When we arrive here, that is mean name is correct
	// Now we can go to next step, adding sensor
	listSensorItem();

	while (true)
	{
		// Reset last token
		sensor = "";

		while (sensor.length() == 0 || sensor.length() > 1)
		{
			std::cout << "> Please choose a Sensor [0 to 5]: ";
			sensor = getUserInput();

			if (!checkSensorValue(sensor[0]))
				continue;
		}

		if (sensor[0] == '0')
			break;

		superSensor.addSensor(generateSensor(sensor[0]));
	}

	superSensorList.push_back(superSensor);
}

std::string generateSuperSensorName()
{
	// Store all input data at the here temporarily
	std::string name;

	// Clear last token GUI
	system("CLS");
	std::cout << "Welcome to SuperSensor Wizard!" << std::endl;
	std::cout << std::endl;

	while (name.length() == 0)
	{
		// Reset last token
		name = "";

		std::cout << "> Please enter a SuperSensor name: ";
		name = getUserInput();
	}

	return name;
}

// -----

void listMenuItem()
{
	// Clear last token GUI
	system("CLS");

	std::cout << "Welcome to SuperSensor Application!" << std::endl;
	std::cout << "  0: Quit Program..." << std::endl;
	std::cout << "  1: Add Sensor (Not Available)" << std::endl;
	std::cout << "  2: Add SuperSensor" << std::endl;
	std::cout << "  3: Print SuperSensor Product Details" << std::endl;
	std::cout << "  4: Clear Console" << std::endl;
}

void listSensorItem()
{
	std::cout << std::endl;
	std::cout << "Which sensors do you want to add?" << std::endl;
	std::cout << "  0: Save And Turn Back..." << std::endl;
	std::cout << "  1: Temperature" << std::endl;
	std::cout << "  2: Humidity" << std::endl;
	std::cout << "  3: Pressure" << std::endl;
	std::cout << "  4: Wind Speed" << std::endl;
	std::cout << "  5: Wind Direction" << std::endl;
	std::cout << std::endl;
}

void listConnectionType()
{
	std::cout << std::endl;
	std::cout << "Which connection type do you want to use?" << std::endl;
	std::cout << "  0: Default..." << std::endl;
	std::cout << "  1: I2C" << std::endl;
	std::cout << "  2: RS232" << std::endl;
	std::cout << "  3: TCP" << std::endl;
	std::cout << "  4: UDP" << std::endl;
	std::cout << std::endl;
}

// -----

bool checkConnectionTypeValue(char selector)
{
	switch (selector)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
		return true;

	default:
		return false;
	}
}

bool checkSensorValue(char selector)
{
	switch (selector)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
		return true;

	default:
		return false;
	}
}

std::string getUserInput()
{
	std::string name;
	std::getline(std::cin, name);

	return name;
}