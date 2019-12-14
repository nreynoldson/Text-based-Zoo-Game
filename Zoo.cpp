/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Zoo Class Soure
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Zoo class coordinates housing animals in exhibits, purchasing
 * animals, feeding and generating random events as well as maintaing the zoo
 * finances.
 *****************************************************************************/
#include "Zoo.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "getInput.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

/******************************************************************************
 * Description: Constructor takes the starting cash as a double parameter and
 * initializes the starting balance with the value. Dynamically allocates an
 * 'exhibit' for each species of animal and initializes starting values for
 * member variables.
 *****************************************************************************/
Zoo::Zoo(double startCash): animalList {TIGER, PENGUIN, TURTLE}, 
sppNamesUp {"Tiger", "Penguin", "Turtle"}, sppNamesLow {"tiger", "penguin", "turtle"}
{
	balance = startCash;
	gameState = UNFINISHED;	
	day = 1;
	
	// Set up base exhibit size of 10 for each species
	tigers = new Tiger[10];
	turtles = new Turtle[10];
	penguins = new Penguin[10];
	
	tigerCap = turtleCap = penguinCap = 10;
	tigerCount = turtleCount = penguinCount = 0;

	tigerExpenses = turtleExpenses = penguinExpenses = 0;
	tigerProfits = turtleProfits = penguinProfits = 0;
	dailyExpenses = dailyProfits = bonus = 0;	

}

/******************************************************************************
 * Description: Destructor frees the dynamically allocated memory used for
 * each animal exhibit.
 *****************************************************************************/
Zoo::~Zoo()
{
	delete [] tigers;
	tigers = NULL;
	delete [] turtles;
	turtles = NULL;
	delete [] penguins;
	penguins = NULL;
}

/******************************************************************************
 * Description: This function takes a value of Species data type as parameter
 * and uses various pointers to point to the species information. This
 * function is useful for other member functions when used in conjunction
 * with the array of species types so that loops may be used to iterate through
 * each exhibit/animal.
 * ***************************************************************************/
void Zoo::setCurrSpp(Species animal)
{
	if(animal == TIGER)
	{
		currSpp = tigers;
		sppCount = &tigerCount;
		sppCap = &tigerCap;
		sppExpenses = &tigerExpenses;
		sppProfits = &tigerProfits;
	}
	else if (animal == PENGUIN)
	{
		currSpp = penguins;
		sppCount = &penguinCount;
		sppCap = &penguinCap;
		sppExpenses = &penguinExpenses;
		sppProfits = &penguinProfits;
	}
	else
	{
		currSpp = turtles;
		sppCount = &turtleCount;
		sppCap = &turtleCap;
		sppExpenses = &turtleExpenses;
		sppProfits = &turtleProfits;
	}
}

/******************************************************************************
 * Description: This function takes a value of Species data type as parameter
 * and uses the setCurrSpp function to point to the species information. 
 * Whether the exhibit is at capacity is checked by other functions that will
 * increase the animal count (buyAnimal, addAnimal, babyBorn). A temporary
 * pointer is used to dynamically allocate an array twice the size of the 
 * previous, the ages of animals are transferred and the memory from the old 
 * array is freed. 
 * ***************************************************************************/
void Zoo::expandExhibit(Species animal)
{
	setCurrSpp(animal);	
	Animal * temp;
	
	//Allocate an array twice the size for the desired exhibit
	if(animal == TIGER)
		temp = new Tiger[(*sppCap) * 2];
	else if(animal == PENGUIN)
		temp = new Penguin[(*sppCap) * 2];
	else	
		temp = new Turtle[(*sppCap) * 2];
	
	//The only variable that should be different for any specific instance
	//of a class is the age. Copy the ages of the objects from previous 
	//exhibit to the new exhibit.
	for(int i = 0; i < *sppCap; i++)
	{
		int age = currSpp[i].getAge();
		temp[i].setAge(age);
	}

	// Free the memory from the old exhibit and set the
	delete [] currSpp;
	currSpp = temp;

	// Double the capacity count
	*sppCap *= 2;
	
	// Make sure the original species pointer is pointing to the new exhibit
	// so it may be accessed in the future
	if(animal == TIGER)
		tigers = currSpp;
	else if(animal == PENGUIN)
		penguins = currSpp;
	else	
		turtles = currSpp;
}

	
/******************************************************************************
 * Description: addAnimal returns no value and takes three parameters: species
 * type, an int as the age and an int for the quantity of animals to add. 
 * The function will set the current species, will increase the count, expand
 * the exhibit if necessary and set the age. Used by both the buyAnimal() and
 * babyBorn functions
 * ***************************************************************************/
