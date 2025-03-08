#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "scanner.h"
token_t token_IN(int ID)
{
    token_t tk;
    if (ID >= 1000)
    {
        switch (ID)
        {
        case 1000:
            return tk = {t1_tk};
            break;
        case 1001:
            return tk = {t2_tk};
            break;
        case 1002:
            return tk = {t3_tk};
            break;
        case 1003:
            return tk = {EOF_tk};
            break;
        default:
            perror("Error: Invalid token");
            exit(1);
        }
    }
    else if (ID < 0)
    {
        perror("invalid token");
        exit(1);
    }
}

token_t FADriver()
{
    int state = 0;
    int nextState = 0;
    std::string S = "";

    while (state < 1000 && state >= 0)
    {
        nextState = Table[state][nextChar];
        if (nextState < 0)
        {
            perror("Error: Invalid character");
            exit(1);
        }
        if (nextState >= 1000)
        {
            return token_IN(nextState);
        }
        else
        {
            state = nextState;
            append(S, nextChar);
            nextChar = getchar();
        }
    }
}