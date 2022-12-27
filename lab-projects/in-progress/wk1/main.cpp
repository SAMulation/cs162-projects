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
const int WIN_HITS = ROWBOAT_SUNK + KAYAK_SUNK + SKIBOAT_SUNK + YACHT_SUNK;
const int MAX_HITS[] = {WIN_HITS, ROWBOAT_SUNK, KAYAK_SUNK, SKIBOAT_SUNK, YACHT_SUNK}; // Max hits

int rand_num();
void fill_array(int[][MAX]);
void find_spot(int[][MAX], int, int);
void print_board(int[][MAX], int, int, int[]);
char print_ship(int);
void print_array(int[][MAX]);
void apply_shot(int[][MAX], int, int, int[]);
void hit_ship(int, int[]);
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
    int board[MAX][MAX] = {0};
    int last[] = {-1, -1};
    int ships_left = 4;
    int hits[5] = {0}; // Current hits
    int turns = 0;
    bool valid;
    int row, col;
    char again;

    // Start by filling board
    fill_array(board);

    // print_array(board);

    // Initial print board
    print_board(board, MAX, MAX, last);

    do {
        turns++;
        do {
            valid = true;
            row = col = -1;
            cout << "Pick coordinates separated by a space (e.g., '1 2') ";
            do {
                cin >> row >> col;
            } while (row < 1 || row > MAX || col < 1 || col > MAX);

            if (board[row - 1][col - 1] < 0 || board[row - 1][col - 1] > 5) {
                cout << "Invalid choice... Try again!" << endl;
                valid = false;
            }
        } while (!valid);


        last[0] = row - 1;
        last[1] = col - 1;
        print_board(board, MAX, MAX, last);
        apply_shot(board, row - 1, col - 1, hits);
    } while (hits[0] != WIN_HITS);

    cout << "You won in " << turns << " turns!!!" << endl
         << "To play again, type 'y': ";
    cin >> again;

    return again == 'y';
}

void apply_shot(int arr[][MAX], int r, int c, int hits[]) {
    // Miss
    if (arr[r][c] == 0) {
        cout << "Nothing...";
        arr[r][c] = -1;
    }
    else {
        hit_ship(arr[r][c], hits);
        arr[r][c] += 10;
    }

    cout << endl;

    return;
}

void hit_ship(int code, int hits[]) {
    string ship_name;

    cout << "You hit my ";
    if (code == 1)
        ship_name = "rowboat";
    else if (code == 2)
        ship_name = "kayak";
    else if (code == 3)
        ship_name = "skiboat";
    else
        ship_name = "yacht";
    cout << ship_name << "!" << endl;

    hits[code]++;
    hits[0]++; // Increment total

    if (hits[code] == MAX_HITS[code])
        cout << "You sunk my " << ship_name << "!!!" << endl;

    return;
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