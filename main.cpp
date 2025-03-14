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
int main(int argc, char *argv[])
{
    std::string input;
    int lineNum = 0;
    FILE *fileptr = NULL;

    if (argc == 1)
    {
        std::cout << "Keep typeing until 'ctrl + d' is entered to end input: \n";
        std::cin >> input;
        FILE *fileptr = fopen(input.c_str(), "r");
        testScanner(fileptr);
    }
    else if (argc == 2)
    {
        fileptr = fopen(argv[1], "r");
        if (!fileptr)
        {
            std::cerr << "Error: File not found" << std::endl;
            return 1;
        }
        else
        {
            testScanner(fileptr);
        }
    }
    else
    {
        std::cerr << "Error: Too many arguments" << std::endl;
        return 1;
    }
}