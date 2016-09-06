// SingletonPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cassert>


class StringSingleton
{

public:
	
	const std::string GetString() { return m_String; }

	void SetString(const std::string& string)
	{
		m_String = string;
	}

	// Magic function
	static StringSingleton& Instance()
	{
		static StringSingleton *instance = new StringSingleton;

		// returns same instance
		return *instance;
	}

private:

	StringSingleton() {}

	~StringSingleton() {}

	// Prevent from copy
	StringSingleton(const StringSingleton& old) {}
	const StringSingleton& operator=(const StringSingleton& old) {}

private:

	std::string m_String;
};

int main()
{
	std::cout << "Comparing both calls ... " << std::endl;
	std::cout << "first call: "<< &StringSingleton::Instance() << " address" << std::endl;
	std::cout << "second call: " << &StringSingleton::Instance() << " address" << std::endl;

	assert(&StringSingleton::Instance() == &StringSingleton::Instance());

	return 0;
}

