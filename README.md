ppgen
=====
Passphrase Generator

Requirements
------------
C++14 compiler.

Building
--------
# make

Running
-------
# ./ppgen

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