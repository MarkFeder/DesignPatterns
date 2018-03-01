#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

/** Record is the base Prototype */
class Record
{
public:
	virtual ~Record() {};
	virtual void print() = 0;
	virtual std::unique_ptr<Record> clone() = 0;
};

class CarRecord : public Record
{
private:
	std::string m_carName;
	int m_id;

public:
	CarRecord(std::string carName, int id)
		:
		m_carName{ carName },
		m_id{ id } {}

	void print() override
	{
		std::cout << "Card Record" << std::endl 
			<< "Name: " << m_carName 
			<< std::endl << "Number: " << m_id << std::endl;
	}

	std::unique_ptr<Record> clone() override
	{
		return std::make_unique<CarRecord>(*this);
	}
};

class PersonRecord : public Record
{
private:
	std::string m_bikeName;
	int m_id;

public:
	PersonRecord(std::string m_bikeName, int id)
		:
		m_bikeName{ m_bikeName },
		m_id{ id } {}

	void print() override
	{
		std::cout << "Card Record" << std::endl
			<< "Name: " << m_bikeName
			<< std::endl << "Number: " << m_id << std::endl;
	}

	std::unique_ptr<Record> clone() override
	{
		return std::make_unique<PersonRecord>(*this);
	}
};