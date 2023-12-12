#include "ComputerPlayer.h"
using namespace std;

mt19937 ComputerPlayer::gen(random_device{}()); // Initialize the static RNG

// Define default ctor
// Although it seems redundant,
// Clang-Tidy issues without
// direct initialization of
// rngStart and rngRange.
ComputerPlayer::ComputerPlayer() : Player(), rngStart(0), rngRange(100) {
    resetRNG();
}

// Define custom ctor
ComputerPlayer::ComputerPlayer(const string& name) : Player(), rngStart(0), rngRange(100) {
    // Initialize RNG range and start values
    setName(name);
    resetRNG();
}

// Define overridden getGuess method
int ComputerPlayer::getGuess() {
    uniform_int_distribution<> distr(rngStart, rngStart + rngRange - 1);
    return distr(gen);
}


// Define overridden wrongGuess method
void ComputerPlayer::wrongGuess(int guess, int answer) {
    // Print if the guess is too high or too low
    // Call appropriate RNG adjustment methods
    if (guess > answer) {
        cout << "Your guess is too high." << endl;
        adjustRangeDown(guess);
    } else {
        cout << "Your guess is too low." << endl;
        adjustRangeUp(guess);
    }
}

// Define overridden endRound method
void ComputerPlayer::endRound(bool hasWon) {
    // reset RNG at end of round
    resetRNG();
    Player::endRound(hasWon);
}

// Define RNG reset method
void ComputerPlayer::resetRNG() {
    rngStart = 0;
    rngRange = 100;
}

// Define method to adjust RNG range downwards when guess is too high
void ComputerPlayer::adjustRangeDown(int guess) {
    rngRange = guess - rngStart;
}

// Define method to adjust RNG range upwards when guess is too low
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