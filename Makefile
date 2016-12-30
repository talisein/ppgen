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

all: bin/ppgen

clean:
	$(RM) bin/ppgen

install: bin/ppgen
	$(INSTALL_PROGRAM) bin/ppgen $(DESTDIR)$(bindir)
	$(INSTALL_DATA) man/ppgen.1 $(DESTDIR)$(man1dir)

uninstall:
	$(RM) $(DESTDIR)$(bindir)/ppgen
	$(RM) $(DESTDIR)$(man1dir)/ppgen.1

bin:
	mkdir -p $@

bin/ppgen: src/ppgen.cpp src/diceware_wordlist.h src/eff_wordlist.h src/eff_short_wordlist.h src/pcg_random.hpp src/pcg_extras.hpp src/pcg_uint128.hpp | bin
	$(CXX) $(CPPFLAGS) $(OPTFLAGS) $(CXXFLAGS) src/ppgen.cpp -o bin/ppgen
