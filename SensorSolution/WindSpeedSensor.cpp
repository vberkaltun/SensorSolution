#include "pch.h"
#include "WindSpeedSensor.h"

WindSpeedSensor::WindSpeedSensor() : ISensorBase(WindSpeed, "WindSpeed", UDP) {}

WindSpeedSensor::WindSpeedSensor(std::string name) : ISensorBase(WindSpeed, name, UDP) {}

WindSpeedSensor::WindSpeedSensor(std::string name, connectionType type) : ISensorBase(WindSpeed, name, type) {}

WindSpeedSensor::~WindSpeedSensor() {}
