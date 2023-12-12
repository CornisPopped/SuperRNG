#include "ComputerPlayer.h"
using namespace std;

mt19937 ComputerPlayer::gen(random_device{}()); // Initialize the static RNG

// TODO: Define default ctor
//       Although it seems redundant,
//       Clang-Tidy issues without
//       direct initialization of
//       rngStart and rngRange.
ComputerPlayer::ComputerPlayer() : Player(), rngStart(0), rngRange(100) {
    resetRNG();
}

// TODO: Define custom ctor
ComputerPlayer::ComputerPlayer(const string& name) : Player(), rngStart(0), rngRange(100) {
    // TODO: Initialize RNG range and start values
    setName(name);
    resetRNG();
}

// TODO: Define overridden getGuess method
int ComputerPlayer::getGuess() {
    uniform_int_distribution<> distr(rngStart, rngStart + rngRange - 1);
    return distr(gen);
}


// TODO: Define overridden wrongGuess method
void ComputerPlayer::wrongGuess(int guess, int answer) {
    // TODO: Print if the guess is too high or too low
    //       Call appropriate RNG adjustment methods
    if (guess > answer) {
        cout << "Your guess is too high." << endl;
        adjustRangeDown(guess);
    } else {
        cout << "Your guess is too low." << endl;
        adjustRangeUp(guess);
    }
}

// TODO: Define overridden endRound method
void ComputerPlayer::endRound(bool hasWon) {
    // TODO: reset RNG at end of round
    resetRNG();
    Player::endRound(hasWon);
}

// TODO: Define RNG reset method
void ComputerPlayer::resetRNG() {
    rngStart = 0;
    rngRange = 100;
}

// TODO: Define method to adjust RNG range downwards when guess is too high
void ComputerPlayer::adjustRangeDown(int guess) {
    rngRange = guess - rngStart;
}

// TODO: Define method to adjust RNG range upwards when guess is too low
void ComputerPlayer::adjustRangeUp(int guess) {
    // Adjust rngStart first
    int newStart = guess + 1;

    // Then adjust rngRange to ensure the range does not exceed the original bounds
    int originalEnd = rngStart + rngRange - 1;
    rngStart = newStart;
    rngRange = originalEnd - newStart + 1;

    // Ensure the range does not go beyond the maximum limit (e.g., 99)
    if (rngStart + rngRange - 1 > 99) {
        rngRange = 100 - rngStart;
    }
}