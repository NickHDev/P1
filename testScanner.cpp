#include <iostream>
#include <fstream>
#include "scanner.h"
#include "testScanner.h"
void testScanner(std::string input)
{
    token_t tk;
    while (tk.id != EOF_tk)
    {
        tk = scanner(input);
        std::cout << tokenNames[tk.id] << "  " << tk.name << "  " << tk.lineNum << std::endl;
    }
}