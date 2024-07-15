#include "view/TicTacToeView.h"

void TicTacToeView::displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

void TicTacToeView::displayMainBoard(const std::vector<std::vector<char>>& mainBoardWinners) {
    std::cout << "Current main field:\n";
    displayBoard(mainBoardWinners);
}

void TicTacToeView::displaySmallBoard(const std::vector<std::vector<char>>& smallBoard) {
    std::cout << "Current small field:\n";
    displayBoard(smallBoard);
}

void TicTacToeView::promptMove(char player) {
    std::cout << "Enter a row and column (0-2) for the player " << player << ": ";
}

void TicTacToeView::promptMainField() {
    std::cout << "Enter the row and column number of the main field (0-2): ";
}

void TicTacToeView::showError() {
    std::cout << "Error, try again.\n";
}

void TicTacToeView::showWinMessage(char player) {
    std::cout << "Player " << player << " won!\n";
}
