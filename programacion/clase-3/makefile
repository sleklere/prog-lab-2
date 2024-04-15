# Compiler and linker configuration
CXX = g++
CXXFLAGS = -Wall -Wextra -g3

# Define directories
SRCDIR = c:\Users\Usuario\Desktop\Santiago\Archivos\TUP\2024\1C\prog-lab-2\programacion\08-04
OUTDIR = c:\Users\Usuario\Desktop\Santiago\Archivos\TUP\2024\1C\prog-lab-2\programacion\08-04\output

# Source and Object files
SOURCES = $(SRCDIR)/alumno.cpp $(SRCDIR)/fecha.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = $(OUTDIR)/alumno.exe

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# To obtain object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	del $(OBJECTS)
	del $(EXECUTABLE)

# Phony targets
.PHONY: all clean
