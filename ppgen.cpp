/*  This program is free software: you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see
    <http://www.gnu.org/licenses/>. */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <random>
#include "pcg_random.hpp"
#include "diceware_wordlist.h"
#include "eff_wordlist.h"

int main(int argc, char** arg_begin)
{
    /* Parse arguments. --diceware to use diceware wordlist, -n 10 to get 10 word passphrases */
    using namespace std::string_literals;
    char **arg_end = arg_begin + argc;
    bool use_diceware = std::find(arg_begin, arg_end, "--diceware"s) != arg_end;
    long num_words = 6;
    auto num_words_arg = std::find(arg_begin, arg_end, "-n"s);
    if (num_words_arg != arg_end && num_words_arg + 1 != arg_end)
        num_words = strtol(num_words_arg[1], NULL, 0);

    using wordlist_t = std::array<const char *, 7776>;
    const wordlist_t& wordlist = use_diceware ? diceware_wordlist : eff_wordlist;

    std::cout << "ppgen  Copyright © 2016 Andrew Potter\n"
              << "This program comes with ABSOLUTELY NO WARRANTY;\n"
              << "This is free software, and you are welcome to redistribute it\n"
              << "under certain conditions.\n\n";

    if (num_words <= 0) {
        std::cout << "Number of words must be a postive numeral (not \"" << num_words_arg[1] << "\").\n";
        return EXIT_FAILURE;
    }

    std::cout << "Using " << num_words << " words will give you "
              << std::log2(wordlist.size()) * num_words << " bits of entropy.\n\n";

    pcg_extras::seed_seq_from<std::random_device> seed_source;
    pcg64 rng(seed_source);
    std::uniform_int_distribution<wordlist_t::size_type> dis {0, wordlist.size() - 1};

    std::cout << "Choose from one of these 10 passphrases:\n\n";
    for (int gen_num = 0; gen_num < 10; ++gen_num) {
        for (long word = 0; word < num_words; ++word) {
            std::cout << wordlist[dis(rng)] << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
