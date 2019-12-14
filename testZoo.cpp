#include "Zoo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
int main ()
{

	srand(time(0));

	Zoo aZoo(10000000000000);
	Zoo bZoo(1000000000000);
	Zoo cZoo(10000000000);
	
	cout << "No animals in exhibit" << endl;
	bool test = aZoo.sickness();
	if (test == false)
	{
		cout << "false" << endl;
	}
	else
	{
		cout << "true" << endl;
	}
	
//	aZoo.buyAnimal(TIGER, 0, 2);
//	aZoo.buyAnimal(PENGUIN, 3, 2);
//	aZoo.buyAnimal(TURTLE, 5, 2);
//	aZoo.babyBorn();
	aZoo.printExhibit();

	cout << "Buying 2 tiger age 0, 2 penguin age 0, 2 turtle age 0" << endl;
	bZoo.buyAnimal(TIGER, 0, 2);
	bZoo.buyAnimal(PENGUIN, 0, 2);
	bZoo.buyAnimal(TURTLE, 0, 2);
	//bZoo.babyBorn();
	test = bZoo.sickness();
	if (test == false)
	{
		cout << "false" << endl;
	}
	else
	{
		cout << "true" << endl;
	}
	bZoo.printExhibit();

	cout << "Buying tigers of varying ages" << endl;
	cZoo.buyAnimal(TIGER, 1);
	cZoo.buyAnimal(TIGER, 2);
	cZoo.buyAnimal(TIGER, 3);
	cZoo.buyAnimal(TIGER, 4);
	cZoo.buyAnimal(TIGER, 5);
	cZoo.buyAnimal(TIGER, 6);
	cZoo.buyAnimal(TIGER, 7);
	cZoo.buyAnimal(TIGER, 8);
	cZoo.buyAnimal(TIGER, 9);
	cZoo.buyAnimal(TIGER, 10);
	cZoo.sickness();
//	cZoo.babyBorn();
	cZoo.printExhibit();
	
	/*cout << "Buying 8 animals of each, age 7" << endl;
	aZoo.buyAnimal(TIGER, 7, 8);
	aZoo.buyAnimal(PENGUIN, 7, 8);
	aZoo.buyAnimal(TURTLE, 7, 8);
	aZoo.printExhibit();
*/
//	aZoo.setCurrSpp(TURTLE);
	
}

