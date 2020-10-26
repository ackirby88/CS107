#ifndef LONGEST_SENTENCE_HPP
#define LONGEST_SENTENCE_HPP

/* system header files */
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

/* header files */
#include "linked_list_soln.hpp"

static std::string trim(const std::string& str){
    size_t first = str.find_first_not_of(" \n\t\r\v");
    size_t last = str.find_last_not_of(" \n\t\r\v");
    return str.substr(first, (last-first+1));
}

static
void findAndReplaceAll(std::string &data, std::string toSearch, std::string replaceStr){
    size_t pos = data.find(toSearch);
    while (pos != std::string::npos) {
        data.replace(pos, toSearch.size(), replaceStr);
        pos = data.find(toSearch, pos + replaceStr.size()); // get next occurance
    }
}

#define OUT 0
#define IN 1

// returns number of words in str
static
unsigned countWords(const char *str){
    int state = OUT;
    unsigned wc = 0; // word count

    // Scan all characters one by one
    while (*str) {
        // If next character is a separator, set the state as OUT
        if(*str == ' ' || *str == '\n' || *str == '\t') {
            state = OUT;

        // If next character is not a word separator and
        // state is OUT, then set the state as IN and
        // increment word count
        } else if (state == OUT) {
            state = IN;
            ++wc;
        }

        // Move to next character
        ++str;
    }
    return wc;
}

#endif /* LONGEST_SENTENCE_HPP */
