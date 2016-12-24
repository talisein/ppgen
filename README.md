ppgen
=====
Passphrase Generator

Requirements
------------
C++14 compiler, acceptance of GPLv3+.

Description
-----------

This simple command line program utilizes the
[Diceware](http://world.std.com/~reinhold/diceware.html) wordlist to
generate a passphrase with the number of words you desire. I use it to
generate answers to security questions. The program generates 10
different random phrases, you should choose one that will be
understood over the phone.

Why use THIS one?
-----------------
A quick look through some of the many other generators shows they are
not trivially inspectable. You want to trust the code of your
passphrase generator! Even if you are not a skilled programmer, you
can look at ppgen.cpp and see it is dead simple with no room for dirty
tricks. Including the GPLv3 disclaimer, it is 53 lines. So you can
plainly see:

- It seeds the random number generator from your system's random
  device.
- It uses a uniform distribution.
- Its not python, so you can be confident from looking at the
  headers & Makefile it is definitely not doing something sneaky
  to talk to the internet.
- I've GPG-signed all commits.

Thanks to
---------
The wordlist comes from
[Diceware](http://world.std.com/~reinhold/diceware.html), by Arnold
Reinhold ([@agreinhold](https://github.com/agreinhold)). He has
provided the wordlist under the Creative Commons CC-BY 3.0 license.

The random number generator used is the
[PCG-Random](http://www.pcg-random.org/) C++ library, by Melissa
O'Neill ([@imneme](https://github.com/imneme)). While I am normally
partial to pure STL implementations, Prof. O'Neill makes a compelling
case that the C++14 RNG toolkit has too many shortcomings. This
library is available under the Apache 2.0 license.

Building & Running
------------------
    # make
    # sudo make install # (Optional)
    # ./ppgen
    ppgen  Copyright © 2016 Andrew Potter
    This program comes with ABSOLUTELY NO WARRANTY;
    This is free software, and you are welcome to redistribute it
    under certain conditions.

    Number of words in passphrase: 10

    Okay, 10 words will give you 129.248 bits of entropy.

    Choose from one of these 10 passphrases:

    19 randy chris bade judo kind atomic bit wm lilt
    back yo blanc cede melee seth wafer raj van agile
    punt hobby ghi till virus tori rm pewee issue 67
    saga vj vf stout ogden row snake silly fs plant
    botch dice gog dais manor van xx livre gwen feet
    eta papaw citrus dill manor kane cody blare hoyt tithe
    waggle ail saxon daly orbit hippy flask zone indy eater
    yz goat taut mario blithe brady bragg lust bunny thyme
    arc nook karl ampex 1000 snark tap agent cooky sheet
    ebb bern tabula prow edgy 4321 day stork xw 1925

