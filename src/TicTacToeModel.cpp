#include "model/TicTacToeModel.h"

TicTacToeModel::TicTacToeModel() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    mainBoard = std::vector<std::vector<std::vector<std::vector<char>>>>(3, std::vector<std::vector<std::vector<char>>>(3, std::vector<std::vector<char>>(3, std::vector<char>(3, EMPTY))));
    mainBoardWinners = std::vector<std::vector<char>>(3, std::vector<char>(3, EMPTY));
}

bool TicTacToeModel::checkSmallBoardWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool TicTacToeModel::checkMainBoardWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if ((mainBoardWinners[i][0] == player && mainBoardWinners[i][1] == player && mainBoardWinners[i][2] == player) ||
            (mainBoardWinners[0][i] == player && mainBoardWinners[1][i] == player && mainBoardWinners[2][i] == player)) {
            return true;
        }
    }
    return (mainBoardWinners[0][0] == player && mainBoardWinners[1][1] == player && mainBoardWinners[2][2] == player) ||
           (mainBoardWinners[0][2] == player && mainBoardWinners[1][1] == player && mainBoardWinners[2][0] == player);
}

void TicTacToeModel::makeMove(int mainRow, int mainCol, int row, int col, char player) {
    mainBoard[mainRow][mainCol][row][col] = player;
    if (checkSmallBoardWin(mainBoard[mainRow][mainCol], player)) {
        mainBoardWinners[mainRow][mainCol] = player;
    }
}

std::vector<std::vector<std::vector<std::vector<char>>>> TicTacToeModel::getMainBoard() const {
    return mainBoard;
}

std::vector<std::vector<char>> TicTacToeModel::getMainBoardWinners() const {
    return mainBoardWinners;
}
