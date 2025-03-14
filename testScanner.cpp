/*
Author: Nicholas Hieb
Date Created: 3/05/2025
This is the test file to get tokens.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "scanner.h"
#include "testScanner.h"
// Function to get tokens from the scanner and print them out
// OR3 and OR1
void testScanner(std::FILE *input)
{
    token_t tk;
    // Get the upcoming character
    setLookAhead(input);

    while (tk.id != EOF_tk)
    {
        tk = scanner(input);
        std::cout << tokenNames[tk.id] << "  " << tk.name << "  " << tk.lineNum << std::endl;
    }
}
