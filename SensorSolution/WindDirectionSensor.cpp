#include "pch.h"
#include "WindDirectionSensor.h"

WindDirectionSensor::WindDirectionSensor() : ISensorBase(WindDirection, "WindDirection", UDP) {}

WindDirectionSensor::WindDirectionSensor(std::string name) : ISensorBase(WindDirection, name, UDP) {}

WindDirectionSensor::WindDirectionSensor(std::string name, connectionType type) : ISensorBase(WindDirection, name, type) {}

WindDirectionSensor::~WindDirectionSensor() {}