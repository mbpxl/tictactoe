#include <cassert>
#include <iostream>
#include "../m/TicTacToeModel.h"

class TicTacToeModelTest {
public:
    void testCheckBoardWin() {
        TicTacToeModel model;
        std::vector<std::vector<char>> board = {
            {PLAYER_X, PLAYER_X, PLAYER_X},
            {EMPTY, EMPTY, EMPTY},
            {EMPTY, EMPTY, EMPTY}
        };
        assert(model.checkBoardWin(board, PLAYER_X) == true);
        
        board = {
            {PLAYER_X, EMPTY, EMPTY},
            {PLAYER_X, EMPTY, EMPTY},
            {PLAYER_X, EMPTY, EMPTY}
        };
        assert(model.checkBoardWin(board, PLAYER_X) == true);

        board = {
            {PLAYER_X, EMPTY, EMPTY},
            {EMPTY, PLAYER_X, EMPTY},
            {EMPTY, EMPTY, PLAYER_X}
        };
        assert(model.checkBoardWin(board, PLAYER_X) == true);

        board = {
            {EMPTY, EMPTY, PLAYER_X},
            {EMPTY, PLAYER_X, EMPTY},
            {PLAYER_X, EMPTY, EMPTY}
        };
        assert(model.checkBoardWin(board, PLAYER_X) == true);
        
        board = {
            {PLAYER_X, EMPTY, EMPTY},
            {EMPTY, PLAYER_O, EMPTY},
            {EMPTY, EMPTY, PLAYER_X}
        };
        assert(model.checkBoardWin(board, PLAYER_X) == false);

        std::cout << "testCheckSmallBoardWin passed\n";
    }

    void testMakeMove() {
        TicTacToeModel model;
        model.makeMove(0, 0, 0, 0, PLAYER_X);
        auto mainBoard = model.getMainBoard();
        assert(mainBoard[0][0][0][0] == PLAYER_X);
        std::cout << "testMakeMove passed\n";
    }

    void testGetMainBoard() {
        TicTacToeModel model;
        auto mainBoard = model.getMainBoard();
        assert(mainBoard.size() == 3);
        assert(mainBoard[0].size() == 3);
        assert(mainBoard[0][0].size() == 3);
        assert(mainBoard[0][0][0].size() == 3);
        std::cout << "testGetMainBoard passed\n";
    }

    void testGetMainBoardWinners() {
        TicTacToeModel model;
        auto mainBoardWinners = model.getMainBoardWinners();
        assert(mainBoardWinners.size() == 3);
        assert(mainBoardWinners[0].size() == 3);
        std::cout << "testGetMainBoardWinners passed\n";
    }

    void runAllTests() {
        testCheckBoardWin();
        testMakeMove();
        testGetMainBoard();
        testGetMainBoardWinners();
        std::cout << "All TicTacToeModel tests passed\n";
    }
};

int main() {
    TicTacToeModelTest test;
    test.runAllTests();
    return 0;
}
