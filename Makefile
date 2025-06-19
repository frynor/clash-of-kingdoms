# Project structure
SRC_DIR := src
INC_DIR := includes
BUILD_DIR := build
BIN := main

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I$(INC_DIR)
LDFLAGS := -lncurses

# Automatically find all .cpp files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(BIN)

# Build binary
$(BIN): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(BIN)

.PHONY: all clean

