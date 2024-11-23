#ifndef ENCORE_H
#define ENCORE_H

#include <vector>
using namespace std;

class Encore
{
	public:
		std::vector<int> GenerateWinningNumbersForEncore();
		std::vector<int> GenerateUserNumbersForEncore();
		std::vector<int> howManyNumbersMatchInEncore(std::vector<int> userNums, std::vector<int> winningNums);

		// Need to create this function
		double CalculatePrizeForEncore(int leftMatches, int rightMatches, int money);

};
#endif