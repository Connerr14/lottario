// Including the external libraiers needed
#include <vector>
#include <iostream>

// Including the header file
#include "Encore.h"

using namespace std;

// Need to refactor the digit size of the nums
vector<int> Encore::GenerateWinningNumbersForEncore() {
	vector<int> randomNums;

	for (int i = 0; i < 7; i++) {
		// Get a new random number
		int newNum = ((rand() % 9) + 1);

		// Iterate through the vector to check if the number is already in the vector
		for (int j = 0; j < randomNums.size(); j++) {
			if (newNum == randomNums[j]) {
				// If it is, get a new number
				newNum = ((rand() % 45) + 1);

				// Reset the loop to check the new number
				j = 0;
			}
		}
		randomNums.push_back(newNum);
	}
	return randomNums;
}

// Generage 7 digits of numbers (0-9)
vector<int> Encore::GenerateUserNumbersForEncore() {
	vector <int> userNums;

	for (int i = 0; i < 6; i++) {
		// Get a new random number
		int newNum = ((rand() % 9) + 1);

		// Iterate through the vector to check if the number is already in the vector
		for (int j = 0; j < userNums.size(); j++) {
			if (newNum == userNums[j]) {
				// If it is, get a new number
				newNum = ((rand() % 45) + 1);

				// Reset the loop to check the new number
				j = 0;
			}
		}

		// Add the new number to the vector
		userNums.push_back(newNum);
	}

	return userNums;
}

vector<int> Encore::howManyNumbersMatchInEncore(vector<int> userNums, vector<int> winningNums) {
	int leftMatches = 0;
	int rightMatches = 0;
	vector<int> highestMatches;

	// Count matches from the left
	for (int i = 0; i < 7; i++) {
		if (userNums[i] == winningNums[i]) {
			leftMatches++;
		}
		else {
			break; // Stop counting as soon as a mismatch occurs
		}
	}

	// Count matches from the right
	for (int i = 6; i >= 0; i--) {
		if (userNums[i] == winningNums[i]) {
			rightMatches++;
		}
		else {
			break; // Stop counting as soon as a mismatch occurs
		}
	}

	highestMatches.push_back(leftMatches);
	highestMatches.push_back(rightMatches);
	return highestMatches;
}

double Encore::CalculatePrizeForEncore(int leftMatches, int rightMatches, int money) {
    // Check right-to-left matches first
    if (leftMatches == 0 || rightMatches == 0) {
        if (rightMatches == 7) {
            std::cout << "Encore Jackpot won! (All 7 digits matched)" << std::endl;
            money += 1000000;
        }
        else if (rightMatches == 6) {
            std::cout << "$100,000 prize won (Last 6 digits matched)" << std::endl;
            money += 100000;
        }
        else if (rightMatches == 5) {
            std::cout << "$1,000 prize won (Last 5 digits matched)" << std::endl;
            money += 1000;
        }
        else if (rightMatches == 4) {
            std::cout << "$100 prize won (Last 4 digits matched)" << std::endl;
            money += 100;
        }
        else if (rightMatches == 3) {
            std::cout << "$10 prize won (Last 3 digits matched)" << std::endl;
            money += 10;
        }
        else if (rightMatches == 2) {
            std::cout << "$5 prize won (Last 2 digits matched)" << std::endl;
            money += 5;
        }
        else if (rightMatches == 1) {
            std::cout << "$2 prize won (Last digit matched)" << std::endl;
            money += 2;
        }
        // If no prize from right-to-left matches, check left-to-right matches
        else if (leftMatches == 6) {
            std::cout << "$10,000 prize won (First 6 digits matched)" << std::endl;
            money += 10000;
        }
        else if (leftMatches == 5) {
            std::cout << "$500 prize won (First 5 digits matched)" << std::endl;
            money += 500;
        }
        else if (leftMatches == 4) {
            std::cout << "$50 prize won (First 4 digits matched)" << std::endl;
            money += 50;
        }
        else if (leftMatches == 3) {
            std::cout << "$10 prize won (First 3 digits matched)" << std::endl;
            money += 10;
        }
        else if (leftMatches == 2) {
            std::cout << "$5 prize won (First 2 digits matched)" << std::endl;
            money += 5;
        }
        else {
            std::cout << "Encore lost!" << std::endl;
        }
    }
    else {
        if (leftMatches >= 5 && rightMatches >= 1) {
            std::cout << "$502 prize for matching first 5 digits and last digit" << endl;
            money += 502;
        }
        else if (leftMatches >= 4 && rightMatches >= 2) {
            std::cout << "$55 prize for matching first 4 digits and last 2 digits" << endl;
            money += 55;
        }
        else if (leftMatches >= 4 && rightMatches >= 1) {
            std::cout << "$52 prize for matching first 4 digits and last digit" << endl;
            money += 52;
        }
        else if (leftMatches >= 3 && rightMatches >= 3) {
            std::cout << "$20 prize for matching first 3 digits and last 3 digits" << endl;
            money += 20;
        }
        else if (leftMatches >= 3 && rightMatches >= 2) {
            std::cout << "$15 prize for matching first 3 digits and last 2 digits" << endl;
            money += 15;
        }
        else if (leftMatches >= 3 && rightMatches >= 1) {
            std::cout << "$12 prize for matching first 3 digits and last digit" << endl;
            money += 12;
        }
        else if (leftMatches >= 2 && rightMatches >= 4) {
            std::cout << "$105 prize for matching first 2 digits and last 4 digits" << endl;
            money += 105;
        }
        else if (leftMatches >= 2 && rightMatches >= 3) {
            std::cout << "$15 prize for matching first 2 digits and last 3 digits" << endl;
            money += 15;
        }
        else if (leftMatches >= 2 && rightMatches >= 2) {
            std::cout << "$10 prize for matching first 2 digits and last 2 digits" << endl;
            money += 10;
        }
        else if (leftMatches >= 2 && rightMatches >= 1) {
            std::cout << "$7 prize for matching first 2 digits and last digit" << endl;
            money += 7;
        }
        else {
            std::cout << "No prize won" << endl;
        }
    }
    return money;
}

