// Inlcuding the main program librairies
#include <iostream>
#include <vector>

// Including the header files
#include "Encore.h"
#include "LotteryGame.h"
#include "Ticket.h"

using namespace std;

// Function to get all the lines of numbers for a ticket
vector<vector<int>> getAllLines(int amountOfTickets, double &budget, vector<int> winningNums, int& moneyMadeFromMainGame) {
    LotteryGame lotteryGame;

    std::vector<vector<int>> lines;
    std::vector<int> newLine;

    for (int i = 0; i < amountOfTickets * 2; i++){

		// Generate the line of numbers
        newLine = lotteryGame.generateUserNumbers();

		// Get the rewards for the line of numbers (howManyNumbersMatch returns the money made from the ticket lines)
        // Updates the budget
        budget += lotteryGame.howManyNumbersMatch(newLine, winningNums, budget, moneyMadeFromMainGame);

        lines.push_back(newLine);
    }
	return lines;
}




void runOneGame(bool isEncore, int amountOfLines, double budget) {
	int moneyMadeFromMainGame = 0;
	int moneyMadeFromEncore = 0;


    // Lottery Game Logic
    // Create the lottery game object
    LotteryGame lotteryGame;

    // Get the winning numbers
    vector<int> winningNums = lotteryGame.generateWinningNumbers();
    
    // Creating a vector to hold all the users ticket lines
	vector<vector<int>> allTicketLines;

	// Get all the ticket lines and rewards (budget is updated)
    allTicketLines = getAllLines(amountOfLines, budget, winningNums, moneyMadeFromMainGame);



	// Encore Logic
    if (isEncore)
    {
		lotteryGame.playEncore(budget);
    }

    // Ticket Logic
	vector<int> userTicketNumbers;

	// Add all of the ticket lines to the user numbers vector
    for (int i = 0; i < allTicketLines.size(); i++) 
    {
		for (int j = 0; j < allTicketLines[i].size(); j++) 
        {  
			userTicketNumbers.push_back(allTicketLines[i][j]);
		}
    }

	Ticket ticket(userTicketNumbers, winningNums);

	ticket.createResultsFile(userTicketNumbers, winningNums, amountMadeFromMainGame, amountMadeFromEncore);

    ticket.generateUserTicket();



}


int main()
{
    double budget;
	bool isEncore = false;
    bool buyTicket;
    int howManyEncores;

    cout << "Welcome to the Lottery Game!" << endl;
    cout << "https://www.olg.ca/en/lottery/play-lottario-encore/past-results.html view the rules and regulations here." << endl;
    cout << "In this Lottery Game, You get 6 numbers, plus 1 bonus number. Every player gets two lines." << endl;
    cout << "1$ is the price to play 1 game." << endl;
    cout << "Please enter your budget:" << endl;
    cin >> budget;
    
    //Input validation for budget
    while (budget < 0 || cin.fail()) {
        cout << "Invalid input, budget must be a number greater than 0, please re-enter your budget:" << endl;
        cin >> budget;
    }

    while (true) {
        // Get the winning numbers


		int startGame;

		// Check if the user budget is greater than 1. If it is, ask if they want to play encore
        if (budget >= 1) 
        {
            cout << "Budget: " << budget << " how many lines would you like of the main game? (0-30)" << endl;
            cin >> startGame;
            //Input validation for startgame
            while (startGame > 30 || startGame < 0) {
                cout << "please enter a number of lines 0-30" << endl;
                cin >> startGame;
            }

			// Exit the game if the user does not want to play
            if (startGame == 0) 
            {
				cout << "Goodbye!" << endl;
                break;
            }
            else if (startGame % 2 == 1){
                cout << "For every line you buy, you get one free line. since you bought an odd number of lines, you get 1 more." << endl;
                startGame += 1;
            }
            
            else 
            {
                budget -= (startGame / 2);
                if (budget >= 1)
                {
                    cout << "Would you like to play encore? (1$ per game) (y/n)" << endl;
                    cin >> startGame;
                    while (startGame != 'n' && startGame != 'N' && startGame != 'y' && startGame != 'Y') {
                        cout << "please enter either Y or N" << endl;
                        cin >> startGame;
                    }
                    if (startGame == 'y' || startGame == 'Y')
                    {
                        budget -= 1;
                        double totalMoney = 0;

                        /*totalMoney = LotteryGame.playEncore(totalMoney, 1);*/
                        budget += totalMoney;
                        cout << "Total money made from encore: " << totalMoney << "$" << endl;
                    }
                }
                else {
					cout << "You do not have enough money to play encore" << endl;
                }
				
               /* budget = runGame(nums, budget);*/
            }
        } 
        else
        {
            cout << "You're out of money!" << endl;
			cout << "Goodbye!" << endl;
            break; // End game when out of money
        }
    }

}

