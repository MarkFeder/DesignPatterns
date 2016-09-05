// PrototypePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>


class Pizza
{

protected:

	std::string Name;
	int Price;

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

	virtual std::unique_ptr<Pizza> clone() = 0;
};

class HamAndMushroomPizza : public Pizza
{
public:


	HamAndMushroomPizza()
	{
		Name = "HamAndMushroomPizza";
		Price = 15;
	}

	virtual int GetPrice() const override
	{
		return Price;
	}

	virtual ~HamAndMushroomPizza()
	{
		std::cout << "HamAndMushroomPizza destructor called!" << std::endl;
	};

	virtual std::unique_ptr<Pizza> clone() override
	{
		return std::make_unique<HamAndMushroomPizza>(*this);
	}
};


class BaconAndCheesePizza : public Pizza
{
public:

	BaconAndCheesePizza()
	{
		Name = "BaconAndCheesePizza";
		Price = 12;
	}

	virtual int GetPrice() const override
	{
		return Price;
	}

	virtual ~BaconAndCheesePizza()
	{
		std::cout << "BaconAndCheesePizza destructor called!" << std::endl;
	};

	virtual std::unique_ptr<Pizza> clone() override
	{
		return std::make_unique<BaconAndCheesePizza>(*this);
	}
};


class DeluxePizza : public Pizza
{
public:

	DeluxePizza()
	{
		Name = "DeluxePizza";
		Price = 10;
	}

	virtual int GetPrice() const override
	{
		return Price;
	}

	virtual ~DeluxePizza()
	{
		std::cout << "Deluxe destructor called!" << std::endl;
	};

	virtual std::unique_ptr<Pizza> clone() override
	{
		return std::make_unique<DeluxePizza>(*this);
	}
};

enum PizzaType
{
	HamAndMushroom,
	BaconAndCheese,
	Deluxe
};

class PizzaFactory
{
private:

	std::unordered_map<PizzaType, std::unique_ptr<Pizza>, std::hash<int>> Orders;

public:

	PizzaFactory()
	{
		Orders[PizzaType::HamAndMushroom] = std::make_unique<HamAndMushroomPizza>();
		Orders[PizzaType::Deluxe] = std::make_unique<DeluxePizza>();
		Orders[PizzaType::BaconAndCheese] = std::make_unique<BaconAndCheesePizza>();
	}

	~PizzaFactory()
	{
		std::cout << "PizzaFactory destructor called!" << std::endl;
	}

	std::unique_ptr<Pizza> CreatePizza(PizzaType pizzaType)
	{
		return Orders[pizzaType]->clone();
	}
};


int main()
{

	PizzaFactory *pPizzaFactory = new PizzaFactory();

	auto pizza = pPizzaFactory->CreatePizza(PizzaType::HamAndMushroom);
	pizza->ShowPrice();

	delete pPizzaFactory;

	return EXIT_SUCCESS;
}

