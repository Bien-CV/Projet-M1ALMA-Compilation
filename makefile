# définition des actions
.PHONY: clean

# définition des variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -ansi -std=c++11 -I./header/

SOURCES = src/main.cpp src/generateur.cpp src/scanner.cpp src/analyseur.cpp \
	src/tabSymbole.cpp src/action.cpp
OBJECTS = $(SOURCES:.cpp =.o)

# regles
all: $(OBJECTS)
	$(CXX) -o compile $^ $(CXXFLAGS)

# action clean
clean:
	-rm src/*.o compile
