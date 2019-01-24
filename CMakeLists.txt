cmake_minimum_required(VERSION 3.13)
project(contract_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(contract_parser main.cpp RMParser.cpp RMParser.hpp parserGrammars/RMParserGrammar.cpp parserGrammars/RMParserGrammar.hpp parserGrammars/RMContractParserGrammar.cpp parserGrammars/RMContractParserGrammar.hpp)