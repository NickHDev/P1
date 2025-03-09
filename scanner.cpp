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
            tk.id = t1_tk;
            return tk;
            break;
        case 1001:
            tk.id = t2_tk;
            return tk;
            break;
        case 1002:
            tk.id = t3_tk;
            return tk;
            break;
        case 1003:
            tk.id = EOF_tk;
            return tk;
            break;
        default:
            perror("Error: Invalid token");
            exit(1);
        }
    }
    else if (ID < 0)
    {
        perror("invalid token less than 0");
        exit(1);
    }
    else
    {
        if (ID == 0)
        {
            tk.lineNum++;
        }
        return tk;
    }
}

token_t scanner(std::string input)
{
    int state = 0;
    int nextState = 0;
    char nextChar = input[0];
    int lineNum = 1;
    int colNum = 0;
    std::string S = "";
    if (nextChar >= 33 && nextChar <= 41)
    {
        colNum = 0;
    }
    else if (nextChar == '+' && S.length() == 0)
    {
        colNum = 1;
    }
    else if (nextChar >= 97 && nextChar <= 122)
    {
        colNum = 2;
    }
    else if (nextChar >= 65 && nextChar <= 90)
    {
        colNum = 2;
    }
    else
    {
        colNum = 5;
    }

    while (state < 1000 && state >= 0)
    {
        if (nextChar >= 33 && nextChar <= 41)
        {
            colNum = 0;
        }
        else if (nextChar >= 97 && nextChar <= 122)
        {
            colNum = 2;
        }
        else if (nextChar >= 65 && nextChar <= 90)
        {
            colNum = 2;
        }
        else {
            colNum = 5;
        }
        std::cout << nextChar << std::endl;
        nextState = Table[state][colNum];
        if (nextState < 0)
        {
            perror("Error: Invalid character");
            exit(1);
        }
        if (nextState >= 1000)
        {
            token_IN(nextState, S);
            return token_IN(nextState, S);
        }
        else
        {
            state = nextState;
            S.append(nextChar, 1);
            nextChar = getchar();
        }
    }
}