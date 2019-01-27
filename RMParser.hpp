/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#ifndef CONTRACT_PARSER_RMPARSER_HPP
#define CONTRACT_PARSER_RMPARSER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include "parserGrammars/RMParserGrammar.hpp"
#include "parserGrammars/RMContractParserGrammar.hpp"

/**
 * This is used to defined what kind of Grammar is required to parse input file
 *  Designed this way for possible future extension
 */
enum class ParserGrammarType {
    CONTRACT,
};

/**
 * This is starting point of the RMParser
 */
class RMParser {
public:
    RMParser(std::string inputFilename);
    ~RMParser();
    void addContract();     // TODO... parameter will be added later
private:
    void initGrammars();
    void parse();
    // a ifstream object to read input file
    std::ifstream input;
    // A map of ParserGrammarType and RMParserGrammar
    std::map<ParserGrammarType , std::shared_ptr<RMParserGrammar>>  parserGrammars;
};

// Non-member function
std::string removeCommentsAndTrim(std::string &s);
std::string removeComments(std::string &s);
std::string trim(std::string &s);
std::string left_trim(std::string &s);
std::string right_trim(std::string s);

#endif //CONTRACT_PARSER_RMPARSER_HPP
