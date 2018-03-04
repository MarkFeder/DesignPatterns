// AdapterPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Christian
{

public:

	virtual ~Christian()
	{
		std::cout << "Christian deleted!" << std::endl;
	}

	virtual void PerformChristianRitual() = 0;
};


class MaleChristian : public Christian
{

public:

	virtual void PerformChristianRitual() override
	{
		std::cout << "MaleChristian performs christian ritual" << std::endl;
	}


	virtual ~MaleChristian() override
	{
		std::cout << "MaleChristian deleted!" << std::endl;
	}
};

class Muslim
{

public:

	virtual ~Muslim() = default;

	virtual void PerformMuslimRitual() = 0;
};

class MaleMuslim : public Muslim
{

public:

	virtual void PerformMuslimRitual() override
	{
		std::cout << "MaleMuslim performs muslim ritual" << std::endl;
	}
};

//class MuslimAdapter : public Muslim
//{
//private:
//
//	Christian *christian;
//
//public:
//
//	MuslimAdapter (Christian* aChristian) : christian(aChristian) {}
//
//	virtual void PerformMuslimRitual() override
//	{
//		christian->PerformChristianRitual();
//	}
//
//	~MuslimAdapter()
//	{
//		delete christian;
//	}
//};
//
//int main()
//{
//	MaleChristian* male_christian = new MaleChristian();
//
//	MuslimAdapter *pAdaptedChristian = new MuslimAdapter(male_christian);
//	pAdaptedChristian->PerformMuslimRitual();
//
//	delete pAdaptedChristian;
//
//	return 0;
//}


class MuslimAdapter : public Muslim
{
private:

	std::unique_ptr<Christian> christian;

public:

	MuslimAdapter (std::unique_ptr<Christian> &aChristian) : christian(std::move(aChristian)) {}

	virtual void PerformMuslimRitual() override
	{
		christian->PerformChristianRitual();
	}
};


int main()
{
	//auto male_christian = std::unique_ptr<MaleChristian>(new MaleChristian());
	std::unique_ptr<Christian> male_christian = std::unique_ptr<MaleChristian>(new MaleChristian());

	// Ownership of unique_ptr changes (because of std::move in MuslimAdapter)
	MuslimAdapter *p_adapter = new MuslimAdapter(male_christian);
	p_adapter->PerformMuslimRitual();

	delete p_adapter;

	//MuslimAdapter *pAdaptedChristian = new MuslimAdapter(male_christian);
	//pAdaptedChristian->PerformMuslimRitual();

	return 0;
}