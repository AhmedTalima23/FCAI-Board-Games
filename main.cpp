#include <iostream>
#include <set>
#include "BoardGame_Classes.h"
#include "connect4.h"
#include "4x4.h"
#include "Misere_X_O.h"
#include "TICTACTOE_H.h"

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

void numbersXO()
{
    TicTacToeBoardd<int> board;
    TicTacToePlayerr<int> player1("Player 1", 1);
    TicTacToePlayerr<int> player2("Player 2", 2);

    player1.setBoard(&board);
    player2.setBoard(&board);

    int x, y, col;
    Player<int> *current_player = &player1;
    bool gameOver = false;

    set<int> usedNumbers;

    board.display_board();

    while (!gameOver)
    {
        cout << current_player->getname() << "'s turn (" << current_player->getsymbol() << "):\n";
        cout << "Enter the number you want to play (between 1 and 9): ";
        cin >> x;
        cout << "Enter the row and column (1-3): ";
        cin >> y >> col;

        if (x < 1 || x > 9 || y < 1 || y > 3 || col < 1 || col > 3)
        {
            cout << "Invalid input, please try again.\n";
            continue;
        }

        if (usedNumbers.find(x) != usedNumbers.end())
        {
            cout << "This number has already been played, try again.\n";
            continue;
        }

        if (board.get_board_value(y - 1, col - 1) != 0)
        {
            cout << "This cell is already occupied, please choose another one.\n";
            continue;
        }

        if (current_player == &player1 && x % 2 == 0)
        {
            cout << "Player 1 must enter an odd number.\n";
            continue;
        }
        else if (current_player == &player2 && x % 2 != 0)
        {
            cout << "Player 2 must enter an even number.\n";
            continue;
        }

        if (!board.update_board(y - 1, col - 1, x))
        {
            cout << "Invalid move, try again.\n";
            continue;
        }

        usedNumbers.insert(x);

        board.display_board();

        if (board.is_win())
        {
            cout << current_player->getname() << " wins!\n";
            gameOver = true;
        }
        else if (board.is_draw())
        {
            cout << "It's a draw!\n";
            gameOver = true;
        }
        else
        {
            current_player = (current_player == &player1) ? &player2 : &player1;
        }
    }
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
        cout << "4. Numbers\n";
        cout << "5. Exit\n";

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
            numbersXO();
            break;

        case 5:
            cout << "Thank you for playing! Goodbye.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

