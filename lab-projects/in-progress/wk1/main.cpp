/*************************
 * Name: Sink Ships
 * Author: Sam Sarsten
 * Date: 12-25-2022
 * Purpose: Battleship clone for CS 162
 * 
 * SHIP (Float,Sunk): rowboat(1,11), kayak(2,12), skiboat(3,13), yacht(4,14)
 * 
**************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX = 9;
const string VALID = "rksyRKSY";

int rand_num();
void print_board(int[][MAX], int, int, int[]);
char print_ship(int);

int main() {
    int board[MAX][MAX] = {0};
    int last[] = {0, 0};
    srand(time(NULL));

    print_board(board, MAX, MAX, last);
    
    return 0;
}

int rand_num() {
    return rand() % MAX;
}

void print_board(int arr[][MAX], int r, int c, int last[]) {
    // last is an array of [last_row, last_col]
    for (int i = 0; i < r; i++) {
        cout << "|";
        for (int j = 0; j < c; j++) {
            char show = ' ';
            // Last hit, show X
            if (i == last[0] && j == last[1])
                show = 'X';
            // It's a ship that's been hit
            else if (arr[i][j] > 10)
                show = print_ship(arr[i][j]);
            // Not a ship, been tried
            else if (arr[i][j] == -1)
                show = '-';
            cout << ' ' << show << " |";
        }
        cout << endl;
    }
}

char print_ship(int x) {
    char c = 'Y';
    if (x == 11)
        c = 'R';
    else if (x == 12)
        c = 'K';
    else if (x == 13)
        c = 'S';

    return c;
}