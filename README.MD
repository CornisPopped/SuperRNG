# SuperRNG Guessing Game

## Overview
This Guessing Game is a console-based application developed in C++. 
It allows players to guess a randomly generated number between 0 and 99. 
The game can be played with either human players, computer players, or a mix of both.

## Features
- Support for 0, 1, or 2 human players.
- Computer players with basic AI for guessing numbers.
- Input validation for player names and guesses.
- Replayability: option to play multiple rounds.
- End-of-game statistics display.

## Requirements
- C++ compiler (GCC, Clang, MSVC, etc.)
- Standard C++ libraries

## Compilation and Running
To compile and run the game, use the following commands (assuming `g++` is the compiler):

```bash
g++ -o GuessingGame main.cpp HumanPlayer.cpp ComputerPlayer.cpp Player.cpp
./GuessingGame
