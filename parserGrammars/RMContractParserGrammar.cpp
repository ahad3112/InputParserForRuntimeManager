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
    dist2predMap.insert(std::make_pair(std::string("default"), GAP_CONTROL::DEFAULT));
    dist2predMap.insert(std::make_pair(std::string("increase"), GAP_CONTROL::INCREASE));
}

void RMContractParserGrammar::parse(std::string &s, unsigned lineNo) {
    for(std::sregex_iterator it(s.begin(), s.end(), expression), end; it != end; ++it) {
        std::cout << "LineNo: " << lineNo << "\n" << it->str() << std::endl;
        //std::cout << "Found:::::: " << (*it)[4].str() << std::endl;
        evaluate(*it, lineNo);
    }
}

void RMContractParserGrammar::evaluate(const std::smatch &match, unsigned lineNo) {
    auto ctype = ctypeMap.find(match[2].str());
    if (ctype == ctypeMap.end()) throw std::runtime_error("missing ctype!!!");
    auto c2l = qualityMap.find(match[4]);
    if (c2l == qualityMap.end()) throw std::runtime_error("missing c2l!!!");
    auto c2f = qualityMap.find(match[6]);
    if (c2f == qualityMap.end()) throw std::runtime_error("missing c2f!!!");
    auto mode = controllerMap.find(match[8]);
    if (mode == controllerMap.end()) throw std::runtime_error("missing mode!!!");

    if(match[9].matched && match[12].matched) {
        // Sanity checking, if passed, generate the Contract instance
        if(match[8] == match[11]) {
            std::string error = "Value for mode and transition2mode are equal on line no: " + std::to_string(lineNo);
            throw std::runtime_error(error);
        }
        auto transition2mode = controllerMap.find(match[11]);
        if (transition2mode == controllerMap.end()) throw std::runtime_error("missing transition2mode!!!");
        auto dist2pred = dist2predMap.find(match[14]);
        if (dist2pred == dist2predMap.end()) throw std::runtime_error("missing dist2pred!!!");

        // add contract
        std::cout << "ctype : " << ctype->second
                  << " c2l : " << c2l->second
                  << " c2f : " << c2f->second
                  << " mode : " << mode->second
                  << " transition2mode : " << transition2mode->second
                  << " dist2pred : " << dist2pred->second
                  << std::endl;

    } else if (match[9].matched) {
        // Sanity checking, if passed, generate the Contract instance
        if(match[8] == match[11]) {
            std::string error = "Value for mode and transition2mode are equal on line no: " + std::to_string(lineNo);
            throw std::runtime_error(error);
        }
        auto transition2mode = controllerMap.find(match[11]);
        if (transition2mode == controllerMap.end()) throw std::runtime_error("missing transition2mode!!!");

        // add contract
        std::cout << "ctype : " << ctype->second
                  << " c2l : " << c2l->second
                  << " c2f : " << c2f->second
                  << " mode : " << mode->second
                  << " transition2mode : " << transition2mode->second
                  << std::endl;
    } else if (match[12].matched) {
        auto dist2pred = dist2predMap.find(match[14]);
        if (dist2pred == dist2predMap.end()) throw std::runtime_error("missing dist2pred!!!");

        // add contract
        std::cout << "ctype : " << ctype->second
                  << " c2l : " << c2l->second
                  << " c2f : " << c2f->second
                  << " mode : " << mode->second
                  << " dist2pred : " << dist2pred->second
                  << std::endl;
    } else {
        throw std::runtime_error("missing guarantee!!!");
    }

}
