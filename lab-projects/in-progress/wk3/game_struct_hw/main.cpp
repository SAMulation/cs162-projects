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
    int current_game;

    Games() : current_game(0) {}

    void set_magic_number()
    {
        magic_number = rand() % 100 + 1;
    }
};

struct Player
{
    int current_guess;
    int guesses[50];

    Player() : current_guess(0) {}

    void set_guess(int g)
    {
        guesses[current_guess] = g;
        current_guess++;
    }

    int last_guess()
    {
        return guesses[current_guess - 1];
    }
};

int get_guess(int);
int found_winner(Player[], Games);
void show_results(Games);
void show_picks(Player[]);

int main()
{
    srand(time(NULL));
    Games game;
    Player players[2];
    int guess;
    int winner;

    do {
        game.set_magic_number();
        game.current_game++;
        cout << "Round " << game.current_game << "!" << endl
             << "Pick numbers until you guess right." << endl
             << MAX << " games total..." << endl << endl;

        do {
            for (int i = 0; i < 2; i++)
            {
                guess = -1;
                guess = get_guess(i);
                players[i].set_guess(guess);
            }

            winner = found_winner(players, game);
        } while (winner != 1 && winner != 2);
    } while (game.current_game < MAX);

    show_results(game);

    cout << "Thanks for playing!" << endl;

    return 0;
}

int get_guess(int p)
{
    int guess = -1;
    cout << "Player " << (p + 1) << " make your guess: ";
    while (guess < 0 || guess > 100)
        cin >> guess;
    return guess;
}

int found_winner(Player p[], Games g) {
    int winner = 0;

    for (int i = 0; i < 2; i++)
    {
        if (p[i].last_guess() == g.magic_number)
            winner = i + 1;
    }

    if (winner != 0)
    {
        g.results[g.current_game] = winner;
        cout << "Player " << (winner) << " won this round!" << endl;
        show_picks(p);
    }
    else
    {
        cout << "Player 1's pick was too " << (p[0].last_guess() < g.magic_number ? "low" : "high") << "!" << endl;
        cout << "Player 2's pick was too " << (p[1].last_guess() < g.magic_number ? "low" : "high") << "!" << endl;
        cout << "Try again!" << endl;
    }

    return winner;
}

void show_results(Games g)
{
    cout << "Final results..." << endl;
    for (int i = 0; i < MAX; i++)
        cout << "Game " << (i + 1) << " Winner: " << g.results << endl;

    return;
}

void show_picks(Player p[])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Player " << i << "'s picks: ";
        for (int j = 0; j < p[i].current_guess; j++)
            cout << p[i].guesses[j] << " ";
        cout << endl;
    }

    return;
}