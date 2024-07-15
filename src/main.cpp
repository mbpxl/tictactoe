#include "model/TicTacToeModel.h"
#include "view/TicTacToeView.h"

int main() {
    TicTacToeModel model;
    TicTacToeView view;

    char currentPlayer = PLAYER_X;
    bool gameOver = false;

    while (!gameOver) {
        int mainRow, mainCol;

        view.displayMainBoard(model.getMainBoardWinners());
        view.promptMainField();
        std::cin >> mainRow >> mainCol;

        if (mainRow < 0 || mainRow >= 3 || mainCol < 0 || mainCol >= 3 || model.getMainBoardWinners()[mainRow][mainCol] != EMPTY) {
            view.showError();
            continue;
        }

        view.displaySmallBoard(model.getMainBoard()[mainRow][mainCol]);

        if (currentPlayer == PLAYER_X) {
            int row, col;
            view.promptMove(currentPlayer);
            std::cin >> row >> col;
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || model.getMainBoard()[mainRow][mainCol][row][col] != EMPTY) {
                view.showError();
                continue;
            }
            model.makeMove(mainRow, mainCol, row, col, currentPlayer);
        } else {
            // Computer move
            int row, col;
            do {
                row = std::rand() % 3;
                col = std::rand() % 3;
            } while (model.getMainBoard()[mainRow][mainCol][row][col] != EMPTY);
            model.makeMove(mainRow, mainCol, row, col, currentPlayer);
        }

        if (model.checkMainBoardWin(currentPlayer)) {
            view.showWinMessage(currentPlayer);
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    std::cout << "Game end!\n";
    return 0;
}
