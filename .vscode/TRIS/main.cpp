#include <iostream>
#include <vector>
using namespace std;

class Tris {
private:
    const int L = 3;
    vector<vector<string>> board;

public:
    Tris() : board(L, vector<string>(L, " ")) {}

    void printBoard() {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                cout << board[i][j];
                if (j < L - 1) cout << " | ";
            }
            cout << endl;
            if (i < L - 1) cout << "---------" << endl;
        }
    }

    bool placeSymbol(int x, int y, string symbol) {
        if (x < 0 || x >= L || y < 0 || y >= L || board[x][y] != " ") {
            return false;
        }
        board[x][y] = symbol;
        return true;
    }

    int checkWinner() {
        // Check rows, columns, and diagonals for a winner
        for (int i = 0; i < L; i++) {
            if (board[i][0] != " " && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return (board[i][0] == "X") ? 1 : 2;
            }
            if (board[0][i] != " " && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return (board[0][i] == "X") ? 1 : 2;
            }
        }
        if (board[0][0] != " " && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return (board[0][0] == "X") ? 1 : 2;
        }
        if (board[0][2] != " " && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return (board[0][2] == "X") ? 1 : 2;
        }
        return 0;  // No winner yet
    }
};

int main() {
    Tris game;
    int x, y, currentPlayer = 1, movesLeft = 9;
    bool validMove, gameOver = false;

    cout << "Welcome to the game of Tic-Tac-Toe (TRIS)!" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;

    while (!gameOver && movesLeft > 0) {
        game.printBoard();
        cout << "Player " << currentPlayer << " - Enter your move (row column): ";
        cin >> x >> y;
        x--; y--;  // Adjust for 0-based indexing

        validMove = game.placeSymbol(x, y, (currentPlayer == 1) ? "X" : "O");
        if (validMove) {
            movesLeft--;
            int winner = game.checkWinner();
            if (winner != 0) {
                game.printBoard();
                cout << "Congratulations! Player " << winner << " wins!" << endl;
                gameOver = true;
            } else if (movesLeft == 0) {
                game.printBoard();
                cout << "It's a draw! The game is over." << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    return 0;
}

