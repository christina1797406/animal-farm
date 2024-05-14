CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra
OBJ_DIR = obj
BIN_DIR = bin
TARGET = vs_pet_store

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(BIN_DIR)/$(Farm Game)