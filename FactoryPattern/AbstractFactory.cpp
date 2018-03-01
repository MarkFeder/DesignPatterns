// AbstractFactory.cpp: An utility class that creates an isntance of a class from a family of derived classes

#include "stdafx.h"
#include <iostream>

class Computer
{
public:
	virtual void Run() = 0;
	virtual void Stop() = 0;

	virtual ~Computer() { std::cout << "Calling Computer class destructor " << std::endl; };
};

class Laptop : public Computer
{
public:
	void Run() override { m_Hibernating = false; }
	void Stop() override { m_Hibernating = true; }

	virtual ~Laptop() { std::cout << "Calling Laptop class destructor" << std::endl; };

private:
	bool m_Hibernating;
};

class Desktop : public Computer
{
public:
	void Run() override { m_On = true; }
	void Stop() override { m_On = false; }

	virtual ~Desktop() { std::cout << "Calling Desktop class destructor" << std::endl; }

private:
	bool m_On;
};

enum EComputerType
{
	ECT_None,
	ECT_Laptop,
	ECT_Desktop
};

class ComputerFactory
{
public:
	static Computer* CreateNewComputer(EComputerType computerType)
	{
		switch (computerType)
		{			
			case EComputerType::ECT_Laptop:
				return new Laptop();
			
			case EComputerType::ECT_Desktop:
				return new Desktop();
			
			case EComputerType::ECT_None:
			default:
				return nullptr;
		}
	}

	~ComputerFactory() { std::cout << "Calling ComputerFactory class destructor" << std::endl; }
};


