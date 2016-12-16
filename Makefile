CXXFLAGS=-Wall -Wextra -pedantic -std=c++14
EXECUTABLE=ppgen
SRC=ppgen.cpp
OBJECTS=ppgen.o
.PHONY=all

all: $(SRC) $(EXECUTABLE)

ppgen: ppgen.o
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

ppgen.o: ppgen.cpp wordlist.h
	$(CXX) $(CXXFLAGS) -c ppgen.cpp -o ppgen.o
