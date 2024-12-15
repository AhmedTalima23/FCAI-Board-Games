#ifndef TIC_TAC_TOE_5X5_H
#define TIC_TAC_TOE_5X5_H
#include "BoardGame_Classes.h"

template <typename T>
class tic_tac_toe_5x5_Board : public Board<T>
{

public:
    tic_tac_toe_5x5_Board();
    int x_count = 0; // Initialize 'X' count
    int o_count = 0; // Initialize 'O' count
    bool xwin = false;
    bool owin = false;
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool count_wins();
};

template <typename T>
class tic_tac_toe_5x5_Player : public Player<T>
{
public:
    tic_tac_toe_5x5_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class tic_tac_toe_5x5_Random_Player : public RandomPlayer<T>
{
public:
    tic_tac_toe_5x5_Random_Player(T symbol);
    void getmove(int &x, int &y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

using namespace std;

// Constructor for X_O_Board
template <typename T>
tic_tac_toe_5x5_Board<T>::tic_tac_toe_5x5_Board()
{
    this->rows = this->columns = 5;
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
bool tic_tac_toe_5x5_Board<T>::update_board(int x, int y, T mark)
{
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns || (x == 0 && y == 4)) && (this->board[x][y] == 0 || mark == 0))
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
void tic_tac_toe_5x5_Board<T>::display_board()
{
    for (int i = 0; i < this->rows; i++)
    {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
}

// Count wins for 'X' and 'O' after 24 moves
template <typename T>
bool tic_tac_toe_5x5_Board<T>::count_wins()
{
    int x_count = 0; // Initialize 'X' count
    int o_count = 0; // Initialize 'O' count

    // Check horizontal and vertical sequences
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns - 2; j++)
        {
            // Horizontal 3-in-a-row check
            if (this->board[i][j] != 0 && this->board[i][j] == this->board[i][j + 1] && this->board[i][j + 1] == this->board[i][j + 2])
            {
                if (this->board[i][j] == 'X')
                    x_count++;
                else if (this->board[i][j] == 'O')
                    o_count++;
            }
            // Vertical 3-in-a-row check
            if (this->board[j][i] != 0 && this->board[j][i] == this->board[j + 1][i] && this->board[j + 1][i] == this->board[j + 2][i])
            {
                if (this->board[j][i] == 'X')
                    x_count++;
                else if (this->board[j][i] == 'O')
                    o_count++;
            }
        }
    }

    // Check diagonal sequences
    for (int i = 0; i < this->rows - 2; i++)
    {
        for (int j = 0; j < this->columns - 2; j++)
        {
            // Diagonal top-left to bottom-right
            if (this->board[i][j] != 0 && this->board[i][j] == this->board[i + 1][j + 1] && this->board[i + 1][j + 1] == this->board[i + 2][j + 2])
            {
                if (this->board[i][j] == 'X')
                    x_count++;
                else if (this->board[i][j] == 'O')
                    o_count++;
            }
            // Diagonal top-right to bottom-left
            if (this->board[i][j + 2] != 0 && this->board[i][j + 2] == this->board[i + 1][j + 1] && this->board[i + 1][j + 1] == this->board[i + 2][j])
            {
                if (this->board[i][j + 2] == 'X')
                    x_count++;
                else if (this->board[i][j + 2] == 'O')
                    o_count++;
            }
        }
    }
    if (x_count > o_count)
    {
        xwin = true;
    }
    else if (o_count > x_count)
    {
        owin = true;
    }

    // Return true if there is a winner (X or O)
    return x_count > o_count || o_count > x_count;
}

template <typename T>
bool tic_tac_toe_5x5_Board<T>::is_win()
{
    // Only check for a winner after 24 moves
    if (this->n_moves == 24)
    {
        return count_wins();
    }
    return false;
}

// Return true if 24 moves are done and no winner
template <typename T>
bool tic_tac_toe_5x5_Board<T>::is_draw()
{
    return (this->n_moves == 24 && !is_win());
}

template <typename T>
bool tic_tac_toe_5x5_Board<T>::game_is_over()
{
    return (this->n_moves == 24);
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
tic_tac_toe_5x5_Player<T>::tic_tac_toe_5x5_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void tic_tac_toe_5x5_Player<T>::getmove(int &x, int &y)
{
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for X_O_Random_Player
template <typename T>
tic_tac_toe_5x5_Random_Player<T>::tic_tac_toe_5x5_Random_Player(T symbol) : RandomPlayer<T>(symbol)
{
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

template <typename T>
void tic_tac_toe_5x5_Random_Player<T>::getmove(int &x, int &y)
{
    do
    {
        x = rand() % 5; // Random row between 0 and 4
        y = rand() % 5; // Random column between 0 and 4
    } while ((x == 0 && y == 4)); // Exclude (0, 4) and ensure spot is empty
}

#endif // TIC_TAC_TOE_5X5_H
