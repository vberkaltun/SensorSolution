#include "ISensorBase.h"

#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

class HumiditySensor : public ISensorBase
{
public:
	HumiditySensor();
	HumiditySensor(std::string name);
	HumiditySensor(std::string name, connectionType type);
	~HumiditySensor();
};

#endif