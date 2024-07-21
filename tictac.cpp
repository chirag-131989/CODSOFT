#include <iostream>
#include <vector>
#include <string>

using namespace std;

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void displayBoard(const vector<vector<char>>& board) {
    cout << endl << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
            cout << board[i][j] << " | ";
        cout << endl << "-------------" << endl;
    }
}

bool makeMove(vector<vector<char>>& board, int row, int col, char currentPlayer) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>>& board, char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        initializeBoard(board);

        while (!gameOver) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(board, row, col)) {
                if (makeMove(board, row, col, currentPlayer)) {
                    if (checkWin(board, currentPlayer)) {
                        displayBoard(board);
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        gameOver = true;
                    } else if (checkDraw(board)) {
                        displayBoard(board);
                        cout << "It's a draw!" << endl;
                        gameOver = true;
                    } else {
                        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                    }
                } else {
                    cout << "Invalid move! That cell is already taken. Try again." << endl;
                }
            } else {
                cout << "Invalid move! Please enter row and column within 0-2." << endl;
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            gameOver = false;
            currentPlayer = 'X';
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}