void Zoo::addAnimal(Species animal, int age, int qty)
{
	setCurrSpp(animal);
	for(int i = 0; i < qty; i++)
	{
		(*sppCount)++;
		if(*sppCount > *sppCap)
		{
			expandExhibit(animal);
		}
		
		currSpp[(*sppCount) - 1].setAge(age);
	}
}

/******************************************************************************
 * Description: buyAnimal take the same parameters as the addAnimal function:
 * Species type, int as the age and int for quantity). It checks that the 
 * total cost of the purchases is not greater than the balance. If so, it sets
 * the gameState to bankrupt. Otherwise, it will add the specified animals
 * and deduct the cost from the balance.
 * ***************************************************************************/
void Zoo::buyAnimal(Species animal, int age, int qty)
{
	setCurrSpp(animal);
	double totalCost = currSpp[0].getCost() * qty;

	if(totalCost > balance)
	{
		gameState = BANKRUPT;
	}

	else
	{
		addAnimal(animal, age, qty);
		balance -= totalCost;
	}
}

// Getter functions for zoo 
double Zoo::getBalance(void)
{
	return balance;
}

State Zoo::getGameState()
{
	return gameState;
}


/******************************************************************************
 * Description: Takes Species type as a parameter and checks if there are any 
 * adults in that specific exhibit. If so, the function returns true, else
 * it will return false if there are no adults present. Acts as a helper 
 * function to the babyBorn() function.
 * ***************************************************************************/
bool Zoo::adultInExhibit(Species animal)
{
	setCurrSpp(animal);
	for(int i = 0; i < *sppCount; i++)
	{
		if(currSpp[i].isAdult() == true)
		{
			return true;
		}
	}
	return false;	
}

/******************************************************************************
 * Description: Takes no parameters and will return a boolean value depending
 * on whether a baby was born to any animal or not. Function will check all 
 * exhibits for adults and will randomly select a species from those that do
 * to have a baby. If no exhibits have any babies, the function returns false.
 * ***************************************************************************/
bool Zoo::babyBorn(void)
{
	//Flag for determining whether there are adults in any of the exhibits
	bool babyPossible = false;
	
	// Holds all the species that do have an adult in the exhibit
	vector <Species> sppWithAdults;

	//Loop through to check for adults and add to the vector if so
	for(int i = 0; i < 3; i++)
	{
		if(adultInExhibit(animalList[i]) == true)
		{
			sppWithAdults.push_back(animalList[i]);
			babyPossible = true;
		}
	}
	
	// If at least one of the exhibits has an adult, generate a random number
	// and pull the corresponding species from the vector to have babies
	if(babyPossible == true)
	{
		int rNum = rand() % sppWithAdults.size();
		setCurrSpp(sppWithAdults[rNum]);
		addAnimal(sppWithAdults[rNum], 0, currSpp[0].getBabies());
		// potentially have strings set in current species function
		cout << "A " << sppNamesLow[static_cast<int>(sppWithAdults[rNum])] 
			  << " has given birth!" << endl;

		return true;
	}	
	else
	{
		return false;
	}
}

/******************************************************************************
 * Description: Takes no parameters and will return a boolean value if it is 
 * possible for an animal to die. Will check that an exhibit actually has 
 * animals that could be sick. If no animals are in the zoo, no event occurs
 * and the function returns false. Else, an animal from the chosen exhibit
 * is selected at random and all of the elements in the array are shifted. 
 * ***************************************************************************/
