#include "pch.h"
#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor() : ISensorBase("Temperature", I2C) {}

TemperatureSensor::TemperatureSensor(std::string name) : ISensorBase(name, I2C) {}

TemperatureSensor::TemperatureSensor(std::string name, connectionType type) : ISensorBase(name, type) {}

TemperatureSensor::~TemperatureSensor() {}
