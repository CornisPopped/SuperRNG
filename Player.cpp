#include "player.h"
using namespace std;

// TODO: Define the Default Ctor (remember to use scope resolution).
Player::Player() : name("Unnamed Player"), numWins(0) {}

// TODO: Define the Mutator/Setter for name member variable.
// Recall that setters are void
void Player::setName(const string& newName) {
    name = newName;
}

// TODO: Define the Accessor/Getter for name member variable.
string Player::getName() const {
    return name;
}

// TODO: Define method for retrieving the guess. Returns 0 because derived classes handle this.
int Player::getGuess() {
    return 0;
}

// TODO: Define method for handling wrong guesses.
void Player::wrongGuess(int guess, int answer) {
    if (guess > answer)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
}

// TODO: Define endRound method, increments once if player has won.
void Player::endRound(bool hasWon) {
    if (hasWon)
    {
        numWins++;
    }
}

// TODO: Define the overloaded '>' binary operator.
bool Player::operator>(const Player &otherPlayer) const {
    return numWins > otherPlayer.numWins;
}

// TODO: Define the overloaded '<<' stream insertion operator.
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player Name: " << player.getName() << ", Wins: " << player.numWins;
    return os;
}
