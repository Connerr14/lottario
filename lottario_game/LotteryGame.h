#ifndef LOTTERY_GAME_H
#define LOTTERY_GAME_H

#include <vector>
#include <string>
#include "Ticket.h"
#include "Encore.h"

class LotteryGame {
private:
    double budget;

public:
    //LotteryGame(double initialBudget);
    vector<int> generateWinningNumbers();
    vector<int> generateUserNumbers();
    void playEncore(int budget);
    void displayWinningNumbers(vector<int>) const;
    int howManyNumbersMatch(vector<int> userNums, vector<int> winningNums, int money);
};

#endif
