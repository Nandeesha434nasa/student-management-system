# Makefile for Student Management System

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable name
TARGET = student_system

# Source files
SOURCES = main.cpp Student.cpp Course.cpp Database.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Clean everything including data files
cleanall: clean
	rm -f students.txt courses.txt
	@echo "All files cleaned!"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  make          - Build the project"
	@echo "  make clean    - Remove object files and executable"
	@echo "  make cleanall - Remove all generated files including data"
	@echo "  make run      - Build and run the program"
	@echo "  make help     - Show this help message"
