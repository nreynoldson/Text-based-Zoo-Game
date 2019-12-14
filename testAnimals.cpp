#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include  "Turtle.hpp"

#include <iostream>
using std::cout;
using std::endl; 

int main(void)
{
	cout <<"Making a tiger:" << endl;
	Tiger tig;
	cout << "Cost: " << tig.getCost() << endl
		  << "Babies: " <<  tig.getBabies() << endl
		  << "Payoff: " << tig.getPayoff() << endl
		  << "Base food: " << tig.getBaseFoodCost() << endl;
	cout << "Setting base age to 10" << endl;
	tig.setAge(10);
	cout << "Age: " << tig.getAge() << endl << endl;
	
	
	cout <<"Making a penguin:" << endl;
	Penguin pen;
	cout << "Cost: " << pen.getCost() << endl
		  << "Babies: " <<  pen.getBabies() << endl
		  << "Payoff: " << pen.getPayoff() << endl
		  << "Base food: " << pen.getBaseFoodCost() << endl;
	cout << "Setting base age to 10" << endl;
	pen.setAge(10);
	cout << "Age: " << pen.getAge() << endl << endl;


	cout <<"Making a turtle:" << endl;
	Turtle turt;
	cout << "Cost: " << turt.getCost() << endl
		  << "Babies: " <<  turt.getBabies() << endl
		  << "Payoff: " << turt.getPayoff() << endl
		  << "Base food: " << turt.getBaseFoodCost() << endl;
	cout << "Setting base age to 10" << endl;
	turt.setAge(10);
	cout << "Age: " << turt.getAge() << endl << endl;
}