bool Zoo::sickness(void)
{
	// Counts the number of exhibits that have no animals in them
	int noAnimals = 0;
	
	//Iterate through all exhibits and increment if an exhibit does not have
	//any animals
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		if(*sppCount == 0)
			noAnimals++;
	}
 	
	//If none of the exhibits have animals, then no animals can die 
	if(noAnimals == 3)
	{
		return false;
	}
	else
	{
		int rNum;
		//Continue generating random numbers until the species selected
		//does have animals in its exhibit
		do
		{
	 		rNum = rand() % 3;
			setCurrSpp(animalList[rNum]);
		}while(*sppCount == 0);
		
		cout << "A " << sppNamesLow[rNum] << " is sick and has died!" << endl;
		//Generate a random number to choose the specific animal in the exhibit
		//to die
		rNum = rand() % *sppCount; 

		// Shift each element of the array by setting age
		// set the last element of the array to -1 to signify no animals
		for(int i = rNum; i < *sppCount - 1; i++)
		{
			currSpp[i].setAge(currSpp[i+1].getAge());
		}
		currSpp[*sppCount - 1].setAge(-1);
		(*sppCount)--;
	
		return true;
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Simply displays
 * a prompt to the screen 
 * ***************************************************************************/
void Zoo::noEvent(void)
{
	cout << "Just another uneventful day at the zoo..." << endl;
}

/******************************************************************************
 * Description: Takes no parameters and returns a boolean value. If there are
 * tigers in the exhibit, a random value between 250 and 500 is generated
 * and multiplied by the total number of tigers. Value of the bonus is added
 * to the balance in the calcProfits() function. If there are no tigers in the
 * zoo, the function simply returns false.
 * ***************************************************************************/
bool Zoo::attendanceBoost(void)
{
	if(tigerCount == 0)
	{
		return false;
	}
	else
	{
		double baseBonus = (rand() % 251) + 250;
		bonus = baseBonus * tigerCount;

		cout << "The guests love your tiger exhibit! You experience an unexpected attedance boost!" << endl;
		cout << "As a result, you pocket an additional $" << baseBonus << " per tiger. " <<  endl;
		
		return true;
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Depending on the 
 * user choice for feed, the feedTypeCoef will be initialized and used to
 * calculate the probability of sickness and feeding costs.
 * ***************************************************************************/
void Zoo::pickFeed(void)
{
	cout << "Choose feed type: " << endl;
	cout << "1. Cheap - $" << BASEFOOD / 2 << endl;
	cout << "2. Generic - $" << BASEFOOD << endl;
	cout << "3. Premium - $" << BASEFOOD * 2 << endl;
	int choice = getInt(1, 3);
	
	if(choice == 1)
	{
		feedTypeCoef = 0.5;
	}
	else if(choice == 2)
	{
		feedTypeCoef = 1.0;
	}
	else
	{
		feedTypeCoef = 2.0;
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Calculates the
 * probability that a sickness should occur based on the feed type chosen by 
 * the user. 
 * ***************************************************************************/
void Zoo::randomEvent(void)
{
	// Calculate the probability that sickness shoudl occur
	double prob = 50.0 / feedTypeCoef;
	int rNum = rand() % 200 + 1;

	// If the number generated is greater than the calculated probability
	// then generate one of the remaining 3 events with equal probability
	if(rNum > prob)
	{
		rNum = rand() % 3 + 1;
		
		switch(rNum)
		{
			case 1:
			{
				//If any of the events return a value of false
				//trigger the noEvent() function
				if(attendanceBoost() == false)
				{
					noEvent();
				}
				break;
			}
			case 2:
			{
				if(babyBorn() == false)
				{
					noEvent();
				}
				break;
			}
			case 3:
			{
				noEvent();
			}
		}
	}
	else
	{
		if(sickness() == false)
		{
			noEvent();
		}
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Will iterate through
 * every instance of each species and will increment the age by 1. Increments
 * the day. Resets the total daily profits and expenses as well as the species
 * specific expenses and profits and the potential bonus value.
 * ***************************************************************************/
void Zoo::advanceDay(void)
{
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		for(int j = 0; j < *sppCount; j++)
		{
			currSpp[j].incrementAge();
		}
	}
	day++;
	
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		*sppProfits = *sppExpenses = 0;	
	}

	dailyProfits = dailyExpenses = bonus = 0;
}


/******************************************************************************
 * Description: Takes no parameters and returns no values. Will iterate through
 * each species type and calculate the daily feed costs by multiplying the base
 * food cost for that species by the feedTypeCoef and the species count. If the
 * daily expenses do not exceed the balance of the zoo, the value is deducted 
 * from the balance, else the gameState will be updated to bankrupt.
 * ***************************************************************************/
void Zoo::calcExpenses()
{
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		*sppExpenses = (currSpp[0].getBaseFoodCost() * feedTypeCoef) * (*sppCount);
		dailyExpenses += *sppExpenses;		
	}

	if(dailyExpenses > balance)
	{
		gameState = BANKRUPT;
	}
	else
	{
		balance -= dailyExpenses;
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Will iterate through
 * each species type, calculate total species by multiplying specific species
 * payoff by the species count and adding it to the zoo balance.
 * ***************************************************************************/
void Zoo::calcProfits()
{
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		*sppProfits = currSpp[0].getPayoff() * (*sppCount);
		dailyProfits = dailyProfits + (*sppProfits);		
	}

	dailyProfits += bonus;
	balance += dailyProfits;
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Displays the species
 * available for purchase and their prices.
 * ***************************************************************************/
void Zoo::animalPrices()
{
	cout << "\nANIMAL PRICES" << endl;
	cout << string(14, '-') << endl;
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		cout << sppNamesUp[i] << ": $" << currSpp[0].getCost() << endl;
	}
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Displays the number
 * of each species that were fed.
 * ***************************************************************************/
void Zoo::feedSummary()
{
	cout << "\nAnimals fed: " << endl;
	for(int i = 0; i < 3; i++)
	{
		setCurrSpp(animalList[i]);
		cout << sppNamesUp[i] << "s: " << *sppCount << endl;
	}
	cout << endl;
}

int Zoo::getDay()
{
	return day;
}

/******************************************************************************
 * Description: Takes no parameters and returns no values. Displays all of 
 * the financials for the current day.
 * ***************************************************************************/
void Zoo::dailySummary()
{
	cout << endl << endl << string(80, '-') << endl;
	cout << "DAY " << day << " SUMMARY" << endl;
	cout << string(80, '-') << endl;
	cout << std::fixed << std::setprecision(2);
	cout << left << setw(25) << " " << setw(25) << "Profits" << setw(25) 
		  << "Expenses" << endl; 

	cout << setw(10) << "Tigers: " << setw(15) << tigerCount << "$"
		  << setw(24) << tigerProfits << "$" << setw(24) << tigerExpenses << endl;
	
	cout << setw(10) << "Penguins: " << setw(15) << penguinCount << "$"
		  << setw(24) << penguinProfits << "$" << setw(24) << penguinExpenses << endl;

	cout << setw(10) << "Turtles: " << setw(15) << turtleCount << "$"
		  << setw(24) << turtleProfits << "$" << setw(24) << turtleExpenses << endl;
	
	cout << setw(25) << "Bonus: " << "$" << setw(49) << bonus << endl;
	
	cout << setw(25) <<  " " << setw(25) << string(10, '-') << setw(25) << string(10, '-') << endl;

	cout << setw(25) << " " << "$" << setw(24) <<  dailyProfits
		  << "$" << setw(24) << dailyExpenses << endl;
	
	cout << setw(10) << "\nBalance:" << "$" << setw(14) << balance << endl;

	cout << string(80, '-') << endl;
}

/*
void Zoo::printExhibit()
{
	cout << "\nTigers" << endl;
	for(int i = 0; i < tigerCap; i++)
	{
		cout << "Age " << i << ":" << tigers[i].getAge() << " "; 
		cout << "Cost " << i << ":" << tigers[i].getCost() << endl;
	}
	cout << endl << "COUNT: " << tigerCount << " CAP: " << tigerCap << endl;
	
	cout << "\nPenguins" << endl;
	for(int i = 0; i < penguinCap; i++)
	{
		cout << "Age " << i << ":" << penguins[i].getAge() << " "; 
		cout << "Cost " << i << ":" << penguins[i].getCost() << endl;
	}
	cout << endl << "COUNT: " << penguinCount << " CAP: " << penguinCap << endl;
	
	cout << "\nTurtles" << endl;
	for(int i = 0; i < turtleCap; i++)
	{
		cout << "Age " << i << ":" << turtles[i].getAge() << " "; 
		cout << "Cost " << i << ":" << turtles[i].getCost() << endl;
	}
	cout << endl << "COUNT: " << turtleCount << " CAP: " << turtleCap << endl;
}
*/
