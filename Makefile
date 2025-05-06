# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source and binary files
SRC_DIR = src
BIN_DIR = build
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
EXECUTABLE = $(BIN_DIR)/tictactoe

# Default target
all: $(EXECUTABLE)

# Link object files into executable
$(EXECUTABLE): $(SOURCES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

# Clean build artifacts
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
