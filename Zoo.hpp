/******************************************************************************
 * Program Name: Project 2 - Zoo Tycoon - Zoo Class Header
 * Date: 7/20/19
 * Name: Nicole Reynoldson
 * Description: Zoo class coordinates housing animals in exhibits, purchasing
 * animals, feeding and generating random events as well as maintaing the zoo
 * finances.
 *****************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <string>

using std::string;

enum Species {TIGER, PENGUIN, TURTLE}; 
enum State {BANKRUPT, FINISHED, UNFINISHED};

class Zoo
{
	private:
		// Pointers to an array for each species that will act as the 'exhibit'
		// Pointer for accessing the currently selected species exhibit	
		Animal *tigers, *turtles, *penguins;
		Animal *currSpp;

		//Variables for tracking the count  and max capacity for each species. 
		//Pointer to the count and capacity for the current species selected
		int turtleCount, penguinCount, tigerCount;
		int turtleCap, penguinCap, tigerCap;
		int *sppCount, *sppCap;

		//Hold the daily expenses and profits for each species
		//Pointer to expenses and profits of current species selected
		double turtleExpenses, penguinExpenses, tigerExpenses;
		double turtleProfits, penguinProfits, tigerProfits; 
		double *sppExpenses, *sppProfits;
	
		//Variables for calculating finances of the zoo
		double bonus, balance, dailyProfits, dailyExpenses;
		int day;

		double feedTypeCoef;
		State gameState;
		
		//Arrays to hold the type of animal and names
		Species animalList[4];
		string sppNamesUp[4];
		string sppNamesLow[4];

		//Member functions	
		void expandExhibit(Species);
		void addAnimal(Species, int, int qty = 1);
		void setCurrSpp(Species);
		bool babyBorn();
		bool attendanceBoost();
		bool adultInExhibit(Species);
		bool sickness(void);
		void noEvent(void);
	
	public:
		Zoo(double);
		~Zoo();
		//void printExhibit();
		double getBalance(void);
		void buyAnimal(Species, int, int qty = 1);
		State getGameState(void);
		void randomEvent(void);
		void advanceDay(void);
		void calcExpenses(void);
		void calcProfits(void);
		void pickFeed(void);
		void animalPrices(void);
		void dailySummary();
		void feedSummary();
		int getDay();
};

#endif		
