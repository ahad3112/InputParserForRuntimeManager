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
    virtual void parse(std::string &s, unsigned lineNo) = 0;
protected:
    std::regex expression;
};


#endif //CONTRACT_PARSER_PARSERGRAMMAR_HPP
