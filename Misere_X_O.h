#ifndef _XO_GAME_CLASSES_H
#define _XO_GAME_CLASSES_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
using namespace std;

class XOBoard : public Board<char>
{
public:
    XOBoard(int rows = 3, int cols = 3); // Default board size is 3x3
    bool update_board(int x, int y, char symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    ~XOBoard();
};

class XOPlayer : public Player<char>
{
public:
    XOPlayer(string name, char symbol);
    XOPlayer(char symbol); // For computer players
    virtual void getmove(int &x, int &y) override;
};

class XORandomPlayer : public RandomPlayer<char>
{
public:
    XORandomPlayer(char symbol);
    virtual void getmove(int &x, int &y) override;
};

#endif //_XO_GAME_CLASSES_H

XOBoard::XOBoard(int rows, int cols)
{
    this->rows = rows;
    this->columns = cols;
    board = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = ' '; // Empty cell
        }
    }
}

bool XOBoard::update_board(int x, int y, char symbol)
{
    if (x >= 0 && x < rows && y >= 0 && y < columns && board[x][y] == ' ')
    {
        board[x][y] = symbol;
        n_moves++;
        if (is_win())
        {
            // Corrected output to match Player 1 loses when Player 1 (symbol 'X') wins
            if (symbol == 'X')
            {
                cout << "Player 1 loses!" << endl; // Player 1 (X) wins, but you say they lose
            }
            else
            {
                cout << "Player 2 loses!" << endl; // Player 2 (O) wins, but you say they lose
            }
        }
        return true;
    }
    return false;
}

void XOBoard::display_board()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << board[i][j];
            if (j < columns - 1)
                cout << " | ";
        }
        cout << endl;
        if (i < rows - 1)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "--";
                if (j < columns - 1)
                    cout << "+";
            }
            cout << endl;
        }
    }
}

bool XOBoard::is_win()
{
    // Check rows and columns
    for (int i = 0; i < rows; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    for (int j = 0; j < columns; j++)
    {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

bool XOBoard::is_draw()
{
    return n_moves == rows * columns && !is_win();
}

bool XOBoard::game_is_over()
{
    return is_win() || is_draw();
}

XOBoard::~XOBoard()
{
    for (int i = 0; i < rows; i++)
        delete[] board[i];
    delete[] board;
}

// XOPlayer implementation
XOPlayer::XOPlayer(string name, char symbol) : Player(name, symbol) {}

XOPlayer::XOPlayer(char symbol) : Player(symbol) {}

void XOPlayer::getmove(int &x, int &y)
{
    cout << this->getname() << " (" << this->getsymbol() << "), enter your move (row and column): ";
    cin >> x >> y;
    x--;
    y--; // Convert to 0-based index
}

// XORandomPlayer implementation
XORandomPlayer::XORandomPlayer(char symbol) : RandomPlayer(symbol)
{
    srand(static_cast<unsigned>(time(0)));
}

void XORandomPlayer::getmove(int &x, int &y)
{
    x = rand() % 3;
    y = rand() % 3;
}
