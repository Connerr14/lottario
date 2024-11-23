#include "Ticket.h"
#include "LotteryGame.h"

#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

// The Class Constructor
Ticket::Ticket(vector<int> userNumbers, vector<int> winningNumbers) {
	setUserNumbers(userNumbers);
	setWinningNumbers(winningNumbers);
}

void Ticket::setUserNumbers(vector<int> userNumbers) {
	if (userNumbers.size() != 7) {
		throw "Error! Invalid number of user numbers";
		return;
	}
	else {
		this->userNumbers = userNumbers;
	}

}


void Ticket::setWinningNumbers(vector<int> winningNumbers) {
	if (winningNumbers.size() != 7) {
		throw "Error! Invalid number of winning numbers";
		return;
	}
	else {
		this->winningNumbers = winningNumbers;
	}
}

vector<int> Ticket::getUserNumbers() {
    return userNumbers;
}

vector<int> Ticket::getWinningNumbers() {
    
	return winningNumbers;
}


string Ticket::getCurrentTimestamp() {
	// Get the current time in epoch format
	auto now = std::chrono::system_clock::now();

	// Convert the time to a time_t object (witch represents calendar time)
	std::time_t timeT = std::chrono::system_clock::to_time_t(now);

	// Convert the time_t object to a tm struct and breaks down the time into its components 
	std::tm tmStruct;
	localtime_s(&tmStruct, &timeT);

	//Set up an output stream to build a formatted string with a struct
	std::ostringstream oss;

	// Convert the tm struct to a string with the following format
	oss << std::put_time(&tmStruct, "%Y-%m-%d-%H-%M-%S"); // Format: YYYY-MM-DD-HH-MM-SS

	// Converts the output stream to a string and returns it
	return oss.str();
}

void Ticket::createResultsFile(vector<int> userTicketNumbers, vector<int> winningNums, int amountWonFromMainGame, int amountWonFromEncore) {
    // Get the current timestamp in a string format
    string time = getCurrentTimestamp();

    // Replace spaces and colons with dashes for a filename-safe format
    for (auto& ch : time) {
        if (ch == ' ' || ch == ':') ch = '-';
    }

    string fileName = "results" + time + ".txt";

    // Open the file
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cout << "Error: Could not open file for writing." << endl;
        return;
    }

    // Write header and formatted numbers
    outFile << "===================\n";
    outFile << "  LOTTARIO\n";
    outFile << "===================\n";
    outFile << "Winning Numbers: ";

    for (int i = 0; i < winningNums.size(); i++) {
        outFile << setw(2) << winningNums[i];
        if (i < winningNums.size() - 1) outFile << " - ";
    }

    outFile << "\n===================\n";
    outFile << "Your numbers: ";

	// Go through the full array of user numbers and write them to the file
    // Print the ticket lines in pairs
    int counter = 0;
    for (int i = 0; i < userTicketNumbers.size(); i++) {
        if (counter < 2)
        {   
            outFile << setw(2) << userTicketNumbers[i];
            counter++;
        }
        else {
            counter = 0;
            outFile << "\n===================\n";
            outFile << "Your numbers: ";
            outFile << setw(2) << userTicketNumbers[i];

        }
		
	}

	// Write the amount won from the main game and encore game to the file
   outFile << "\n===================\n";
   outFile << "Amount won from the main game: " << amountWonFromMainGame << endl;
   outFile << "Amount won from the encore game: " << amountWonFromEncore << endl;
   outFile << "Total amount won: " << amountWonFromMainGame + amountWonFromEncore << endl;

   outFile.close();
}

void Ticket::generateUserTicket(vector<vector<int>>userNumbers, vector<int>winningNumbers) {
    // Open the file
    ofstream output_file;

    string time = getCurrentTimestamp();

    // Replace spaces and colons with dashes for a filename-safe format
    for (auto& ch : time) {
        if (ch == ' ' || ch == ':') ch = '-';
    }


    // Add time number to the file name to make it unique
    string fileName = "lotteryTicket" + time + ".txt";

    std::ofstream outFile(fileName);


    output_file.open(fileName, ios::app);


    if (output_file.is_open()) {

        output_file << "===================\n";
        output_file << "  LOTTARIO\n";
        output_file << "===================\n";
        output_file << "Your Ticket Numbers: " << endl;

        // Write user ticket numbers (each ticket has two lines)
        for (size_t i = 0; i < userNumbers.size(); i += 2) {
            output_file << "Ticket " << (i / 2) + 1 << ":\n";

            // Print the first line of the ticket
            for (size_t j = 0; j < userNumbers[i].size(); j++) {
                output_file << userNumbers[i][j] << " ";
            }
            output_file << "\n";

            // Print the second line of the ticket
            for (size_t j = 0; j < userNumbers[i + 1].size(); j++) {
                output_file << userNumbers[i + 1][j] << " ";
            }
            output_file << "===================\n\n";
        }

        //Print winning numbers
        output_file << "Winning numbers: \n" << endl;

        for (int i = 0; i < winningNumbers.size(); i++) {
            output_file << winningNumbers[i] << " ";
        }
        output_file << endl;

    } else if (output_file.fail()) {
        cout << "Error opening file" << endl;
    }

    output_file.close();

}