#ifndef ULTIMATE_TIC_TAC_TOE_H
#define ULTIMATE_TIC_TAC_TOE_H
#include "BoardGame_Classes.h"

template <typename T>
class ultimate_tic_tac_toe_Board : public Board<T>
{
public:
    ultimate_tic_tac_toe_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool mini_win1();
    bool mini_win2();
    bool mini_win3();
    bool mini_win4();
    bool mini_win5();
    bool mini_win6();
    bool mini_win7();
    bool mini_win8();
    bool mini_win9();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class ultimate_tic_tac_toe_Player : public Player<T>
{
public:
    ultimate_tic_tac_toe_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class ultimate_tic_tac_toe_Random_Player : public RandomPlayer<T>
{
public:
    ultimate_tic_tac_toe_Random_Player(T symbol);
    void getmove(int &x, int &y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()

using namespace std;

// Constructor for ultimate_tic_tac_toe_Board
template <typename T>
ultimate_tic_tac_toe_Board<T>::ultimate_tic_tac_toe_Board()
{
    this->rows = this->columns = 9;
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
bool ultimate_tic_tac_toe_Board<T>::update_board(int x, int y, T mark)
{
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0))
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
void ultimate_tic_tac_toe_Board<T>::display_board()
{

    for (int i = 0; i < this->rows; i++)
    {
        if (i == 0){
            cout << "\n||---------------------------||--------------------------||--------------------------||" ;
            cout << "\n||---------------------------||--------------------------||--------------------------||" ;
        }

        cout << "\n|";
        for (int j = 0; j < this->columns; j++)
        {   if (j == 0){
            cout << "| ";

        }
            cout << " (" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
            if (j == 2 || j == 5 || j == 8){
                cout << "|";
            }
        }
        if (i == 2 || i == 5 || i == 8){
            cout <<"\n||---------------------------||--------------------------||--------------------------||" ;
        }
        cout << "\n||---------------------------||--------------------------||--------------------------||" ;
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win1()
{
    // Check rows and columns
    for (int i = 0; i < 2; i++)
    {
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0))
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0))
    {
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win2()
{
    // Check rows and columns
    for (int i = 3; i < 6; i++)
    {
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][3] != 0) ||
            (this->board[3][i] == this->board[4][i] && this->board[4][i] == this->board[5][i] && this->board[3][i] != 0))
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[3][3] == this->board[4][4] && this->board[4][4] == this->board[5][5] && this->board[3][3] != 0) ||
        (this->board[3][5] == this->board[4][4] && this->board[4][4] == this->board[5][3] && this->board[3][5] != 0))
    {
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win3()
{
    // Check rows and columns
    for (int i = 6; i < 9; i++)
    {
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && this->board[i][6] != 0) ||
            (this->board[6][i] == this->board[7][i] && this->board[7][i] == this->board[8][i] && this->board[6][i] != 0))
        {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[6][6] == this->board[7][7] && this->board[7][7] == this->board[8][8] && this->board[6][6] != 0) ||
        (this->board[6][8] == this->board[7][7] && this->board[7][7] == this->board[8][6] && this->board[6][8] != 0))
    {
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win4()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        for (int j= 3; j < 6 ; j++){
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][3] != 0) ||
            (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[0][j] != 0))
        {
            return true;
        }
    }
    }

    // Check diagonals
    if ((this->board[0][3] == this->board[1][4] && this->board[1][4] == this->board[2][5] && this->board[0][3] != 0) ||
        (this->board[0][5] == this->board[1][4] && this->board[1][4] == this->board[2][3] && this->board[0][5] != 0))
    {
        return true;
    }

    return false;
}
template <typename T>

