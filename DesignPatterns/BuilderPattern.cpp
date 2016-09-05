// DesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <memory>
#include <vector>


// ############################
// ##### Abstract classes #####
// ############################


class Packing
{
	
public:

	virtual ~Packing() {}

	virtual std::string Pack() { return std::string();  };
};

class Item
{

public:

	virtual ~Item() {}

	virtual std::string Name() { return std::string(); };

	virtual Packing* Wrap() { return nullptr;  }

	virtual float Price() { return 0.0f; };
};


// ##################################
// ##### Implementation classes #####
// ##################################


class Wrapper : public Packing
{
	
public:

	~Wrapper() {}

	std::string Pack() override
	{
		return "Wrapper";
	}
};

class Bottle : public Packing
{

public:

	~Bottle() {}

	std::string Pack() override
	{
		return "Bottle";
	}
};

class Burguer: public Item
{

public:

	~Burguer() {}

	virtual Packing* Wrap() override
	{
		return new Wrapper();
	}
};

class ColdDrink : public Item
{

public:

	~ColdDrink() {}

	virtual Packing* Wrap() override
	{
		return new Bottle();
	}
};


class ChickenBurguer : public Burguer
{

public:

	~ChickenBurguer() {}

	virtual std::string Name() override
	{
		return "Chicken Burguer";
	}

	virtual float Price() override
	{
		return 50.5f;
	}
};


class Pepsi : public ColdDrink
{

public:

	~Pepsi() {}

	virtual std::string Name() override
	{
		return "Pepsi";
	}

	virtual float Price() override
	{
		return 3.5f;
	}
};


class Meal
{

private:
	
	std::vector<std::unique_ptr<Item>> items;

public:

	void AddItem(Item* NewItem)
	{
		items.push_back(std::unique_ptr<Item>(NewItem));
	}

	float GetCost()
	{
		float cost = 0.0f;

		for (auto& item : items)
		{
			cost += item->Price();
		}

		return cost;
	}

	void ShowItems()
	{
		for (auto& item : items)
		{
			std::cout << "Item : " + item->Name() + "\t";
			std::cout << ", Packing : " + item->Wrap()->Pack() << "\t";
			std::cout << ", Price : " << item->Price() << std::endl;
		}
	}
};

class MealBuilder
{

public:

	static Meal* PrepareCasualMeal()
	{
		Meal *meal = new Meal();

		ChickenBurguer* Burguer = new ChickenBurguer();
		Pepsi* PepsiBottle = new Pepsi();

		meal->AddItem(Burguer);
		meal->AddItem(PepsiBottle);

		return meal;
	}
};

int main()
{
	auto MetalBuilder = new MealBuilder();

	auto MyFavoriteMeal = MetalBuilder->PrepareCasualMeal();

	// Print all info
	std::cout << "The cost of all meal is: " << MyFavoriteMeal->GetCost() << std::endl;
	MyFavoriteMeal->ShowItems();

	return EXIT_SUCCESS;
}
