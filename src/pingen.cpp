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

#include <iostream>
#include <random>
#include "pcg_random.hpp"

int main(int argc, char** arg_begin)
{
    using namespace std::string_literals;
    char **arg_end = arg_begin + argc;
    bool no_repeats = std::find(arg_begin, arg_end, "--no-repeats"s) != arg_end;
    long num_digits = 4;
    auto num_digits_arg = std::find(arg_begin, arg_end, "-n"s);
    if (num_digits_arg != arg_end && num_digits_arg + 1 != arg_end)
        num_digits = strtol(num_digits_arg[1], NULL, 0);

    std::cout << "pingen  Copyright © 2016 Andrew Potter\n"
              << "This program comes with ABSOLUTELY NO WARRANTY;\n"
              << "This is free software, and you are welcome to redistribute it\n"
              << "under certain conditions.\n\n";

    if (num_digits <= 0) {
      std::cout << "Number of digits must be a positive numeral (not \"" << num_digits_arg[1] << "\").\n";
      return EXIT_FAILURE;
    }

    pcg_extras::seed_seq_from<std::random_device> seed_source;
    pcg64 rng(seed_source);
    std::uniform_int_distribution<unsigned int> dis {0, 9};
    unsigned int prev_r = 10;

    std::cout << "Your random ";
    if (no_repeats)
      std::cout << "(with no repeating digits) ";
    std::cout << "PIN: ";

    for (long digit = 0; digit < num_digits; ++digit) {
      auto r = dis(rng);
      while (no_repeats && r == prev_r)
	r = dis(rng);
      std::cout << r;
      prev_r = r;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
