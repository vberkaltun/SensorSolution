#include "ISensorBase.h"

#ifndef WINDSPEEDSENSOR_H
#define WINDSPEEDSENSOR_H

class WindSpeedSensor : public ISensorBase
{
public:
	WindSpeedSensor();
	WindSpeedSensor(std::string name);
	WindSpeedSensor(std::string name, connectionType type);
	~WindSpeedSensor();
};

#endif