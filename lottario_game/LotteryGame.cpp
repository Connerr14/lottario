#include "LotteryGame.h"
#include "Encore.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <vector>

//LotteryGame::LotteryGame(double initialBudget) : budget(initialBudget) {}

std::vector<int> LotteryGame::generateWinningNumbers() {
    std::vector<int> winningNumbers;

    while (winningNumbers.size() < 7) {
        int newNum = (rand() % 45) + 1;
        if (std::find(winningNumbers.begin(), winningNumbers.end(), newNum) == winningNumbers.end()) {
            winningNumbers.push_back(newNum);
        }
    }
    return winningNumbers;
}

std::vector<int> LotteryGame::generateUserNumbers() {
    std::vector<int> userNumbers;

    while (userNumbers.size() < 7) {
        int newNum = (rand() % 45) + 1;
        if (std::find(userNumbers.begin(), userNumbers.end(), newNum) == userNumbers.end()) {
            userNumbers.push_back(newNum);
        }
    }
    return userNumbers;
}

void LotteryGame::playEncore(int budget) {
    int money = 0;
    Encore encore;

    // Get the winning numbers for encore
    vector<int> encoreWinningNumbers = encore.GenerateWinningNumbersForEncore();

	// Get the user numbers for encore
    std::vector<int> encoreUserNumbers = encore.GenerateUserNumbersForEncore();

    //Display winning numbers
    std::cout << "Encore Winning Numbers: ";
    for (size_t i = 0; i < encoreWinningNumbers.size(); i++) {
        int num = encoreWinningNumbers[i];
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Calculate left and right matches
    std::vector<int> matches = encore.howManyNumbersMatchInEncore(encoreUserNumbers, encoreWinningNumbers);

    // Output match results
    std::cout << "Encore Matches: Left " << matches[0] << ", Right " << matches[1] << std::endl;

    // Calculate prizes for matches
    money += encore.CalculatePrizeForEncore(matches[0], matches[1], 0);

    budget += money;

}

void LotteryGame::displayWinningNumbers(vector<int> winningNumbers) const {
    std::cout << "Winning Numbers: ";
    for (size_t i = 0; i < winningNumbers.size(); i++) {
        int num = winningNumbers[i];
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void LotteryGame::howManyNumbersMatch(vector<int> userNums, vector<int> winningNums, int money, int& moneyMadeFromMainGame) {
    // Check if any of the user numbers match the winning numbers
	double count = 0;
	int bonusNumber = winningNums[6];

        // first check if there is a bonus number
	    for (int k = 0; k <= 5; k++) {
		    if (userNums[k] == bonusNumber) {
			    count += 0.5;
                break;
		    }
        }
		// Check main numbers (order does not matter)
		for (int i = 0; i <= 5; i++) {
			for (int j = 0; j <= 5; j++) {
				if (userNums[i] == winningNums[j]) {
					count++;
				}
			}
		}

		
    // If else statements to determine prize and adjust budget
    if (matches >= 6){
        cout << "$250,000.00 Jackpot won" << endl;
        money += 250000;
    } else if (matches >= 5.5){
        cout << "You matched 5/6 numbers and matched the bonus number. $10,000.00 won" << endl;
        money += 10000;
    } else if (matches >= 5){
        cout << "You matched 5/6 numbers. $500.00 won" << endl;
        money += 500;
    } else if (matches >= 4.5){
        cout << "You matched 4/6 numbers and matched the bonus number. $30.00 won" << endl;
        money += 30;
    } else if (matches >= 4) {
        cout << "You matched 4/6 numbers. $10.00 won" << endl;
        money += 10;
    } else if (matches >= 3.5) {
        cout << "You matched 3/6 numbers and matched the bonus number. $5.00 won" << endl;
        money += 5;
    } else if (matches >= 3) {
        cout << "You matched 3/6 numbers. $4.00 won" << endl;
        money += 4;
    } else if (matches == 0.5) // Checking if bonus was won without any other prizes
    {
        cout << "Bonus play won!" << endl;
		// Re run the game
        vector<int> bonusPlay = getAllLines(1, winningNums, money);
        money += bonusMoney
    } else {
        cout << "You lost. Try again next time" << endl;
    }

    return money;
}