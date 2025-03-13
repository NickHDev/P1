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
        printf("Error: Invalid token in token in");
        exit(1);
    }
}

token_t scanner(char nextChar, int colNum)
{
    int state = 0;
    int nextState;
    std::string S = "";

    while (state >= 0 && state < 1000)
    {
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
        }
    }
    return token_IN(nextState, S);
}