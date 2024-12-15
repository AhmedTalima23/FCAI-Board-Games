#ifndef WORDGAME_H
#define WORDGAME_H

#include "BoardGame_Classes.h"
#include <unordered_set>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

template <typename T>
class WordGame_Board : public Board<T>
{
private:
    char grid[3][3];                         // 3x3 game board
    const unordered_set<string> &dictionary; // Reference to the dictionary
    mutable string winnerWord;               // Store the winning word

public:
    WordGame_Board(const unordered_set<string> &dict);
    bool update_board(int x, int y, T symbol) override;
    void display_board() const override;
    bool is_win() const override;
    bool is_draw() const override;
    bool game_is_over() const override;
};

template <typename T>
class WordGamePlayer : public Player<T>
{
public:
    WordGamePlayer(string name, T symbol);
    void getmove(int &x, int &y) const override;
};

template <typename T>
class RandomWordGamePlayer : public RandomPlayer<T>
{
public:
    RandomWordGamePlayer(T symbol);
    void getmove(int &x, int &y) const override;
};

// --------------------------------- IMPLEMENTATION ---------------------------------

template <typename T>
WordGame_Board<T>::WordGame_Board(const unordered_set<string> &dict) : dictionary(dict)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = '\0'; // Initialize all cells as empty
}

template <typename T>
bool WordGame_Board<T>::update_board(int x, int y, T symbol)
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || grid[x][y] != '\0')
        return false;

    grid[x][y] = toupper(symbol);
    return true;
}

template <typename T>
void WordGame_Board<T>::display_board() const
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == '\0')
                cout << ". "; // Display empty cells as dots
            else
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
bool WordGame_Board<T>::is_win() const
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        string rowWord;
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] != '\0')
                rowWord += grid[i][j];
        }
        if (dictionary.count(rowWord))
        {
            winnerWord = rowWord;
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j)
    {
        string colWord;
        for (int i = 0; i < 3; ++i)
        {
            if (grid[i][j] != '\0')
                colWord += grid[i][j];
        }
        if (dictionary.count(colWord))
        {
            winnerWord = colWord;
            return true;
        }
    }

    // Check diagonals
    string diag1, diag2;
    for (int i = 0; i < 3; ++i)
    {
        if (grid[i][i] != '\0')
            diag1 += grid[i][i];
        if (grid[i][2 - i] != '\0')
            diag2 += grid[i][2 - i];
    }

    if (dictionary.count(diag1))
    {
        winnerWord = diag1;
        return true;
    }
    if (dictionary.count(diag2))
    {
        winnerWord = diag2;
        return true;
    }

    return false;
}

template <typename T>
bool WordGame_Board<T>::is_draw() const
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == '\0')
                return false;
    return !is_win();
}

template <typename T>
bool WordGame_Board<T>::game_is_over() const
{
    return is_win() || is_draw();
}

template <typename T>
WordGamePlayer<T>::WordGamePlayer(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void WordGamePlayer<T>::getmove(int &x, int &y) const
{
    cout << this->name << "'s move (row and column): ";
    cin >> x >> y;
    --x; // Convert to 0-based indexing
    --y; // Convert to 0-based indexing
}

template <typename T>
RandomWordGamePlayer<T>::RandomWordGamePlayer(T symbol) : RandomPlayer<T>(symbol) {}

template <typename T>
void RandomWordGamePlayer<T>::getmove(int &x, int &y) const
{
    x = rand() % 3;
    y = rand() % 3;
}

#endif // WORDGAME_H
