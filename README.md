# 🎮 FCAI Board Games Hub

## 📌 Overview
This project is a **C++ console application** that brings together multiple classic board games under one hub.  
Players can enjoy different variations of **Tic-Tac-Toe**, **Connect 4**, and even a **Numbers-based X-O** game with unique rules.  

The program is built with **OOP concepts** like inheritance, polymorphism, and templates for reusable game components.  

---

## 🕹️ Games Available
1. **Connect 4**  
   - Standard 7x6 Connect Four game.  
   - Supports **Human vs Human** and **Human vs Random Computer** play.  

2. **Tic-Tac-Toe (4x4)**  
   - Extended Tic-Tac-Toe on a 4x4 board.  
   - Supports **Human vs Human** and **Human vs Random Computer**.  

3. **Misere Tic-Tac-Toe (X-O)**  
   - A twist on classic Tic-Tac-Toe: **the player who gets 3 in a row loses**.  

4. **Numbers Tic-Tac-Toe**  
   - Each move uses numbers **1–9**.  
   - **Player 1 must use odd numbers**, **Player 2 must use even numbers**.  
   - A player wins if their numbers form a row/column/diagonal summing to **15**.  

---

## 📂 Project Structure
├── BoardGame_Classes.h # Base board & player classes
├── connect4.h # Connect 4 board & player definitions
├── 4x4.h # 4x4 Tic-Tac-Toe implementation
├── Misere_X_O.h # Misere Tic-Tac-Toe implementation
├── TICTACTOE_H.h # Standard Tic-Tac-Toe classes
├── main.cpp # Main game hub & menu system

yaml
Copy code

---

## ⚡ Features
- **Menu-driven interface** for choosing games.  
- **Dynamic player setup** (Human or Random AI).  
- **Input validation** for correct moves.  
- **Object-oriented design** with templates, polymorphism, and inheritance.  
- **Reusable GameManager** class for running all games.  

---

## ▶️ How to Run
1. Compile the program using g++ (or any C++ compiler):
   ```bash
   g++ main.cpp -o games
Run the executable:

bash
Copy code
./games
Follow the menu to select and play a game.

📂 Example Usage
markdown
Copy code
Welcome to FCAI Board Games!
Please select a game to play:
1. Connect4
2. Tic-Tac-Toe (4x4)
3. Misere X-O (Tic-Tac-Toe)
4. Numbers
5. Exit

Enter choice: 1
Welcome to FCAI Connect4 Game. :)
Enter Player X name: Ahmed
Choose Player X type:
1. Human
2. Random Computer
> 1
Enter Player O name: Omar
Choose Player O type:
1. Human
2. Random Computer
> 2
Game starts...
🖼️ Flowchart
mermaid
Copy code
flowchart TD
    A[Start] --> B[Main Menu]
    B -->|1. Connect4| C[playConnect4()]
    B -->|2. TicTacToe 4x4| D[playTicTacToe()]
    B -->|3. Misere XO| E[MisereXO()]
    B -->|4. Numbers XO| F[numbersXO()]
    B -->|5. Exit| Z[Exit Program]

    C --> G[GameManager.run()]
    D --> G
    E --> G
    F --> G
    G --> B
