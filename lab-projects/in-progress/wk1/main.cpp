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
const int ROWBOAT_NUM = 1;
const int KAYAK_NUM = 2;
const int SKIBOAT_NUM = 3;
const int YACHT_NUM = 4;
const int ROWBOAT_SUNK = 2;
const int KAYAK_SUNK = 3;
const int SKIBOAT_SUNK = 4;
const int YACHT_SUNK = 5;

int rand_num();
void fill_array(int[][MAX]);
void find_spot(int[][MAX], int, int);
void print_board(int[][MAX], int, int, int[]);
char print_ship(int);
void print_array(int[][MAX]);
bool game_logic();

int main() {
    bool again = true;
    srand(time(NULL));

    do {
        again = game_logic();
    } while (again);
    
    return 0;
}

bool game_logic() {
    const int WIN_HITS = ROWBOAT_SUNK + KAYAK_SUNK + SKIBOAT_SUNK + YACHT_SUNK;
    const int MAX_HITS[] = {WIN_HITS, ROWBOAT_SUNK, KAYAK_SUNK, SKIBOAT_SUNK, YACHT_SUNK}; // Max hits
    int board[MAX][MAX] = {0};
    int last[] = {-1, -1};
    int ships_left = 4;
    int hits[5] = {0}; // Current hits
    int turns = 0;

    // Start by filling board
    fill_array(board);

    // Initial print board
    print_board(board, MAX, MAX, last);

    do {
        turns++;
        print_board(board, MAX, MAX, last);
    } while (hits[0] != WIN_HITS);

    // print_board(board, MAX, MAX, last);

    // print_array(board);




}

int rand_num() {
    return rand() % MAX;
}

void fill_array(int arr[][MAX]) {
    find_spot(arr, ROWBOAT_NUM, ROWBOAT_SUNK); // rowboat
    find_spot(arr, KAYAK_NUM, KAYAK_SUNK); // kayak
    find_spot(arr, SKIBOAT_NUM, SKIBOAT_SUNK); // skiboat
    find_spot(arr, YACHT_NUM, YACHT_SUNK); // yacht
    return;
}

void find_spot(int arr[][MAX], int code, int size) {
    bool valid;
    int flip; // 0 (right) or 1 (down)
    int r; // Starting row
    int c; // Starting column
    int start;

    // Test ship placement
    do {
        valid = true;
        flip = rand() % 2;
        r = rand_num(); // Starting row
        c = rand_num(); // Starting column
        
        if (flip == 1)
            start = r;
        else
            start = c;

        for (int i = start; i < start + size && valid; i++) {
            if (i > size)
                valid = false;
            // Something is there
            if (valid && (flip == 1 && arr[i][c] != 0) || (flip == 0 && arr[r][i]))
                valid = false;
            // else: keep checking
        }

        // cout << "code: " << code << " start: " << start << " flip: " << flip << " valid: " << valid << " size: " << size << endl;
    } while (!valid);

    // Actually place ship
    for (int i = start; i < start + size; i++)
        if (flip == 1)
            arr[i][c] = code;
        else
            arr[r][i] = code;

    return;
}


void print_board(int arr[][MAX], int r, int c, int last[]) {
    // last is an array of [last_row, last_col]
    for (int i = 0; i <= r; i++) {
        if (i != r)
            cout << (i + 1) << " |";
        else
            cout << "  |";

        for (int j = 0; j < c; j++) {
            char show = ' ';
            // Last row, display columns
            if (i == r)
                cout << ' ' << (j + 1) << " |";
            else {
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
        }
        cout << endl;
    }
    return;
}

char print_ship(int x) {
    char c = 'Y'; // Defaulting to yacht
    if (x == ROWBOAT_NUM + 10)
        c = 'R';
    else if (x == KAYAK_NUM + 10)
        c = 'K';
    else if (x == SKIBOAT_NUM + 10)
        c = 'S';

    return c;
}

void print_array(int arr[][MAX]) {
    for (int i = 0; i < MAX; i++) {
        cout << '|';
        for (int j = 0; j< MAX; j++)
            cout << arr[i][j] << '|';
        cout << endl;
    }
    return;
}