CXXFLAGS=-Wall -Wextra -pedantic -std=c++14

all: ppgen ppgen.o

clean:
	$(RM) ppgen ppgen.o

ppgen: ppgen.o
	$(CXX) ppgen.o -o ppgen

ppgen.o: ppgen.cpp wordlist.h pcg_random.hpp pcg_extras.hpp pcg_uint128.hpp
	$(CXX) $(CXXFLAGS) -c ppgen.cpp -o ppgen.o
