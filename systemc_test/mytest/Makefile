# Makefile for SystemC project

SYSTEMC_HOME = ../../install_sc

# Compiler and linker
CXX = g++
# Compiler flags
CXXFLAGS = -g -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -v -W -t
# Source files
SRCS = mytest.cpp
# Output executable
TARGET = mytest

# Default target
all: $(TARGET)

# Build the target  not using -lsystemc, this will using the systemc installed at the build system.
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)  $(SYSTEMC_HOME)/lib-linux64/libsystemc.a

# Clean up build files
clean:
	rm -f $(TARGET)