#include "pch.h"
#include "TemperatureSensor.h"


TemperatureSensor::TemperatureSensor() : ISensorBase(Temperature, "Temperature", I2C) {}

TemperatureSensor::TemperatureSensor(std::string name) : ISensorBase(Temperature, name, I2C) {}

TemperatureSensor::TemperatureSensor(std::string name, connectionType type) : ISensorBase(Temperature, name, type) {}

TemperatureSensor::~TemperatureSensor() {}
