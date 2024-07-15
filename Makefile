# Имя компилятора
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++11 -Wall -Iinc

# Папка с исходными файлами и заголовочными файлами
SRC_DIR = src
INC_DIR = inc

# Имя исполняемого файла
TARGET = TicTacToe

# Исходные файлы
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/TicTacToeModel.cpp $(SRC_DIR)/TicTacToeView.cpp

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Цель по умолчанию
all: build

# Цель сборки
build: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Правило для сборки объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Цель очистки
clean:
	rm -f $(OBJS) $(TARGET)
