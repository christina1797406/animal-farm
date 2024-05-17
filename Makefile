# Define compilers and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra -Iinclude
LIBFLAGS = -Llib -lsfml-graphics -lsfml-window -lsfml-system # ADDING LIBRARY FLAGS FOR SFML
OBJ_DIR = obj
BIN_DIR = bin
TARGET = vs_pet_store

# Source and object files
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean

# Default target
all: $(BIN_DIR)/$(TARGET)

# Linking target
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) $^ -o $@

# Compiling
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(BIN_DIR)/$(Farm Game)