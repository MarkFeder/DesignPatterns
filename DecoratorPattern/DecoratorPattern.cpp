// DecoratorPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Car
{
protected:

	std::string m_name;

public:

	// Custom Constructors
	Car() { m_name = "Unknown Car!"; }
	Car(std::string& name) { m_name = name; }

	virtual std::string GetName() const { return m_name; }
	virtual double GetCost() = 0;
	virtual ~Car() { std::cout << "<Car::~Car>\n"; }
};

class CarModelOne : public Car
{
public:
	
	// Custom Constructors and Destructors
	CarModelOne() { m_name = "CarModelOne"; }
	~CarModelOne() { std::cout << "<CarModelOne::~CarModelOne>\n"; }

	virtual double GetCost() { return 31000.23; }
};

class OptionsDecorator : public Car
{
public:

	virtual std::string GetName() = 0;
	virtual ~OptionsDecorator() { std::cout << "<OptionsDecorator::~OptionsDecorator>\n"; }
};

class Navigation : public OptionsDecorator
{
private:

	Car* m_pCar;

public:

	Navigation(Car *pCar) { m_pCar = pCar; }
	~Navigation() 
	{ 
		std::cout << "<Navigation::~Navigation()>\n"; 
		delete m_pCar; 
	}

	virtual std::string GetName() { return m_pCar->GetName().append(", Navigation"); }
	virtual double GetCost() { return m_pCar ? 300.56 + m_pCar->GetCost() : 0.0; }

	Car* GetCar() const { return m_pCar; }
};

int main()
{
	// Create the car that we want to buy
	Car *newCar = new CarModelOne();

	std::cout << "Base model of " << newCar->GetName() << " costs $" << newCar->GetCost() << std::endl;

	// Add more features to the base model
	newCar = new Navigation(newCar);
	std::cout << newCar->GetName() << " will cost you $" << newCar->GetCost() << "\n";
	
	delete newCar;

    return EXIT_SUCCESS;
}

