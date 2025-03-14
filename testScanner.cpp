#include <iostream>
#include <fstream>
#include <vector>
#include "scanner.h"
#include "testScanner.h"
void testScanner(std::FILE *input)
{
    token_t tk;

    setLookAhead(input);

    while (tk.id != EOF_tk)
    {
        tk = scanner(input);
        std::cout << tokenNames[tk.id] << "  " << tk.name << "  " << tk.lineNum << std::endl;
    }
}


