#include <iostream>
#include <fstream>
#include "scanner.h"
#include "testScanner.h"
void testScanner(std::string input, char nextChar)
{
    token_t tk;

    std::cout << "nextChar In testScanner is " << nextChar << std::endl;
    tk = scanner(input, nextChar); 
    std::cout << tokenNames[tk.id] << "  " << tk.name << "  " << tk.lineNum << std::endl;
}