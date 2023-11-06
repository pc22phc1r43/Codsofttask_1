#include <iostream>
#include <vector>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if the game has been won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameOver) {
        displayBoard(board);

        // Get player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check for valid input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else {
            // Check for a draw
            bool isDraw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        isDraw = false;
                        break;
                    }
                }
                if (!isDraw) {
                    break;
                }
            }
            if (isDraw) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
