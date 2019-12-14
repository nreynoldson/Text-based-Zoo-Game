/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Turtle Class Source File
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Species derived from the Animal class. Inherits all of the 
 * necessary setter and getter functions. Constructor initializes specific
 *	turtle information: number of babies, cost, payoff, basefood cost.
 *****************************************************************************/
#include "Turtle.hpp"

Turtle::Turtle()
{
	numberOfBabies = TURTLE_BABIES;
	cost = TURTLE_COST;
	baseFoodCost *= TURTLE_FOODCOEFF;
	payoff = cost * TURTLE_PAYPERCENT;
}
