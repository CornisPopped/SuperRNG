// Derived class for CPU

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include <iostream>
#include <string>
#include <random>
#include "Player.h"
using namespace std;

class ComputerPlayer : public Player {
public:
    // Declare default ctor
    ComputerPlayer();

    // Declare custom ctor that takes CPU name as a parameter
    explicit ComputerPlayer(const string& name);

    // Declare overridden getGuess method
    int getGuess() override;

    // Declare overridden wrongGuess method
    void wrongGuess(int guess, int answer) override;

    // Declare overridden endRound method
    void endRound(bool hasWon) override;

    // Declare resetRNG method
    void resetRNG();

    // Declare method to adjust RNG range downwards when guess is too high
    void adjustRangeDown(int guess);

    // Declare method to adjust RNG range upwards when the guess is too low
    void adjustRangeUp(int guess);

private:
    // Declare private member variables for RNG range
    int rngStart;
    int rngRange;
    static mt19937 gen; // Static RNG
};

#endif // COMPUTERPLAYER_H