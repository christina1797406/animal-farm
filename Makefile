# Determine the OS
OS := $(shell uname)

# Conditional flags based on OS
ifeq ($(OS), Darwin)
    SFML_INCLUDE = -I/opt/homebrew/Cellar/sfml/2.6.1/include
    SFML_LIB = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
else ifeq ($(OS), Linux)
    SFML_INCLUDE = -I/usr/include/SFML
    SFML_LIB = -L/usr/lib
endif

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Define compilers and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wextra $(SFML_INCLUDE)
LIBFLAGS = $(SFML_LIB) $(SFML_FLAGS)
OBJ_DIR = obj
BIN_DIR = bin
TARGET = FarmSimulator

# Source and object files
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(filter-out CropTest.cpp ShovelTest.cpp UserTest.cpp FlowerTest.cpp VegetableTest.cpp WaterCanTest.cpp EquipmentTest.cpp seasonalVegTest.cpp, $(SOURCES)))

.PHONY: all clean

# Default target
all: $(BIN_DIR)/$(TARGET)

# Linking target
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LIBFLAGS) -o $@

# Compiling
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(BIN_DIR)/$(TARGET)
