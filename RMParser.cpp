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
        std::cout << line << std::endl;
        // call matchedGrammar.parse(line);
    }

    std::cout << "RMParser finished parsing the input file successfully." << std::endl;

}