#include "ISensorBase.h"

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

class TemperatureSensor : public ISensorBase
{
public:
	TemperatureSensor();
	TemperatureSensor(std::string name);
	TemperatureSensor(std::string name, connectionType type);
	~TemperatureSensor();
};

#endif