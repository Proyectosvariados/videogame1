# Makefile for Roguelike Medieval Fantasy

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -I./include

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN := RoguelikeMedievalFantasy

# Gather all source files and create corresponding object files in the OBJ_DIR
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link the final executable
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
