/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Tiger Class Header File
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Species derived from the Animal class. Inherits all of the 
 * necessary setter and getter functions. Constructor initializes specific
 *	tiger information: number of babies, cost, payoff, basefood cost.
 *****************************************************************************/
#include "Tiger.hpp"

Tiger::Tiger()
{
	numberOfBabies = TIGER_BABIES;
	cost = TIGER_COST;
	baseFoodCost *= TIGER_FOODCOEFF;
	payoff = cost * TIGER_PAYPERCENT;
}
