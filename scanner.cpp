#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "scanner.h"
token_t token_IN(int ID, std::string S)
{
    token_t tk;
    tk.name = S;
    if (ID >= 1000)
    {
        switch (ID)
        {
        case 1000:
            tk.id = EOF_tk;
            return tk;
            break;
        case 1001:
            tk.id = t1_tk;
            return tk;
            break;
        case 1002:
            tk.id = t2_tk;
            return tk;
            break;
        case 1003:
            tk.id = t3_tk;
            return tk;
            break;
        default:
            printf("Error: Invalid token in token in");
            exit(1);
        }
    }
    else
    {
        return tk;
    }
}

token_t scanner(std::string input, char nextChar)
{
    int state = 0;
    int nextState = 0;
    int lineNum = 1;
    int colNum = 0;
    int index = 0;
    std::string S = "";
    std::cout << "nextChar in scanner is " << nextChar << std::endl;
    std::cout << "input in scanner is " << input << std::endl;
    while (state < 1000 && state >= 0)
    {
        if (nextChar == ' ')
        {
            colNum = 5;
        }
        else if (nextChar >= 33 && nextChar <= 41)
        {
            colNum = 4;
        }
        else if (nextChar == '+')
        {
            colNum = 3;
        }
        else if (nextChar >= 48 && nextChar <= 57)
        {
            colNum = 2;
        }
        else if (nextChar >= 65 && nextChar <= 90)
        {
            colNum = 1;
        }
        else if (nextChar >= 97 && nextChar <= 122)
        {
            colNum = 1;
        }
        else if (nextChar == EOF || nextChar == '\n' || nextChar == 10)
        {
            colNum = 0;
        }
        else 
        {
            printf("Error: Invalid character : less than 0");
            exit(1);
        }
        std::cout << "colNum is " << colNum << " After assign" << std::endl;
        std::cout << "nextChar is " << nextChar << " After assign" << std::endl;
        std::cout << "state is " << state << " After assign" << std::endl;
        nextState = Table[state][colNum];
        if (nextState < 0)
        {
            printf("Error: Invalid character : less than 0");
            exit(1);
        }
        if (nextState >= 1000)
        {
            return token_IN(nextState, S);
        }
        else
        {
            state = nextState;
            S.push_back(nextChar);
            std::cout << "Buffer String: " << S << std::endl;
            index++;
            if (input[index] == '\n' || input[index] == EOF)
            {
                lineNum++;
                return token_IN(nextState, S);
            }
            else
            {
                nextChar = input[index];
            }

            std::cout << "Upcomng char is " << nextChar << std::endl;
        }
    }
    return token_IN(nextState, S);
}