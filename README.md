ppgen
=====
Passphrase Generator

Requirements
------------
C++14 compiler.

Description
-----------

This simple command line program utilizes the [Diceware](http://world.std.com/~reinhold/diceware.html) wordlist to
generate a passphrase with the number of words you desire. I use it to
generate answers to security questions (I use actual dice to generate
my passwords). The program generates 10 different random phrases, you
should choose one that will be understood over the phone.

Using random characters for security questions is known to be bypassed
by false actors simply saying "a bunch of random letters, it would be
silly for me to say them all!"

Why use THIS one?
-----------------
A quick look through some of the many other generators shows they are
not trivially inspectable. You want to trust the code of your
passphrase generator! Even if you are not a skilled programmer, you
can look at ppgen.cpp and see it is dead simple with no room for dirty
tricks. Including the GPLv3 disclaimer, it is 53 lines. Even so you
can see:
    - It seeds the random number generator from your system's random
      device
    - It uses a uniform distribution
    - Its not python, so you can be confident from looking at the
      headers & Makefile it is definitely not doing something sneaky
      to talk to the internet.

Building
--------
    # make

Running
-------
    # ./ppgen

