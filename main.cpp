#include <iostream>
#include "Zoo.hpp"
#include <string>
#include "menus.hpp"
#include "getInput.hpp"
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main ()
{
	// Seeding random functions in Zoo class
	// setting up arrays to list the animals
	srand(time(0));
	string animalNames[] = {"Tiger", "Penguin", "Turtle"};
	Species animalList[] = {TIGER, PENGUIN, TURTLE}; 

	int menuChoice;
	int balance;
	bool gameFinished = false;

	// General instructions, asking the player if they would like to play or quit
	cout << endl << string(80, '-') << endl; 
	cout << "ZOO TYCOON WITH EXTRA CREDIT - USER PICKS FEED" << endl;
	cout << string(80, '-') << endl;

	cout << "You are now the proud owner of a zoo! You will be in charge of the"
		  << " daily " << endl << "operations including maintaining finances, "
		  << "exhibits and the care of animals." << endl << "The goal is to make as"
		  << " much money as possible and not go bankrupt!" << endl;
	cout << string(80, '-') << endl;
	
	playMenu();
	menuChoice = getInt(1, 2);

	// If the player would like to quit, terminate the program
	if(menuChoice == 2)
	{
		cout << "\nTerminating Zoo Tycoon." << endl;
		return 0;
	}
	
	//Allow the user to choose from 3 different start balance difficulties
	//instantiate the zoo
	balance = chooseDifficulty();
	Zoo userZoo(balance);
		
	// Display prices of each animal and take the qty to be purchased for each
	userZoo.animalPrices();
	cout << "\n\nTo begin your zoo you must buy 1 or 2 animals of each type " 
		  << "listed above. " << endl;
	cout << "Enter the desired quantity of: " << endl;
		
	for(int i = 0; i < 3 && gameFinished != true; i++)
	{
		cout << endl << animalNames[i] << ": ";
		int qty = getInt(1, 2);
		userZoo.buyAnimal(animalList[i], 1, qty);
	
		if(userZoo.getGameState() == BANKRUPT)
		{
			gameFinished = true;
			cout << "GAMEOVER: You have gone bankrupt!" << endl;
		}
		else
		{
			cout << "Balance: $" << userZoo.getBalance() << endl;
		}	
	}
	
	// While loop contains all of the actions for completeing a single day at
	while(gameFinished == false)
	{
		cout << endl << string(80, '-') << endl;
		cout << "FEEDING ANIMALS" << endl;
		cout << string(80, '-') << endl;
		cout << "The base cost of food per animal is listed below. Each species has a unique " << endl
			  << "multiplier that makes food more or less expensive. Careful, as cheaper feed will" << endl
			  << "make sickness more likely!" << endl;
		cout << string(80, '-') << endl;
		
		//Have the user choose their feed and calculate the expenses
		cout << "Balance: $" << userZoo.getBalance() << endl << endl;
		userZoo.pickFeed();
		userZoo.calcExpenses();
		if(userZoo.getGameState() != BANKRUPT)
		{
			userZoo.feedSummary();
			
			// Calculate financials and display the day summary
			cout << endl << string(80, '-') << endl;
			cout << "NOTABLE EVENTS" << endl;
			cout << string(80, '-') << endl;
			userZoo.randomEvent();
			userZoo.calcProfits();
			userZoo.dailySummary();
			
			cout << "\nBefore the day advances, you may buy 1 animal of any type. " << endl;
			cout << "Add another animal to exhibit? (y/n)  ";
		
			char choice = getChar('y', 'n');
			
			//If user would like to add animals, provide a list and take the user choice		
			if(choice == 'y')
			{
				cout << "\nCHOOSE AN ANIMAL" << endl;
				cout << string(16, '-') << endl;
				for(int i = 0; i < 3; i++)
				{
					cout << i + 1 << ". " << animalNames[i] << endl;
				}
			
				menuChoice = getInt(1, 3);
		
				userZoo.buyAnimal(static_cast<Species>(menuChoice - 1), 3, 1);
				
				if(userZoo.getGameState() == BANKRUPT)
				{
					cout << "GAMEOVER: You have gone bankrupt!" << endl;
					return 0;
				}
	
				cout << "\nYou have purchased a " << animalNames[menuChoice - 1] << endl;
			}
			
			gameFinished = exitMenu();
			if(gameFinished == true)
			{
				cout << "Thank you for playing!" << endl;
			}
			else
			{
				userZoo.advanceDay();
				cout << "\nSTARTING DAY " << userZoo.getDay();
			}
		}
		else
		{
			gameFinished = true;
			cout << "GAMEOVER: You have gone bankrupt!" << endl;;
		}
	}

	return 0;
}

	
