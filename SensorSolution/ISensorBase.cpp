#include "pch.h"
#include "ISensorBase.h"

// Constructors and deconstructor

ISensorBase::ISensorBase() : ISensorBase("NA", Idle) {}

ISensorBase::ISensorBase(std::string name) : ISensorBase(name, Idle) {}

ISensorBase::ISensorBase(std::string name, connectionType type)
{
	_name = name;
	_type = type;
}

ISensorBase::~ISensorBase() {}

// Methods

void ISensorBase::setValue(int value)
{
	_value = value;
}

int ISensorBase::getValue() { return _value; }

bool ISensorBase::isConnected() { return _connected; }

void ISensorBase::Connect()
{
	_connected = true;
	std::cout << "Connection was established successfully";
}

void ISensorBase::printProperties()
{
	std::cout << "Sensor name: " << _name << ", ConnType: " << _type << ", Conn: " << _connected << "." << std::endl;
}
