#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    //std::string delimiters[3] = { "'", ".", " " };
    std::set<std::string> words;

    string wordSinceLastSplit = "";
    for (unsigned int i = 0; i < rawWords.length(); i++) {
        bool bDelim = false;
        
        char s1 = '.';
        char s2 = ' ';
        char s3 = '\'';
        if (rawWords[i] == s1 || rawWords[i] == s2 || rawWords[i] == s3)
        {
            bDelim = true;
        }
        if (bDelim == true) {
            if (wordSinceLastSplit.length() >= 2) {
                words.insert(wordSinceLastSplit);
            }
            wordSinceLastSplit = "";
        }
        else {
            wordSinceLastSplit += rawWords[i];
        }
    }
    if (wordSinceLastSplit.length() > 0) {
        words.insert(wordSinceLastSplit);
    }
    return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
