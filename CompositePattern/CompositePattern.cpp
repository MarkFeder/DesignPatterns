// CompositePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>

class Graphic
{
public:

	virtual void Print() const = 0;
	virtual ~Graphic() = default;
};

class Ellipse : public Graphic
{
public:

	void Print() const
	{
		std::cout << "Ellipse \n";
	}
};

class CompositeGraphic : public Graphic
{
public:

	void Print() const
	{
		for (auto graphic : m_graphicList)
		{
			graphic->Print();
		}
	}

	void Add(Graphic* NewGraphic)
	{
		m_graphicList.push_back(NewGraphic);
	}

private:

	std::vector<Graphic*> m_graphicList;
};

int main()
{
	// Initialize four ellipses
	const std::unique_ptr<Ellipse> ellipse1 = std::make_unique<Ellipse>();
	const std::unique_ptr<Ellipse> ellipse2 = std::make_unique<Ellipse>();
	const std::unique_ptr<Ellipse> ellipse3 = std::make_unique<Ellipse>();
	const std::unique_ptr<Ellipse> ellipse4 = std::make_unique<Ellipse>();

	// Initialize three composite graphics
	const std::unique_ptr<CompositeGraphic> graphic1 = std::make_unique<CompositeGraphic>();
	const std::unique_ptr<CompositeGraphic> graphic2 = std::make_unique<CompositeGraphic>();
	const std::unique_ptr<CompositeGraphic> graphic3 = std::make_unique<CompositeGraphic>();

	// Composite the graphics
	graphic2->Add(ellipse1.get());
	graphic2->Add(ellipse2.get());
	graphic2->Add(ellipse3.get());

	graphic3->Add(ellipse4.get());

	graphic1->Add(graphic2.get());
	graphic1->Add(graphic3.get());

	// Prints the complete graphic
	graphic1->Print();

    return 0;
}

