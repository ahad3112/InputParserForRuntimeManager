#include <iostream>
#include "RMParser.hpp"

int main() {
    //RMParser rmParser("/Users/maaahad/CLionProjects/contract_parser/contracts_input.txt");
    std::string test("ahah%      ::ahad#israt#jahan     #");
    std::cout << removeCommentsAndTrim(test) << std::endl;
    return 0;
}