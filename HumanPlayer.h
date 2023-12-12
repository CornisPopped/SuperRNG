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
    // TODO: Declare Default Ctor
    HumanPlayer();
    // TODO: Declare Custom Ctor
    // 'explicit' for constructor with one argument to avoid implicit conversions
    explicit HumanPlayer(const string& name);

    // TODO: New version of getGuess that reads in an integer
    //       if the integer is not between 0-99 (inclusive),
    //       the user will be prompted to enter the guess again.
    //       The guess will be returned.
    int getGuess() override;                    // TODO: Declare the virtual getGuess()
};

#endif // HUMANPLAYER_H