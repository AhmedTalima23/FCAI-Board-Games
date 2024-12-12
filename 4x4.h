#ifndef _4X4_XO_H
#define _4X4_XO_H

#include "BoardGame_Classes.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// Template class for 4x4 Tic-Tac-Toe board
template <typename T>
class TicTacToeBoard : public Board<T>
{
public:
    TicTacToeBoard();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;

    bool is_valid_move(int x, int y);
    int to_x;
    int to_y;
};

template <typename T>
bool TicTacToeBoard<T>::is_valid_move(int x, int y)
{
    return (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == ' ');
}

template <typename T>
bool TicTacToeBoard<T>::game_is_over()
{
    return is_win();
}

template <typename T>
bool TicTacToeBoard<T>::is_draw()
{
    return this->n_moves == 100; // All spaces are filled
}

template <typename T>
bool TicTacToeBoard<T>::is_win()
{
    // Check rows for 4 consecutive symbols
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 0; j++) // Adjusted for a 4x4 board
        {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2])
                return true;
        }
    }

    // Check columns for 4 consecutive symbols
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i <= 0; i++) // Adjusted for a 4x4 board
        {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j])
                return true;
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i <= 0; i++)
    {
        if (this->board[i][i] != ' ' &&
            this->board[i][i] == this->board[i + 1][i + 1] &&
            this->board[i][i] == this->board[i + 2][i + 2])
            return true;

        if (this->board[i][3 - i] != ' ' &&
            this->board[i][3 - i] == this->board[i + 1][2 - i] &&
            this->board[i][3 - i] == this->board[i + 2][1 - i])
            return true;
    }

    return false;
}

template <typename T>
void TicTacToeBoard<T>::display_board()
{
    // Print column numbers
    cout << "    1   2   3   4" << endl;

    for (int i = 0; i < this->rows; i++)
    {
        // Print the row number
        cout << "  +---+---+---+---+" << endl;
        cout << i + 1 << " "; // Adjust row number to start from 1

        // Loop through columns and print the contents of each cell with borders
        for (int j = 0; j < this->columns; j++)
        {
            cout << "| " << (this->board[i][j] == 0 ? ' ' : this->board[i][j]) << " ";
        }

        cout << "|" << endl;
    }

    // Print the bottom border of the board
    cout << "  +---+---+---+---+" << endl;
}

template <typename T>
bool TicTacToeBoard<T>::update_board(int x, int y, T symbol)
{
    // Convert to 0-indexed
    x--;
    y--;

    // Ensure the selected token belongs to the player and is valid
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == symbol)
    {
        cout << "Enter the new position you want to move to (row and column): ";
        cin >> to_x >> to_y;

        // Convert the destination to 0-indexed
        to_x--;
        to_y--;

        // Validate the destination position
        if (is_valid_move(to_x, to_y))
        {
            // Move the token
            this->board[to_x][to_y] = symbol;
            this->board[x][y] = ' '; // Clear the original position
            this->n_moves++;         // Increment the move count
            return true;
        }
        else
        {
            cout << "Invalid move. Destination is either out of bounds or occupied." << endl;
        }
    }
    else
    {
        cout << "Invalid token selection. Choose a valid token that belongs to you." << endl;
    }

    return false;
}

template <typename T>
TicTacToeBoard<T>::TicTacToeBoard()
{
    this->rows = 4;
    this->columns = 4;
    this->board = new T *[this->rows];

    // Initialize the board with empty cells
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = ' '; // Initialize all cells as empty
        }
    }

    // Manually set the starting positions for the tokens
    this->board[0][0] = 'O';
    this->board[0][1] = 'X';
    this->board[0][2] = 'O';
    this->board[0][3] = 'X';
    this->board[3][0] = 'X';
    this->board[3][1] = 'O';
    this->board[3][2] = 'X';
    this->board[3][3] = 'O';

    this->n_moves = 0; // Initialize the number of moves
}

// Player class for Tic-Tac-Toe
template <typename T>
class TicTacToePlayer : public Player<T>
{
public:
    TicTacToePlayer(string name, T symbol);
    void getmove(int &x, int &y) override;
};

template <typename T>
void TicTacToePlayer<T>::getmove(int &x, int &y)
{
    cout << "enter the position do you want move it ( row and column ) " << endl;
    cin >> x >> y;
}

template <typename T>
TicTacToePlayer<T>::TicTacToePlayer(string name, T symbol) : Player<T>(name, symbol) {}

// Random player for Tic-Tac-Toe
template <typename T>
class TicTacToeRandomPlayer : public RandomPlayer<T>
{
public:
    TicTacToeRandomPlayer(T symbol);
    void getmove(int &x, int &y) override;
};

template <typename T>
void TicTacToeRandomPlayer<T>::getmove(int &x, int &y)
{
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % 4; // Random number between 0 and 3
    y = rand() % 4;
}

template <typename T>
TicTacToeRandomPlayer<T>::TicTacToeRandomPlayer(T symbol) : RandomPlayer<T>(symbol) {}

#endif //_4X4_XO_H