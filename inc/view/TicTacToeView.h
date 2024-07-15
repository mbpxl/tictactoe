#ifndef TICTACTOEVIEW_H
#define TICTACTOEVIEW_H

#include <iostream>
#include "model/TicTacToeModel.h"

class TicTacToeView {
public:
    void displayBoard(const std::vector<std::vector<char>>& board);
    void displayMainBoard(const std::vector<std::vector<char>>& mainBoardWinners);
    void displaySmallBoard(const std::vector<std::vector<char>>& smallBoard);
    void promptMove(char player);
    void promptMainField();
    void showError();
    void showWinMessage(char player);
};

#endif // TICTACTOEVIEW_H
