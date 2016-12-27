ppgen
=====
Passphrase Generator

Requirements
------------
C++14 compiler, acceptance of GPLv3+.

Description
-----------

This simple command line program utilizes the
[EFF](https://www.eff.org/deeplinks/2016/07/new-wordlists-random-passphrases)
or [Diceware](http://world.std.com/~reinhold/diceware.html) wordlist
to generate a passphrase with the number of words you desire. I use it
to generate answers to security questions.

Why use THIS one?
-----------------
A quick look through some of the many other generators shows they are
not trivially inspectable. You want to trust the code of your
passphrase generator! Even if you are not a skilled programmer, you
can look at ppgen.cpp and see it is dead simple with no room for dirty
tricks. Including the GPLv3 disclaimer, it is 64 lines. So you can
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
The default wordlist was created by the [Electronic Frontier
Foundation](https://www.eff.org)
([@EFForg](https://github.com/EFForg)), provided under the Creative
Commons CC-BY 3.0 license. You can read their design criteria
[here](https://www.eff.org/deeplinks/2016/07/new-wordlists-random-passphrases),
and you can read about how to use physical dice to generate your
passphrases [here](https://www.eff.org/dice).

The alternative wordlist comes from the classic
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

    Using 6 words will give you 77.5489 bits of entropy.

    Choose from one of these 10 passphrases:

    untried umbilical detection spoken moonshine reps
    storage immersion unshipped moaner empirical renewably
    devotee prancing chewing climatic erasable backache
    herself theology enlisted bobble skyward unlisted
    harmful sabotage undefined knickers marlin case
    tiger confider recluse populace relocate ecology
    demeaning scooter naturist provider relieve nastiness
    magnitude flounder scratch caddie plug earplugs
    cornball unbridle depraved gerbil bundle engaging
    freewill diaphragm guzzler amigo unbaked magnetize

    # ./ppgen --diceware -n 10
    ppgen  Copyright © 2016 Andrew Potter
    This program comes with ABSOLUTELY NO WARRANTY;
    This is free software, and you are welcome to redistribute it
    under certain conditions.

    Using 10 words will give you 129.248 bits of entropy.

    Choose from one of these 10 passphrases:

    disk flat slain puck cook menlo extra ue 42nd 7
    due useful cecil tardy warty evil skim cock apex yap
    chess mobil hoyt aiken errand fed carob jerry dull billy
    cheek ghent cozy lane infra nymph pate krause red cruel
    asset seat marks ruin hand wiley warmth patch aver 4th
    almost oa align image bauer warm js madman cairo cider
    stu basel dj rode 29th tonsil flout muslim tid usage
    exact sara green label bacon yond ez march that alba
    gain + cj muggy usage akin gc prom vo byrne
    over ive buck preen hay vv cauchy sturm ghetto smug