bool ultimate_tic_tac_toe_Board<T>::mini_win5()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        for (int j= 6; j < 9 ; j++){
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && this->board[i][6] != 0) ||
            (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[0][j] != 0))
        {
            return true;
        }
    }
    }

    // Check diagonals
    if ((this->board[0][6] == this->board[1][7] && this->board[1][7] == this->board[2][8] && this->board[0][6] != 0) ||
        (this->board[0][8] == this->board[1][7] && this->board[1][7] == this->board[2][6] && this->board[0][8] != 0))
    {
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win6()
{
    // Check rows and columns
    for (int i = 3; i < 6; i++)
    {
        for (int j= 0; j < 3 ; j++){
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[3][j] == this->board[4][j] && this->board[4][j] == this->board[5][j] && this->board[3][j] != 0))
        {
            return true;
        }
    }
    }

    // Check diagonals
    if ((this->board[3][0] == this->board[4][1] && this->board[4][1] == this->board[5][2] && this->board[3][0] != 0) ||
        (this->board[3][2] == this->board[4][1] && this->board[4][1] == this->board[5][0] && this->board[3][2] != 0))
    {
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::mini_win7()
{
    // Check rows and columns
    for (int i = 3; i < 6; i++)
    {
        for (int j= 6; j < 9 ; j++){
        if ((this->board[i][6] == this->board[i][7] && this->board[i][7] == this->board[i][8] && this->board[i][6] != 0) ||
            (this->board[3][j] == this->board[4][j] && this->board[4][j] == this->board[5][j] && this->board[3][j] != 0))
        {
            return true;
        }
    }
    }

    // Check diagonals
    if ((this->board[3][6] == this->board[4][7] && this->board[4][7] == this->board[5][8] && this->board[3][6] != 0) ||
        (this->board[3][8] == this->board[4][7] && this->board[4][7] == this->board[5][6] && this->board[3][8] != 0))
    {
        return true;
    }

    return false;
}
template <typename T>

bool ultimate_tic_tac_toe_Board<T>::mini_win8()
{
    // Check rows and columns
    for (int i = 6; i < 9; i++)
    {
        for (int j= 0; j < 3 ; j++){
        if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) ||
            (this->board[6][j] == this->board[7][j] && this->board[7][j] == this->board[8][j] && this->board[6][j] != 0))
        {
            return true;
        }
        }
    }

    // Check diagonals
    if ((this->board[6][0] == this->board[7][1] && this->board[7][1] == this->board[8][2] && this->board[6][0] != 0) ||
        (this->board[6][2] == this->board[7][1] && this->board[7][1] == this->board[8][0] && this->board[6][2] != 0))
    {
        return true;
    }

    return false;
}
template <typename T>

bool ultimate_tic_tac_toe_Board<T>::mini_win9()
{
    // Check rows and columns
    for (int i = 6; i < 9; i++)
    {
        for (int j= 3; j < 6 ; j++){
        if ((this->board[i][3] == this->board[i][4] && this->board[i][4] == this->board[i][5] && this->board[i][3] != 0) ||
            (this->board[6][j] == this->board[7][j] && this->board[7][j] == this->board[8][j] && this->board[6][j] != 0))
        {
            return true;
        }
    }
    }

    // Check diagonals
    if ((this->board[6][3] == this->board[7][4] && this->board[7][4] == this->board[8][5] && this->board[6][3] != 0) ||
        (this->board[6][5] == this->board[7][4] && this->board[7][4] == this->board[8][3] && this->board[6][5] != 0))
    {
        return true;
    }

    return false;
}
template <typename T>

bool ultimate_tic_tac_toe_Board<T>::is_win() {

    if ((mini_win1() && mini_win4() && mini_win5 ()) || (mini_win6() && mini_win2() && mini_win7()) ||
        (mini_win8() && (mini_win9 () && mini_win3 ()))){
            return true;
        }
    else if ((mini_win1() && mini_win6() && mini_win8()) || (mini_win4() && mini_win2() && mini_win9()) ||
        (mini_win5() && mini_win7 () && mini_win3())){
            return true;
        }
    else if ((mini_win1() && mini_win2() && mini_win3()) || mini_win5()&& mini_win2() && mini_win8()){
            return true ;
    }

    else {
        return false;
    }
}
// Return true if 9 moves are done and no winner
template <typename T>
bool ultimate_tic_tac_toe_Board<T>::is_draw()
{
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool ultimate_tic_tac_toe_Board<T>::game_is_over()
{
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for ultimate_tic_tac_toe_Player
template <typename T>
ultimate_tic_tac_toe_Player<T>::ultimate_tic_tac_toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void ultimate_tic_tac_toe_Player<T>::getmove(int &x, int &y)
{
    cout << "\nPlease enter your move x and y (0 to 8) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for ultimate_tic_tac_toe_Random_Player
template <typename T>
ultimate_tic_tac_toe_Random_Player<T>::ultimate_tic_tac_toe_Random_Player(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

template <typename T>
void ultimate_tic_tac_toe_Random_Player<T>::getmove(int &x, int &y)
{
    x = rand() % this->dimension; // Random number between 0 and 2
    y = rand() % this->dimension;
}


#endif // ULTIMATE_TIC_TAC_TOE_H
