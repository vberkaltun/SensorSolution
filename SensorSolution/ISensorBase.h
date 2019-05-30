#include <string>
#include <iostream>

#ifndef ISENSORBASE_H
#define ISENSORBASE_H

// Sensor base class
class ISensorBase
{
public:
	// Connection type selector enum
	enum connectionType { C_Idle, I2C, RS232, TCP, UDP };
	enum sensorType { S_Idle, Temperature, Humidity, Pressure, WindDirection, WindSpeed };

	// Constructor and deconstructor
	ISensorBase();
	ISensorBase(sensorType sensor, std::string name);
	ISensorBase(sensorType sensor, std::string name, connectionType connection);
	virtual ~ISensorBase();

	// Default mandatory methods
	virtual int getValue();
	virtual void setValue(int value);
	virtual void Connect();

	void printProperties();
	bool isConnected();

private:
	int _value = 0;
	std::string _name = "";
	sensorType _sensor = S_Idle;
	connectionType _connection = C_Idle;
	bool _connected = false;

	std::string getConnectionType();
	std::string getSensorType();

};

#endif

