CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -Iinc -Im

BUILD_DIR = build
SRC_DIR = src
INC_DIR = inc
TEST_DIR = test

MODEL_SRC = $(SRC_DIR)/TicTacToeModel.cpp
VIEW_SRC = $(SRC_DIR)/TicTacToeView.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp

MODEL_TEST_SRC = $(TEST_DIR)/TestTicTacToeModel.cpp
VIEW_TEST_SRC = $(TEST_DIR)/TestTicTacToeView.cpp

MODEL_OBJ = $(BUILD_DIR)/TicTacToeModel.o
VIEW_OBJ = $(BUILD_DIR)/TicTacToeView.o
MAIN_OBJ = $(BUILD_DIR)/main.o

MODEL_TEST_OBJ = $(BUILD_DIR)/TestTicTacToeModel.o
VIEW_TEST_OBJ = $(BUILD_DIR)/TestTicTacToeView.o

EXEC = TicTacToe
MODEL_TEST_EXEC = TestTicTacToeModel
VIEW_TEST_EXEC = TestTicTacToeView

.PHONY: all clean test

all: $(EXEC)

$(EXEC): $(MAIN_OBJ) $(MODEL_OBJ) $(VIEW_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(MODEL_TEST_EXEC): $(MODEL_TEST_OBJ) $(MODEL_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(VIEW_TEST_EXEC): $(VIEW_TEST_OBJ) $(VIEW_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(MODEL_TEST_EXEC) $(VIEW_TEST_EXEC)
	./$(MODEL_TEST_EXEC)
	./$(VIEW_TEST_EXEC)

clean:
	rm -rf $(BUILD_DIR) $(EXEC) $(MODEL_TEST_EXEC) $(VIEW_TEST_EXEC)
