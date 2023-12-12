#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
// TODO: Include the other header files you write for the three classes.
#include "Player.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
using namespace std;

void play(Player& player1, Player& player2);
bool checkForWin(Player& player, int answer);
void outputStats(const Player& player1, const Player& player2);

int main()
{
    // TODO: Set the Random Seed!
    srand(static_cast<unsigned int>(time(nullptr)));

    int numPlayers;
    bool validInput = false;
    string inputLine;

    while (!validInput) {
        cout << "Enter the number of human players (0, 1, or 2): ";
        getline(cin, inputLine); // Use getline to read the whole line
        stringstream ss(inputLine); // Use a stringstream for parsing

        if (ss >> numPlayers && !(ss >> inputLine)) { // Check if we got an integer and nothing else
            if (numPlayers >= 0 && numPlayers <= 2) {
                validInput = true; // Input is valid
            } else {
                cout << "Please enter a whole number between 0 and 2." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a whole number." << endl;
        }
    }

    // TODO: Initialize the players
    HumanPlayer h1("Player 1"), h2("Player 2");
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    Player* p1, * p2;

    // Assign player pointers based on the number of human players
    if (numPlayers == 0) {
        p1 = &c1;
        p2 = &c2;
    } else if (numPlayers == 1) {
        p1 = &h1;
        p2 = &c2;

        string name1;
        cout << "Enter name for Player 1: ";
        getline(cin, name1); // Use getline for player name
        h1.setName(name1);
    } else {
        string name1, name2;
        cout << "Enter name for Player 1: ";
        getline(cin, name1); // Use getline for player names
        h1.setName(name1);

        cout << "Enter name for Player 2: ";
        getline(cin, name2); // Use getline for player names
        h2.setName(name2);

        p1 = &h1;
        p2 = &h2;
    }

    char playAgain;
    do {
        play(*p1, *p2);

        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
        while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n') {
            cout << "Please re-enter your answer. (Y/N): ";
            cin >> playAgain;
        }
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << endl;
    outputStats(*p1, *p2);

    cout << "Press enter to exit." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any leftover input
    cin.get();

    return 0;
}

void play(Player& player1, Player& player2)
{
    int answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}

// TODO: Write the function to output game stats (called after the game loop
void outputStats(const Player& player1, const Player& player2) {
    cout << "Final Results:" << endl;
    cout << player1 << endl;
    cout << player2 << endl;

    if (player1 > player2) {
        cout << "Congratulations, " << player1.getName() << "!" << endl;
    } else if (player2 > player1) {
        cout << "Congratulations, " << player2.getName() << "!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
