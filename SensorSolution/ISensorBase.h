#include <string>
#include <iostream>

#ifndef ISENSORBASE_H
#define ISENSORBASE_H

// Sensor base class
class ISensorBase
{
public:
	// Connection type selector enum
	enum connectionType { Idle, I2C, RS232, TCP, UDP };

	// Constructor and deconstructor
	ISensorBase();
	ISensorBase(std::string name);
	ISensorBase(std::string name, connectionType type);
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
	connectionType _type = Idle;
	bool _connected = false;
};

#endif

