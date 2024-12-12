#include <iostream>
#include "BoardGame_Classes.h"
#include "connect4.h"
#include "4x4.h"
#include "Misere_X_O.h"

using namespace std;

void playConnect4()
{
    int choice;
    Player<char> *players[2];
    Connect4_Board<char> *B = new Connect4_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI Connect4 Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new Connect4_Player<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new Connect4_Random_Player<char>('X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting Connect4.\n";
        delete B;
        return;
    }

    // Set up player 2
    cout << "Enter Player O name: ";
    cin >> player2Name;
    cout << "Choose Player O type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new Connect4_Player<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new Connect4_Random_Player<char>('O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting Connect4.\n";
        delete B;
        delete players[0];
        return;
    }

    // Create the game manager and run the game
    GameManager<char> connect4_game(B, players);
    connect4_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void playTicTacToe()
{
    int choice;
    Player<char> *players[2];
    TicTacToeBoard<char> *B = new TicTacToeBoard<char>();
    string playerXName, player2Name;

    cout << "Welcome to FCAI X-O Game. :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[0] = new TicTacToePlayer<char>(playerXName, 'X');
        break;
    case 2:
        players[0] = new TicTacToeRandomPlayer<char>('X');
        break;
    default:
        cout << "Invalid choice for Player 1. Exiting X-O.\n";
        delete B;
        return;
    }

    // Set up player 2
    cout << "Enter Player O name: ";
    cin >> player2Name;
    cout << "Choose Player O type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        players[1] = new TicTacToePlayer<char>(player2Name, 'O');
        break;
    case 2:
        players[1] = new TicTacToeRandomPlayer<char>('O');
        break;
    default:
        cout << "Invalid choice for Player 2. Exiting X-O.\n";
        delete B;
        delete players[0];
        return;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i)
    {
        delete players[i];
    }
}

void MisereXO()
{
    XOBoard board;

    XOPlayer player1("Player 1", 'X');
    XOPlayer player2("Player 2", 'O');

    Player<char> *players[] = {&player1, &player2};
    player1.setBoard(&board);
    player2.setBoard(&board);

    GameManager<char> gameManager(&board, players);

    cout << "Welcome to Tic Tac Toe!" << endl;
    gameManager.run();
}

int main()
{
    int gameChoice;

    while (true)
    {
        cout << "\nWelcome to FCAI Board Games!\n";
        cout << "Please select a game to play:\n";
        cout << "1. Connect4\n";
        cout << "2. Tic-Tac-Toe (4x4)\n";
        cout << "3. Misere X-O (Tic-Tac-Toe)\n";
        cout << "4. Exit\n";

        cin >> gameChoice;

        switch (gameChoice)
        {
        case 1:
            playConnect4();
            break;
        case 2:
            playTicTacToe();
            break;
        case 3:
            MisereXO();
            break;

        case 4:
            cout << "Thank you for playing! Goodbye.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}