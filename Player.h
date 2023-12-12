#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    // Default constructor
    Player();

    // Mutator/Setter for the name member variable
    // Uses 'const' reference parameter
    // to avoid copying the string and ensures the setter won't change
    // the original value of the string variable.
    void setName(const string& newName);

    // Accessor/Getter for the name member variable
    // Marked 'const' because it is
    // good practice for accessor/getter methods to not modify the object's state.
    string getName() const;

    // Method to handle getting the guess for the game
    // Marked virtual to allow derived classes to override it.
    // Returns int because it is a random number game.
    virtual int getGuess();

    // Method to handle wrong guesses.
    // Takes the guess as an int
    // parameter and reports if "Your guess is too high" or "Your guess is too low."
    virtual void wrongGuess(int guess, int answer);

    // Method 'endRound' which takes a bool argument.
    // If true, the user has won. Increments wins by 1.
    // Virtual because ComputerPlayer.h modifies it
    virtual void endRound(bool hasWon);

    // Overloaded operator '>' to compare the number of wins between players.
    bool operator>(const Player& otherPlayer) const;

    // Overloaded operator '<<' to output name of player and their number of wins.
    // Declare friend function for the overloaded operator '<<'
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    // Member variable for the number of wins the player has achieved
    int numWins;

private:
    // Member variable for the player's name
    string name = "n";

};

#endif // PLAYER_H
