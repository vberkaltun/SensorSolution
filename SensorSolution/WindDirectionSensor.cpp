#include "pch.h"
#include "WindDirectionSensor.h"

WindDirectionSensor::WindDirectionSensor() : ISensorBase("WindDirection", UDP) {}

WindDirectionSensor::WindDirectionSensor(std::string name) : ISensorBase(name, UDP) {}

WindDirectionSensor::WindDirectionSensor(std::string name, connectionType type) : ISensorBase(name, type) {}

WindDirectionSensor::~WindDirectionSensor() {}