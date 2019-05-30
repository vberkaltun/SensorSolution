#include "pch.h"
#include "WindSpeedSensor.h"

WindSpeedSensor::WindSpeedSensor() : ISensorBase("WindSpeed", UDP) {}

WindSpeedSensor::WindSpeedSensor(std::string name) : ISensorBase(name, UDP) {}

WindSpeedSensor::WindSpeedSensor(std::string name, connectionType type) : ISensorBase(name, type) {}

WindSpeedSensor::~WindSpeedSensor() {}
