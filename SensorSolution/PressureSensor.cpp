#include "pch.h"
#include "PressureSensor.h"

PressureSensor::PressureSensor() : ISensorBase(Pressure, "Pressure", TCP) {}

PressureSensor::PressureSensor(std::string name) : ISensorBase(Pressure, name, TCP) {}

PressureSensor::PressureSensor(std::string name, connectionType type) : ISensorBase(Pressure, name, type) {}

PressureSensor::~PressureSensor() {}