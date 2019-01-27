/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#ifndef CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP
#define CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP

#include <map>
#include "RMParserGrammar.hpp"

// The following enum will be replaced from the RM
enum CONTRACT_TYPE {
    WIFI,
    INTERNAL_ERROR,
};

enum QUALITY {
    OK,
    POOR,
    CRITICAL,
};

enum ACTIVE_CONTROLLER {
    ACC,
    PLOEG,
    CACC,
};

enum GAP_CONTROL {
    DEFAULT,
    INCREASE,
};

class RMContractParserGrammar : public RMParserGrammar{
public:
    RMContractParserGrammar();
    ~RMContractParserGrammar() override;

    void parse(std::string &s, unsigned lineNo) override;
private:
    void initRegexPattern();
    void initParametersValueMap();
    void evaluate(const std::smatch &match, unsigned lineNo);

    std::map<std::string, CONTRACT_TYPE> ctypeMap;
    std::map<std::string, QUALITY> qualityMap;
    std::map<std::string, ACTIVE_CONTROLLER > controllerMap;
    std::map<std::string, GAP_CONTROL > dist2predMap;
};

#endif //CONTRACT_PARSER_RMCONTRACTPARSERGRAMMAR_HPP
