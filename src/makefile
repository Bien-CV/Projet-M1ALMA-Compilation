# définition des actions
.PHONY: clean

# définition des variables
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
SOURCES = main.cpp generateur.cpp
OBJECTS = $(SOURCES:.cpp =.o)

# regles
all: $(OBJECTS)
	$(CXX) -o compile $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

generateur.cpp: generateur.hpp typage.hpp
	@touch generateur.hpp typage.hpp

# action clean
clean:
	-rm *.o compile
