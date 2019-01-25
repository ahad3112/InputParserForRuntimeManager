/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#include <iostream>
#include "RMContractParserGrammar.hpp"

////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////
RMContractParserGrammar::RMContractParserGrammar() {
    initRegexPattern();
}

////////////////////////////////////////////////////
// Destructor
////////////////////////////////////////////////////
RMContractParserGrammar::~RMContractParserGrammar() {

}
////////////////////////////////////////////////////
// Member function
////////////////////////////////////////////////////
void RMContractParserGrammar::initRegexPattern() {
    std::string contractPattern = "::contract\\s*\\[\\s*"
                                  "(ctype)\\s*=\\s*(wifi)\\s*[:]+\\s*"
                                  "(c2f)\\s*=\\s*(ok|poor|critical)[\\s;]+"
                                  "(c2l)\\s*=\\s*(ok|poor|critical)[\\s;]+"
                                  "(mode)\\s*=\\s*(acc|ploeg|cacc)\\s*[:]+\\s*"
                                  "((transition2mode)\\s*=\\s*(acc|ploeg|cacc)[\\s;]*)?"
                                  "((dist2pred)\\s*=\\s*(default|increase)[\\s;]*)?"
                                  "\\]";
    expression = std::regex(contractPattern, std::regex::icase);
}

void RMContractParserGrammar::parse(std::string &s) {
    for(std::sregex_iterator it(s.begin(), s.end(), expression), end; it != end; ++it) {
        std::cout << "Found:::::: " << it->str() << std::endl;
        //std::cout << "Found:::::: " << (*it)[14].str() << std::endl;
    }
}
