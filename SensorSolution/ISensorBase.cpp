#include "pch.h"
#include "ISensorBase.h"

// Constructors and deconstructor

ISensorBase::ISensorBase() : ISensorBase(S_Idle, "NA", C_Idle) {}

ISensorBase::ISensorBase(sensorType sensor, std::string name) : ISensorBase(S_Idle, name, C_Idle) {}

ISensorBase::ISensorBase(sensorType sensor, std::string name, connectionType connection)
{
	_sensor = sensor;
	_name = name;
	_connection = connection;
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
	std::cout << "  Connection was established successfully!" << std::endl << std::endl;
}

void ISensorBase::printProperties()
{
	std::cout << "SensorName: " << _name << ", SensorType: " << getSensorType() << ", ConnType: " << getConnectionType() << ", Conn: " << _connected << "." << std::endl;
}

// -----

std::string  ISensorBase::getConnectionType()
{
	switch (_connection)
	{
	default:
	case ISensorBase::C_Idle:
		return "NA";
	case ISensorBase::I2C:
		return "I2C";
	case ISensorBase::RS232:
		return "RS232";
	case ISensorBase::TCP:
		return "TCP";
	case ISensorBase::UDP:
		return "UDP";
	}
}

std::string  ISensorBase::getSensorType()
{
	switch (_sensor)
	{
	default:
	case ISensorBase::S_Idle:
		return "NA";
	case ISensorBase::Temperature:
		return "Temperature";
	case ISensorBase::Humidity:
		return "Humidity";
	case ISensorBase::Pressure:
		return "Pressure";
	case ISensorBase::WindDirection:
		return "WindDirection";
	case ISensorBase::WindSpeed:
		return "WindSpeed";
	}
}
