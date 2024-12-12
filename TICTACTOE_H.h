#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

#include "BoardGame_Classes.h"
#include <iostream>

using namespace std;

template <typename T>
class TicTacToeBoardd : public Board<T>
{
public:
    TicTacToeBoardd()
    {
        this->rows = 3;
        this->columns = 3;
        this->board = new T *[3];
        for (int i = 0; i < 3; ++i)
        {
            this->board[i] = new T[3]();
        }
    }

    bool update_board(int x, int y, T symbol) override
    {
        if (x >= 0 && x < 3 && y >= 0 && y < 3 && this->board[x][y] == 0)
        {
            this->board[x][y] = symbol;
            this->n_moves++;
            return true;
        }
        return false;
    }

    void display_board() override
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << (this->board[i][j] == 0 ? 0 : this->board[i][j]) << " ";
            }
            cout << endl;
        }
    }

    bool is_win() override
    {
        for (int i = 0; i < 3; ++i)
        {
            if (this->board[i][0] + this->board[i][1] + this->board[i][2] == 15)
                return true;
            if (this->board[0][i] + this->board[1][i] + this->board[2][i] == 15)
                return true;
        }
        if (this->board[0][0] + this->board[1][1] + this->board[2][2] == 15)
            return true;
        if (this->board[0][2] + this->board[1][1] + this->board[2][0] == 15)
            return true;
        return false;
    }

    bool is_draw() override
    {
        return this->n_moves == 9;
    }

    bool game_is_over() override
    {
        return is_win() || is_draw();
    }

    T get_board_value(int x, int y)
    {
        return this->board[x][y];
    }
};

template <typename T>
class TicTacToePlayerr : public Player<T>
{
public:
    TicTacToePlayerr(string n, T symbol) : Player<T>(n, symbol) {}

    void getmove(int &x, int &y) override
    {
        cout << "Enter your move (row and column): ";
        cin >> x >> y;
    }
};

#endif //_TICTACTOE_H_
