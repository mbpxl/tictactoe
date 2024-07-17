#include <iostream>
#include <vector>
#include "view/TicTacToeView.h"

class TicTacToeViewTest {
public:
    void testDisplayBoard() {
        TicTacToeView view;
        std::vector<std::vector<char>> board = {
            {PLAYER_X, PLAYER_O, PLAYER_X},
            {PLAYER_O, PLAYER_X, PLAYER_O},
            {PLAYER_X, PLAYER_O, PLAYER_X}
        };
        view.displayBoard(board);
        std::cout << "testDisplayBoard passed\n";
    }

    void testDisplayMainBoard() {
        TicTacToeView view;
        std::vector<std::vector<char>> mainBoardWinners = {
            {PLAYER_X, PLAYER_O, PLAYER_X},
            {PLAYER_O, PLAYER_X, PLAYER_O},
            {PLAYER_X, PLAYER_O, PLAYER_X}
        };
        view.displayMainBoard(mainBoardWinners);
        std::cout << "testDisplayMainBoard passed\n";
    }

    void testDisplaySmallBoard() {
        TicTacToeView view;
        std::vector<std::vector<char>> smallBoard = {
            {PLAYER_X, PLAYER_O, PLAYER_X},
            {PLAYER_O, PLAYER_X, PLAYER_O},
            {PLAYER_X, PLAYER_O, PLAYER_X}
        };
        view.displaySmallBoard(smallBoard);
        std::cout << "testDisplaySmallBoard passed\n";
    }

    void testPromptMove() {
        TicTacToeView view;
        view.promptMove(PLAYER_X);
        std::cout << "testPromptMove passed\n";
    }

    void testPromptMainField() {
        TicTacToeView view;
        view.promptMainField();
        std::cout << "testPromptMainField passed\n";
    }

    void testShowError() {
        TicTacToeView view;
        view.showError();
        std::cout << "testShowError passed\n";
    }

    void testShowWinMessage() {
        TicTacToeView view;
        view.showWinMessage(PLAYER_X);
        std::cout << "testShowWinMessage passed\n";
    }

    void runAllTests() {
        testDisplayBoard();
        testDisplayMainBoard();
        testDisplaySmallBoard();
        testPromptMove();
        testPromptMainField();
        testShowError();
        testShowWinMessage();
        std::cout << "All TicTacToeView tests passed\n";
    }
};

int main() {
    TicTacToeViewTest test;
    test.runAllTests();
    return 0;
}
