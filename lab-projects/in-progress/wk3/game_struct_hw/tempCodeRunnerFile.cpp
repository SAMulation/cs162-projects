// Write a program to create objects that can be used in a game. You are free to be creative about 
// what objects you create and how they are used, but your program MUST contain the following: 
// • at least 2 defined structures, each with at least 2 member variables 
// • at least one array that is a member of one of the structures 
// • an array of each structure used in the program 

/*************************
 * Name: Fraction Struct
 * Author: Sam Sarsten
 * Date: 01-08-2022
 * Purpose: Implementing Fraction struct using C++
**************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 3;
struct Games
{
    int results[MAX];
    int magic_number;
    int current_game = 0;

    void set_magic_number()
    {
        magic_number = rand() % 100 + 1;
    }
};

struct Player
{
    int current_guess = 0;
    int guesses[50];

    void set_guess(int g)
    {
        guesses[current_guess] = g;
        current_guess++;
    }

    int last_guess()
    {
        return guesses[current_guess - 1];
    }
}

int get_guess(int);
int found_winner(Player[], Games);

int main()
{
    srand(time(NULL));
    Games game;
    Player players[2];
    int guess;

    do {
        game.set_magic_number();
        game.current_game++;

        do {
            for (int i = 0; i < 2; i++)
            {
                guess = -1;
                guess = get_guess(i);
                players[i].set_guess(guess);
            }


        } while (found_winner() != 1 && found_winner() !=2);
    } while (game.current_game < MAX);

    cout << "Thanks for using..." << endl;

    return 0;
}

int get_guess(int p)
{
    int guess = -1;
    cout << "Player " << p << " make your guess: ";
    while (guess < 0 || guess > 100)
        cin >> guess;
    return guess;
}

int found_winner(Player p[], Games g) {
    int winner = 0;

    for (int i = 0; i < 2; i++)
    {
        if (p[0].last_guess() == g.magic_number)
            winner = i + 1;
    }

    if (winner != 0)
        g.results[g.current_game] = winner;

    return winner;
}