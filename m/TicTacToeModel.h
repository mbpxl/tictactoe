#ifndef TICTACTOEMODEL_H
#define TICTACTOEMODEL_H

#include <vector>
#include <cstdlib>
#include <ctime>

const char EMPTY = '.';
const char PLAYER_X = 'x';
const char PLAYER_O = 'o';

class TicTacToeModel {
public:
    TicTacToeModel();
    bool checkBoardWin(const std::vector<std::vector<char>>& board, char player);
    bool checkMainBoardWin(char player);
    void makeMove(int mainRow, int mainCol, int row, int col, char player);
    bool isValidMove(int mainRow, int mainCol, int row, int col) const; // dobavil!
    std::vector<std::vector<std::vector<std::vector<char>>>> getMainBoard() const;
    std::vector<std::vector<char>> getMainBoardWinners() const;

private:
    std::vector<std::vector<std::vector<std::vector<char>>>> mainBoard;
    std::vector<std::vector<char>> mainBoardWinners;
};

#endif // TICTACTOEMODEL_H
