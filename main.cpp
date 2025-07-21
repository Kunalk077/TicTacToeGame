#include <iostream>
using namespace std;

// Global variables
char board[3][3];
char currentPlayer = 'X';

// Function to initialize the game board with numbers
void initializeBoard() {
    char pos = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = pos++;
        }
    }
}

// Function to display the current board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

// Function to switch turns
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if a move is valid
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

// Function to check for a win
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Main game loop
int main() {
    int move;
    bool gameRunning = true;

    initializeBoard();

    cout << "=== TIC TAC TOE ===" << endl;
    cout << "Player 1: X\nPlayer 2: O\n";

    while (gameRunning) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (!makeMove(move)) {
            cout << "Position already taken. Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            gameRunning = false;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameRunning = false;
        } else {
            switchPlayer();
        }
    }

    return 0;
}
