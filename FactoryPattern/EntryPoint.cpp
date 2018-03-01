#include "stdafx.h"
#include "AbstractFactory.cpp"

int main()
{
	//PizzaFactory* Factory = new PizzaFactory();

	//auto pizza = Factory->CreateNewPizza(PizzaFactory::PizzaType::HamAndMushroom);

	//pizza->ShowPrice();

	//delete Factory;

	Computer* firstComputer = ComputerFactory::CreateNewComputer(EComputerType::ECT_Laptop);
	Computer* secondComputer = ComputerFactory::CreateNewComputer(EComputerType::ECT_Desktop);

	firstComputer->Run();
	secondComputer->Stop();

	delete firstComputer;
	delete secondComputer;

	return EXIT_SUCCESS;
}