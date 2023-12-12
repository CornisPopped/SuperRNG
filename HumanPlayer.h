// Include Header Guards
// Derive class for Human Players

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "Player.h"
using namespace std;

//
class HumanPlayer : public Player {
public:
    // Declare Default Ctor
    HumanPlayer();
    // Declare Custom Ctor
    // 'explicit' for constructor with one argument to avoid implicit conversions
    explicit HumanPlayer(const string& name);

    // New version of getGuess that reads in an integer
    // if the integer is not between 0-99 (inclusive),
    // the user will be prompted to enter the guess again.
    // The guess will be returned.
    int getGuess() override;
};

#endif // HUMANPLAYER_H