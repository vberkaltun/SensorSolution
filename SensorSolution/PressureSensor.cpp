#include "pch.h"
#include "PressureSensor.h"

PressureSensor::PressureSensor() : ISensorBase("Pressure", TCP) {}

PressureSensor::PressureSensor(std::string name) : ISensorBase(name, TCP) {}

PressureSensor::PressureSensor(std::string name, connectionType type) : ISensorBase(name, type) {}

PressureSensor::~PressureSensor() {}