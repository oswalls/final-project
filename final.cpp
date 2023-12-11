#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;



class Connect4 {
public:
    Connect4() : currentPlayer('X') {
        board.resize(ROWS, std::vector<char>(COLS, ' '));
    }

    void playGame() {
        int column;

        do {
            printBoard();
            column = getColumn();
            dropDisc(column);
        } while (!isGameOver());

        printBoard();
        printResult();
    }
/// board creation
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void printBoard() {
        std::cout << " 1 2 3 4 5 6 7\n";
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << "|" << board[i][j];
            }
            std::cout << "|\n";
        }
        std::cout << "---------------\n";
    }


    //Player Prompt for action

    int getColumn() {
        int column;
        do {
            std::cout << "Player " << currentPlayer << ", enter a column (1-7): ";
            std::cin >> column;
        } while (column < 1 || column > 7 || board[0][column - 1] != ' ');

        return column - 1;
    }

    void dropDisc(int column) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][column] == ' ') {
                board[i][column] = currentPlayer;
                switchPlayer();
                return;
            }
        }
    }

    bool isGameOver() {
        // Check for a win
        if (checkWin()) {
            return true;
        }

        // Check for a tie
        for (int i = 0; i < COLS; ++i) {
            if (board[0][i] == ' ') {
                return false;
            }
        }

        std::cout << "The game is a tie!\n";
        return true;
    }

    bool checkWin() {
        // Check horizontally
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i][j + 1] == currentPlayer &&
                    board[i][j + 2] == currentPlayer &&
                    board[i][j + 3] == currentPlayer) {
                    printBoard();
                    printResult();
                    return true;
                }
            }
        }

        // Check vertically
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j] == currentPlayer &&
                    board[i + 2][j] == currentPlayer &&
                    board[i + 3][j] == currentPlayer) {
                    printBoard();
                    printResult();
                    return true;
                }
            }
        }

        // Check diagonally
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j + 1] == currentPlayer &&
                    board[i + 2][j + 2] == currentPlayer &&
                    board[i + 3][j + 3] == currentPlayer) {
                    printBoard();
                    printResult();
                    return true;
                }
            }
        }

        // Check diagonally 
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 3; j < COLS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j - 1] == currentPlayer &&
                    board[i + 2][j - 2] == currentPlayer &&
                    board[i + 3][j - 3] == currentPlayer) {
                    printBoard();
                    printResult();
                    return true;
                }
            }
        }

        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void printResult() {
        std::cout << "Player " << currentPlayer << " wins!\n";
    }
};

int main() {
    Connect4 game;
    game.playGame();

    return 0;
}
