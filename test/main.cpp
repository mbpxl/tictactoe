#include "model/TicTacToeModel.h"
#include "view/TicTacToeView.h"

#include "TestTicTacToeModel.cpp"
#include "TestTicTacToeView.cpp"

int main() {
    // Run all tests
    TicTacToeModelTest modelTest;
    modelTest.runAllTests();

    TicTacToeViewTest viewTest;
    viewTest.runAllTests();

    return 0;
}
