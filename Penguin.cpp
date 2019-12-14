/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Penguin Class Source File
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Species derived from the Animal class. Inherits all of the 
 * necessary setter and getter functions. Constructor initializes specific
 *	penguin information: number of babies, cost, payoff, basefood cost.
 *****************************************************************************/
#include "Penguin.hpp"

Penguin::Penguin()
{
	numberOfBabies = PENG_BABIES;
	cost = PENG_COST;
	payoff = cost * PENG_PAYPERCENT;
	baseFoodCost *= PENG_FOODCOEFF;
}

