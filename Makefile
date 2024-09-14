# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Ihpp\ files -Wall

# Source and header directories
SRCDIR = cpp\ files
HDRDIR = hpp\ files

# Object files
OBJ = $(SRCDIR)/Player.o $(SRCDIR)/Slot.o $(SRCDIR)/Property.o $(SRCDIR)/Utility.o \
      $(SRCDIR)/TrainStation.o $(SRCDIR)/Board.o $(SRCDIR)/GameManager.o $(SRCDIR)/Dice.o \
      $(SRCDIR)/Bank.o

# Output executable
TARGET = monopoly

# Default rule
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile individual .cpp files into .o files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HDRDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the compiled object files and executable
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

# Phony target to ensure clean runs every time
.PHONY: all clean
