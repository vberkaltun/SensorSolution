#include "ISensorBase.h"

#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

class PressureSensor : public ISensorBase
{
public:
	PressureSensor();
	PressureSensor(std::string name);
	PressureSensor(std::string name, connectionType type);
	~PressureSensor();
};

#endif