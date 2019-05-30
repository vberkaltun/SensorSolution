#include "pch.h"
#include "HumiditySensor.h"

HumiditySensor::HumiditySensor() : ISensorBase("Humidity", RS232) {}

HumiditySensor::HumiditySensor(std::string name) : ISensorBase(name, RS232) {}

HumiditySensor::HumiditySensor(std::string name, connectionType type) : ISensorBase(name, type) {}

HumiditySensor::~HumiditySensor() {}
