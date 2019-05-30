#include "pch.h"
#include "SuperSensorProduct.h"

// Constructors and deconstructor

SuperSensorProduct::~SuperSensorProduct() {}

SuperSensorProduct::SuperSensorProduct() : SuperSensorProduct("NA") {}

SuperSensorProduct::SuperSensorProduct(std::string name)
{
	_name = name;
}

// Methods

void SuperSensorProduct::addSensor(ISensorBase sensor)
{
	// Add to sensor list
	_sensorList.push_back(sensor);
}

void SuperSensorProduct::printProperties()
{
	std::cout << "SuperSensor name: " << _name << ", SensorCount: " << _sensorList.size() << "." << std::endl;

	for (int index = 0; index < _sensorList.size(); index++)
	{
		std::cout << "     ";
		_sensorList[index].printProperties();
	}
}