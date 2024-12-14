#ifndef PYRAMID_H
#define PYRAMID_H
#include "BoardGame_Classes.h"

template <typename T>
class pyramid_Board : public Board<T>
{
public:
    pyramid_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class pyramid_Player : public Player<T>
{
public:
    pyramid_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class pyramid_Random_Player : public RandomPlayer<T>
{
public:
    pyramid_Random_Player(T symbol);
    void getmove(int &x, int &y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

using namespace std;

// Constructor for pyramid_Board
template <typename T>
pyramid_Board<T>::pyramid_Board()
{
    this->rows = 3;
    this->columns = 5;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool pyramid_Board<T>::update_board(int x, int y, T mark)
{
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns || ( x == 0 && y == 0) ||
                   (x == 0 && y == 1)|| (x == 0 && y == 3)|| (x == 0 && y == 4)|| (x == 1 && y == 0)|| (x == 1 && y == 4)) && (this->board[x][y] == 0 || mark == 0))
    {
        if (mark == 0)
        {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else
        {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void pyramid_Board<T>::display_board()
{
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++)
        {
            if ((i == 0 && j ==0) ||(i == 0 && j ==1) ||(i == 0 && j ==3) ||(i == 0 && j ==4) ||(i == 1 && j ==0) ||(i == 1 && j ==4) ){
                cout <<setw(5) << " " << " |";
            }
            else{
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << "|";
        }
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool pyramid_Board<T>::is_win()
{

    // Check diagonals
    if ((this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0) ||
        (this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4] && this->board[0][2] != 0))
    {

        return true;
    }
    // check columns
    if ((this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[0][2] != 0)){

        return true;
    }

    // check rows
    if((this->board[1][1] == this->board[1][2] && this->board[1][2] == this->board[1][3] && this->board[1][1] != 0) ||
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) ||
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 0) ||
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0)){

            return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool pyramid_Board<T>::is_draw()
{
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool pyramid_Board<T>::game_is_over()
{
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for pyramid_Player
template <typename T>
pyramid_Player<T>::pyramid_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void pyramid_Player<T>::getmove(int &x, int &y)
{
    cout << "\nPlease enter your move x (0 to 2) and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for pyramid_Random_Player
template <typename T>
pyramid_Random_Player<T>::pyramid_Random_Player(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 3  ;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

template <typename T>
void pyramid_Random_Player<T>::getmove(int &x, int &y)
{
    do
    {
        x = rand() % 3; // Random number between 0 and 2
        y = rand() % 5; // Random number between 0 and 4
    } while ((x == 0 && (y < 2 || y > 2)) || (x == 1 && (y == 0 || y == 4)));
}



#endif // PYRAMID_H
