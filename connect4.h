#ifndef CONNECT4_H
#define CONNECT4_H

#include "BoardGame_Classes.h"

template <typename T>
class Connect4_Board : public Board<T>
{
private:
    int grid[6][7];      // 6 rows x 7 columns
    int row_index = 5;   // Start from the bottom row
    int moves_count = 0; // To count the number of moves made

public:
    connect4_board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Connect4_Player : public Player<T>
{
public:
    Connect4_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class Connect4_Random_Player : public RandomPlayer<T>
{
public:
    Connect4_Random_Player(T symbol);
    void getmove(int &x, int &y);
};

//--------------------------------------- IMPLEMENTATION

template <typename T>
Connect4_Board<T>::connect4_board()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            grid[i][j] = 0; // Initialize all cells to empty
        }
    }
};

template <typename T>
bool Connect4_Board<T>::update_board(int x, int y, T symbol)
{
    int player = (symbol == 'X' ? 1 : 2); // Map symbol to player number
    if (row_index >= 0)
    {
        if (grid[row_index][y] != 0)
        {
            row_index--;
            return update_board(x, y, symbol);
        }
        else
        {
            grid[row_index][y] = player;
            row_index = 5; // Reset to the bottom row for the next move
            moves_count++;
            return true;
        }
    }
    else
    {
        cout << "Invalid move! Column is full.\n";
        row_index = 5;
        return false;
    }
}

template <typename T>
void Connect4_Board<T>::display_board()
{
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (grid[i][j] == 0)
                {
                    cout << "|   |";
                }
                else if (grid[i][j] == 1)
                {
                    cout << "| X |";
                }
                else if (grid[i][j] == 2)
                {
                    cout << "| O |";
                }
            }
            cout << "\n";
        }
        for (int i = 0; i < 7; i++)
        {
            cout << "=====";
        }
        cout << "\n";
    }
}

template <typename T>
bool Connect4_Board<T>::is_win()
{
    {
        // Check horizontal
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] != 0 && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
                {
                    return true;
                }
            }
        }
        // Check vertical
        for (int j = 0; j < 7; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (grid[i][j] != 0 && grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j])
                {
                    return true;
                }
            }
        }
        // Check diagonal (top-left to bottom-right)
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] != 0 && grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2] && grid[i][j] == grid[i + 3][j + 3])
                {
                    return true;
                }
            }
        }
        // Check diagonal (bottom-left to top-right)
        for (int i = 3; i < 6; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid[i][j] != 0 && grid[i][j] == grid[i - 1][j + 1] && grid[i][j] == grid[i - 2][j + 2] && grid[i][j] == grid[i - 3][j + 3])
                {
                    return true;
                }
            }
        }
        return false;
    }
}

template <typename T>
bool Connect4_Board<T>::is_draw()
{
    return moves_count == 42 && !is_win(); // Full board with no winner
}

template <typename T>
bool Connect4_Board<T>::game_is_over()
{
    return is_win() || is_draw();
}

template <typename T>
Connect4_Player<T>::Connect4_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Connect4_Player<T>::getmove(int &x, int &y)
{
    cout << "Enter column number (0-6): ";
    cin >> y;
    y--; // Convert from 1-based to 0-based indexing
}

template <typename T>
Connect4_Random_Player<T>::Connect4_Random_Player(T symbol) : RandomPlayer<T>(symbol)
{

    this->dimension = 7;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

template <typename T>
void Connect4_Random_Player<T>::getmove(int &x, int &y)
{
    y = rand() % this->dimension; // Random number between 0 and 6
}

#endif // CONNECT4_H
       // #endif