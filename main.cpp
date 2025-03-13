/*
Author: Nicholas Hieb
Date Created: 2/08/2025
This is our main file to get input from the user or file and parse the file and output the traversal files.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"
char nextChar;
int colNum = 0;
int main(int argc, char *argv[])
{
    std::string input;
    int lineNum = 0;

    if (argc == 1)
    {
        std::cout << "Keep typeing until 'ctrl + d' is entered to end input: \n";
        while (getline(std::cin, input))
        {
            nextChar = input[0];
            testScanner(input, lineNum, colNum);
            lineNum++;
        }
    }
    else if (argc == 2)
    {
        std::ifstream file(argv[1]);
        if (!file)
        {
            std::cerr << "Error: File not found" << std::endl;
            return 1;
        }
        else
        {
            while (getline(file, input))
            {
                nextChar = input[0];
                std::cout << " input in main" << input << std::endl;
                testScanner(input, lineNum, colNum);
                lineNum++;
            }
        }
    }
    else
    {
        std::cerr << "Error: Too many arguments" << std::endl;
        return 1;
    }
}