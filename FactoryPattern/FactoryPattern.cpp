// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>
#include <vector>

class Pizza
{
public:

	virtual int GetPrice() const = 0;
	
	virtual ~Pizza()
	{
		std::cout << "Pizza destructor called!" << std::endl;
	};

	void ShowPrice()
	{
		std::cout << "The pizza costs: " << GetPrice() << std::endl;
	}
};

class HamAndMushroomPizza : public Pizza
{
public:

	virtual int GetPrice() const override
	{
		return 15;
	}

	virtual ~HamAndMushroomPizza()
	{
		std::cout << "HamAndMushroomPizza destructor called!" << std::endl;
	};
};


class BaconAndCheesePizza : public Pizza
{
public:

	virtual int GetPrice() const override
	{
		return 12;
	}

	virtual ~BaconAndCheesePizza()
	{
		std::cout << "BaconAndCheesePizza destructor called!" << std::endl;
	};
};


class DeluxePizza : public Pizza
{
public:

	virtual int GetPrice() const override
	{
		return 10;
	}

	virtual ~DeluxePizza()
	{
		std::cout << "Deluxe destructor called!" << std::endl;
	};
};


class PizzaFactory
{

public:

	enum PizzaType
	{
		HamAndMushroom,
		BaconAndCheese,
		Deluxe
	};

	static std::unique_ptr<Pizza> CreateNewPizza(PizzaType type)
	{
		switch (type)
		{
			case HamAndMushroom:
				return std::make_unique<HamAndMushroomPizza>();

			case BaconAndCheese:
				return std::make_unique<BaconAndCheesePizza>();

			case Deluxe:
				return std::make_unique<DeluxePizza>();
		}
	}

	~PizzaFactory()
	{
		std::cout << "PizzaFactory destructor called!" << std::endl;
	}
};


int main()
{
	PizzaFactory* Factory = new PizzaFactory();

	auto pizza = Factory->CreateNewPizza(PizzaFactory::PizzaType::HamAndMushroom);

	pizza->ShowPrice();

	delete Factory;

	return EXIT_SUCCESS;
}

