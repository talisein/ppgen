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
    <http://www.gnu.org/licenses/>.
*/

#include <random>
#include <iostream>
#include <sstream>
#include "wordlist.h"

int main(int, char *[])
{
    std::cout << "ppgen  Copyright © 2016 Andrew Potter\n"
              << "This program comes with ABSOLUTELY NO WARRANTY;\n"
              << "This is free software, and you are welcome to redistribute it\n"
              << "under certain conditions.\n\n";

    int num_words;
    do {
        std::cout << "Number of words in passphrase: ";
        std::cin >> num_words;
        if (num_words <= 0) {
            std::cout << "Number of words must be a postive numeral (not \"" << num_words << "\").\n";
        }
    } while (num_words <= 0);

    std::cout << "Choose from one of these 10 passphrases:\n\n";

    std::stringstream passphrase;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, wordlist.size());

    for (int gen_num = 0; gen_num < 10; ++gen_num) {
        for (int word = 0; word < num_words; ++word) {
            passphrase << wordlist[dis(gen)] << " ";
        }
        std::cout << passphrase.str() << std::endl;
        passphrase.str("");
    }

    return 0;
}
