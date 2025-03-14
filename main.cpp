/*
Author: Nicholas Hieb
Date Created: 3/05/2025
This is our main file to get input from the user or file and parse the file and output the scanned tokens.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"
// Main function to get the input from user or file and scan the file
int main(int argc, char *argv[])
{
    std::string input, output;
    int lineNum = 0;
    FILE *fileptr = NULL;

    if (argc == 1)
    {
        // Get input from user
        std::cout << "Keep typeing until 'ctrl + d' is entered to end input: \n";
        while(std::cin >> input)
        {
            output += input + "\n";
        }
        fileptr = fmemopen((void *)output.c_str(), output.size(), "r");
        testScanner(fileptr);
    }
    else if (argc == 2)
    {
        // Get input from file
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