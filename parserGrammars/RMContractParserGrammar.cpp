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
    initParametersValueMap();
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

void RMContractParserGrammar::initParametersValueMap() {
    // CONTRACT_TYPE
    ctypeMap.insert(std::make_pair(std::string("wifi"), CONTRACT_TYPE::WIFI));
    // QUALITY
    qualityMap.insert(std::make_pair(std::string("ok"), QUALITY::OK));
    qualityMap.insert(std::make_pair(std::string("poor"), QUALITY::POOR));
    qualityMap.insert(std::make_pair(std::string("critical"), QUALITY::CRITICAL));
    // ACTIVE_CONTROLLER
    controllerMap.insert(std::make_pair(std::string("acc"), ACTIVE_CONTROLLER::ACC));
    controllerMap.insert(std::make_pair(std::string("ploeg"), ACTIVE_CONTROLLER::PLOEG));
    controllerMap.insert(std::make_pair(std::string("cacc"), ACTIVE_CONTROLLER::CACC));
    // GAP_CONTROL
    gapcontrolMap.insert(std::make_pair(std::string("default"), GAP_CONTROL::DEFAULT));
    gapcontrolMap.insert(std::make_pair(std::string("increase"), GAP_CONTROL::INCREASE));
}

void RMContractParserGrammar::parse(std::string &s, unsigned lineNo) {
    for(std::sregex_iterator it(s.begin(), s.end(), expression), end; it != end; ++it) {
        //std::cout << "LineNo: " << lineNo << "\n" << it->str() << std::endl;
        //std::cout << "Found:::::: " << (*it)[4].str() << std::endl;
        evaluate(*it, lineNo);
    }
}

void RMContractParserGrammar::evaluate(const std::smatch &match, unsigned lineNo) {
    // Sanity checking, if passed, generate the Contract instance
    if(match[9].matched) {
        if(match[8] == match[11]) {
            std::string error = "Value for mode and transition2mode are equal on line no: " + std::to_string(lineNo);
            throw std::runtime_error(error);
        }
    }
    // TODO : we can add more sanity checking later if time permits
    // Now create the instance of Contract and add to the RMCGContainer
}
