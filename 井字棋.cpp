#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char player, computer;
    int playerWins, computerWins, draws;

public:
    TicTacToe() : player('X'), computer('O'), playerWins(0), computerWins(0), draws(0) {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    void displayBoard() {
        cout << "-------------\n";
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool isWin(char c) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void playerMove() {
        int row, col;
        while (true) {
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = player;
                break;
            }
            else {
                cout << "This move is not valid. Try again.\n";
            }
        }
    }

    void computerMove() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = computer;
                    return;
                }
            }
        }
    }

    void saveResult(string result) {
        ofstream outfile("TicTacToeResults.txt", ios::app);
        outfile << result << endl;
        outfile.close();
    }

    void playGame() {
        char turn;
        cout << "Do you want to go first (Y/N)? ";
        cin >> turn;
        bool playerFirst = (turn == 'Y' || turn == 'y');

        while (true) {
            displayBoard();
            if (playerFirst) {
                playerMove();
                if (isWin(player)) {
                    cout << "Player wins!\n";
                    playerWins++;
                    saveResult("Player wins!");
                    break;
                }
                playerFirst = false;
            }
            else {
                computerMove();
                if (isWin(computer)) {
                    cout << "Computer wins!\n";
                    computerWins++;
                    saveResult("Computer wins!");
                    break;
                }
                playerFirst = true;
            }
            if (isDraw()) {
                cout << "It's a draw!\n";
                draws++;
                saveResult("It's a draw!");
                break;
            }
        }
        displayBoard();
    }

    void showStatistics() {
        cout << "\n--- Game Statistics ---\n";
        cout << "Player wins: " << playerWins << "\n";
        cout << "Computer wins: " << computerWins << "\n";
        cout << "Draws: " << draws << "\n";
    }
};

int main() {
    TicTacToe game;
    char playAgain;
    do {
        game.playGame();
        cout << "Do you want to play again (Y/N)? ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
    game.showStatistics();
    return 0;
}
