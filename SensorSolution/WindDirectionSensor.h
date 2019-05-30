#include "ISensorBase.h"

#ifndef WINDDIRECTIONSENSOR_H
#define WINDDIRECTIONSENSOR_H

class WindDirectionSensor : public ISensorBase
{
public:
	WindDirectionSensor();
	WindDirectionSensor(std::string name);
	WindDirectionSensor(std::string name, connectionType type);
	~WindDirectionSensor();
};

#endif