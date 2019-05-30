#include <string>
#include <iostream>
#include <vector> 
#include <cctype>
#include "ISensorBase.h"

#ifndef SUPERSENSORPRODUCT_H
#define SUPERSENSORPRODUCT_H

class SuperSensorProduct
{
public:
	// Constructor and deconstructor
	SuperSensorProduct();
	SuperSensorProduct(std::string name);
	~SuperSensorProduct();

	void addSensor(ISensorBase sensor);
	void printProperties();

private:
	std::string _name = "";
	std::vector<ISensorBase> _sensorList;
};

#endif
