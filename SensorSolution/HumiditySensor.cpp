#include "pch.h"
#include "HumiditySensor.h"

HumiditySensor::HumiditySensor() : ISensorBase(Humidity, "Humidity", RS232) {}

HumiditySensor::HumiditySensor(std::string name) : ISensorBase(Humidity, name, RS232) {}

HumiditySensor::HumiditySensor(std::string name, connectionType type) : ISensorBase(Humidity, name, type) {}

HumiditySensor::~HumiditySensor() {}
