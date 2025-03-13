#include <iostream>
#include <fstream>
#include <vector>
#include "scanner.h"
#include "testScanner.h"
void testScanner(std::string input, int lineNum, int colNum)
{
    token_t tk;
    std::vector<std::string> substrs;
    std::string substr = "";

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == EOF)
        {
            substrs.push_back(substr);
            substr = "";
        }
        if (input[i] == ' ')
        {
            if (substr != "")
            {
                substrs.push_back(substr);
                substr = "";
            }
        }
        else
        {
            substr += input[i];
        }
    }
    if (!substr.empty())
    {
        substrs.push_back(substr);
    }
    for (int i = 0; i < substrs.size(); i++)
    {
        for (int j = 0; j < substrs[i].length(); j++)
        {
            if (substrs[i][j] == ' ')
            {
                colNum = 5;
            }
            else if (substrs[i][j] >= 33 && substrs[i][j] <= 41)
            {
                colNum = 4;
            }
            else if (substrs[i][j] == '+')
            {
                colNum = 3;
            }
            else if (substrs[i][j] >= 48 && substrs[i][j] <= 57)
            {
                colNum = 2;
            }
            else if (substrs[i][j] >= 65 && substrs[i][j] <= 90)
            {
                colNum = 1;
            }
            else if (substrs[i][j] >= 97 && substrs[i][j] <= 122)
            {
                colNum = 1;
            }
            else if (substrs[i][j] == EOF || substrs[i][j] == '\n' || substrs[i][j] == '\0')
            {
                colNum = 0;
            }
            else
            {
                printf("Error: Invalid character : not in range\n");
            }
            tk = scanner(substrs[i][j], colNum);
            std::cout << tokenNames[tk.id] << "  " << tk.name << "  " << lineNum << std::endl;
        }
    }
}