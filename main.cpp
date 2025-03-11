/*
Author: Nicholas Hieb
Date Created: 2/08/2025
This is our main file to get input from the user or file and parse the file and output the traversal files.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "scanner.h"
#include "testScanner.h"
int main(int argc, char *argv[]) 
{
    std::string input;

    if (argc == 1)
    {
        std::cout << "Keep typeing until 'ctrl + d' is entered to end input: \n";
        while (getline(std::cin, input))
        {
            testScanner(input, std::cin.get());
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
        while (getline(file, input))
        {
            std::cout << input << " Input In main." <<  std::endl;
            testScanner(input, input[0]);
        }
    }
    else
    {
        std::cerr << "Error: Too many arguments" << std::endl;
        return 1;
    }
}