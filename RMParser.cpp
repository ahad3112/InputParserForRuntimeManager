/**************************************************
* Developed by: Muhammed Ahad
* E-mail      : maaahad@kth.se; ahad3112@yahoo.com
***************************************************/

#include "RMParser.hpp"
#include "parserGrammars/RMContractParserGrammar.hpp"

////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////
RMParser::RMParser(std::string inputFilename) {
    // open the input file, if succeed read line by line and create the list of Contracts to be considered by the runtime manager
    input.open(inputFilename, std::ios::in);
    if(!input) {
        std::cerr << inputFilename << " could not opened..." << std::endl;
        exit(-1);
    }
    // init the grammar list
    initGrammars();

    // File opened successfully. Lets start parsing the input
    parse();
}

////////////////////////////////////////////////////
// Desstructor
////////////////////////////////////////////////////
RMParser::~RMParser() {
    // The following close operation is not required, as this will be called automatically by the compiler once
    // the iftream goes out of the scope
    input.close();
    // No dynamically allocated memory(using built in pointer) is used by the class
}

////////////////////////////////////////////////////
// Member Function
////////////////////////////////////////////////////
void RMParser::initGrammars() {
    // This will be hard coded
    // CONTRACT Grammar
    parserGrammars.insert(std::make_pair(ParserGrammarType::CONTRACT, std::make_shared<RMContractParserGrammar>()));
    // [ Debug ===================
    std::cout << "CONTRACT grammar has been added to the RMParser" << std::endl;
    // ==================== Debug ]

    // TODO :: add more grammars if required (For further extension)
    // Right now we are only parsing contract from the input
}

void RMParser::parse() {

    std::cout << "RMParser start parsing the input file ...." << std::endl;
    // parse(std::string &line) from the appropriate Grammar class will be called after reading every line
    std::string line;
    while(std::getline(input, line)) {
        if(line.find("::contract") != std::string::npos && line.find("#") == std::string::npos) {
            std::cout << line << std::endl;
        }
        // call matchedGrammar.parse(line);
    }

    std::cout << "RMParser finished parsing the input file successfully." << std::endl;

}

////////////////////////////////////////////////////
// Non-Member Function
////////////////////////////////////////////////////
/**
 * String represents starting of comments
 */
std::string COMMENT = "#";          // add more character that can define start of comment
/**
* String represents starting of WHITESPACE
*/
std::string WHITESPACE = " ";       // add more character that can define WHITESPACE

std::string removeCommentsAndTrim(std::string &s) {
    std::string notComments = removeComments(s);
    return notComments.empty() ? notComments : trim(notComments);
}
std::string removeComments(std::string &s) {
    auto start = s.find_first_of(COMMENT);
    return (start == std::string::npos) ? s : s.substr(0, start);
}
std::string trim(std::string &s) {
    return right_trim(left_trim(s));
}
std::string left_trim(std::string &s) {
    auto start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
std::string right_trim(std::string s) {
    auto end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end+1);
}