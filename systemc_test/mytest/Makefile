# Makefile for SystemC project

# Compiler and linker
CXX = g++
# Compiler flags
CXXFLAGS = -g -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux -lsystemc
# Source files
SRCS = mytest.cpp
# Output executable
TARGET = mytest

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)