/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#ifndef CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP
#define CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP


#include "RMParserGrammar.hpp"

class RMContractParserGrammar : public RMParserGrammar{
public:
    RMContractParserGrammar();
    ~RMContractParserGrammar() override;

    void parse(std::string &s) override;
private:
    void initRegexPattern();
};


#endif //CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP
