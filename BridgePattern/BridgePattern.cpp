// BridgePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/* Implementor */
class DrawingAPI
{
public:

	virtual void DrawCircle(double x, double y, double radius) = 0;
	virtual ~DrawingAPI() = default;
};

/* Concrete ImplementorA */
class DrawingAPI1 : public DrawingAPI
{
public:

	void DrawCircle(double x, double y, double radius)
	{
		std::cout << "API1.circle at " << x << ":" << y << ' ' << radius << std::endl;
	}
};

/* Concrete ImplementorB */
class DrawingAPI2 : public DrawingAPI
{
public:

	void DrawCircle(double x, double y, double radius)
	{
		std::cout << "API2.circle at " << x << ":" << y << ' ' << radius << std::endl;
	}
};

/* Abstraction */
class Shape
{
public:

	virtual ~Shape() = default;
	virtual void Draw() = 0;
	virtual void ResizeByPercentage(double pct) = 0;
};

/* Refined Abstraction */
class CircleShape : public Shape
{
public:

	CircleShape(double x, double y, double radius, DrawingAPI* drawingAPI) : 
		m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI) {}

	void Draw()
	{
		m_drawingAPI->DrawCircle(m_x, m_y, m_radius);
	}

	void ResizeByPercentage(double pct)
	{
		m_radius *= pct;
	}

private:

	double m_x, m_y, m_radius;
	DrawingAPI* m_drawingAPI;
};

int main()
{
	CircleShape *circle1 = new CircleShape(1, 2, 3, new DrawingAPI1());
	CircleShape *circle2 = new CircleShape(5, 7, 11, new DrawingAPI2());
	
	circle1->ResizeByPercentage(2.5);
	circle2->ResizeByPercentage(2.5);

	circle1->Draw();
	circle2->Draw();
	
	delete circle1, circle2;

    return 0;
}

