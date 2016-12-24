SHELL=/bin/sh
INSTALL?=/usr/bin/install
INSTALL_PROGRAM?=$(INSTALL)
prefix?=/usr/local
exec_prefix?=$(prefix)
bindir?=$(exec_prefix)/bin

OPTFLAGS?=-Os
CXXFLAGS?=-Wall -Wextra -pedantic -Werror -std=c++14

.PHONY: all clean install uninstall

all: ppgen ppgen.o

clean:
	$(RM) ppgen ppgen.o

install: ppgen
	$(INSTALL_PROGRAM) ppgen $(DESTDIR)$(bindir)

uninstall:
	$(RM) $(DESTDIR)$(bindir)/ppgen

ppgen: ppgen.o
	$(CXX) $(LDFLAGS) ppgen.o -o ppgen

ppgen.o: ppgen.cpp wordlist.h pcg_random.hpp pcg_extras.hpp pcg_uint128.hpp
	$(CXX) $(CPPFLAGS) $(OPTFLAGS) $(CXXFLAGS) -c ppgen.cpp -o ppgen.o
