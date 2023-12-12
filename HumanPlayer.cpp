#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer() : Player() {}

HumanPlayer::HumanPlayer(const string& name) {
    setName(name); // Uses setName from base class
}

int HumanPlayer::getGuess() {
    int guess;
    bool validInput = false;
    string inputLine;

    while (!validInput) {
        cout << "Enter a guess between 0 and 99: ";
        getline(cin, inputLine); // Use getline to read the whole line
        stringstream ss(inputLine); // Use a stringstream for parsing

        if (ss >> guess && ss.eof()) { // Check if we got an integer and nothing else
            if (guess >= 0 && guess <= 99) {
                validInput = true; // Input is valid
            } else {
                cout << "Invalid guess. Please enter a number between 0 and 99." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a whole number." << endl;
        }
    }
    return guess;
}
