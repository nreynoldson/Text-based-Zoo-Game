/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Animal Class Soure
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Animal is an abstract base class used for deriving specific
 * species classes. Contatins basic getter and setter functions that do not
 * need to be specialized by derived classes.
 *****************************************************************************/
 #include "Animal.hpp"

//Constructor sets age to -1 so animals added to the zoo can be differentiated
//from those that are just sitting in the array
Animal::Animal()
{
	age = -1;
	baseFoodCost = BASEFOOD;
}
		
// Function used to check whether an animal is an adult. Takes no parameters
// and returns a boolean value.
bool Animal::isAdult(void)
{
	if(age >= 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Getter and setter functions to be used by each derived class
double Animal::getPayoff(void)
{
	return payoff;
}

int Animal::getBabies(void)
{
	return numberOfBabies;
}

double Animal::getCost(void)
{
	return cost;
}

int Animal::getAge(void)
{
	return age;
}

double Animal::getBaseFoodCost(void)
{
	return baseFoodCost;
}

void Animal::setAge(int ageIn)
{
	age = ageIn;
}

//Increments the animals age by 1
void Animal::incrementAge(void)
{
	age++;
}
