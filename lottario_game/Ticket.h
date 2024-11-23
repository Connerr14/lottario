#ifndef TICKET_H 
#define TICKET_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ticket { 
public:
	Ticket(vector<int> userNumbers, vector<int> winningNumbers);
	vector<int> userNumbers;
	vector<int> winningNumbers;

	// Getters and setters
	void setUserNumbers(vector<int> userNumbers);
	void setWinningNumbers(vector<int> winningNumbers);
	vector<vector<int>> getUserNumbers();
	vector<int> getWinningNumbers();

	string getCurrentTimestamp();
	void createResultsFile(vector<int> userNums1, vector<int> userNums2, vector<int> winningNums, double amountWon);
	void generateUserTicket(vector<vector<int>> userNumbers, vector<int>winningNumbers)

};
#endif