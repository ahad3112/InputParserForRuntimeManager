/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#ifndef CONTRACT_PARSER_PARSERGRAMMAR_HPP
#define CONTRACT_PARSER_PARSERGRAMMAR_HPP

#include <regex>

class RMParserGrammar {
public:
    RMParserGrammar();
    virtual ~RMParserGrammar() = 0;
protected:
    std::regex pattern;
};


#endif //CONTRACT_PARSER_PARSERGRAMMAR_HPP