/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Animal Class Header
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Animal is an abstract base class used for deriving specific
 * species classes. Contatins basic getter and setter functions that do not
 * need to be specialized by derived classes.
 *****************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "constants.hpp"
class Animal
{
	protected:
		int age;
		int numberOfBabies;
		double cost;
		double baseFoodCost;
		double payoff;
	
	public:
		Animal();

		//Getter and setter functions
		double getPayoff();
		int getBabies();
		double getCost();
		int getAge(void);
		double getBaseFoodCost(void);
		void setAge(int);

		void incrementAge(void);
		bool isAdult();
};

#endif	
