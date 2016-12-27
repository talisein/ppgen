SHELL=/bin/sh
INSTALL?=/usr/bin/install
INSTALL_PROGRAM?=$(INSTALL)
INSTALL_DATA?=${INSTALL} -m 644
prefix?=/usr/local
exec_prefix?=$(prefix)
datarootdir=$(prefix)/share
bindir?=$(exec_prefix)/bin
mandir?=$(datarootdir)/man
man1dir?=$(mandir)/man1

OPTFLAGS?=-Os
CXXFLAGS?=-Wall -Wextra -pedantic -Werror -std=c++14

.PHONY: all clean install uninstall

all: ppgen ppgen.o

clean:
	$(RM) ppgen ppgen.o

install: ppgen
	$(INSTALL_PROGRAM) ppgen $(DESTDIR)$(bindir)
	$(INSTALL_DATA) ppgen.1 $(DESTDIR)$(man1dir)

uninstall:
	$(RM) $(DESTDIR)$(bindir)/ppgen

ppgen: ppgen.o
	$(CXX) $(LDFLAGS) ppgen.o -o ppgen

ppgen.o: ppgen.cpp diceware_wordlist.h eff_wordlist.h pcg_random.hpp pcg_extras.hpp pcg_uint128.hpp
	$(CXX) $(CPPFLAGS) $(OPTFLAGS) $(CXXFLAGS) -c ppgen.cpp -o ppgen.o
