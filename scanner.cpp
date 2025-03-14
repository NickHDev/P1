#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "scanner.h"
inputChar nextChar;
int lineNum = 0;

token_t scanner(FILE *input)
{
    int state = 0;
    int nextState;
    token_t tk;
    std::string S = "";

    while (state >= 0 && state < 1000)
    {
        nextState = Table[state][nextChar.colNum];
        if (nextState < 0)
        {
            printf("Error: Invalid character : less than 0");
            exit(1);
        }
        if (nextState >= 1000)
        {
            switch (nextState)
            {
            case 1000:
                tk.id = EOF_tk;
                break;
            case 1001:
                tk.id = t1_tk;
                break;
            case 1002:
                tk.id = t2_tk;
                break;
            case 1003:
                tk.id = t3_tk;
                break;
            default:
                break;
            }
            tk.name = S;
            tk.lineNum = nextChar.lineNum;
            return tk;
        }
        else
        {
            if (nextChar.c != ' ')
            {
                S.push_back(nextChar.c);
            }
            state = nextState;
            nextChar = filter(input);
        }
    }
    return tk;
}

inputChar filter(FILE *input)
{
    inputChar ic;
    char c = fgetc(input);
    int colNum = getColNum(c);
    while (colNum == '*')
    {
        c = fgetc(input);
        while (c != '*')
        {
            c = fgetc(input);
            if (c == '\n')
            {
                lineNum++;
            }
        }
        c = fgetc(input);
        colNum = getColNum(c);
    }

    if (colNum >= 0 && colNum <= 5)
    {   
        ic.c = c;
        ic.colNum = colNum;
        ic.lineNum = lineNum;
        if (c == '\n')
        {
            lineNum++;
        }
        return ic;
    }
    else
    {
        printf("Error: Invalid character : not in range\n");
        exit(1);
    }
}

int getColNum(char c)
{
    if (isspace(c))
    {
        return 5;
    }
    else if (c >= 33 && c <= 41)
    {
        return 4;
    }
    else if (c == '+')
    {
        return 3;
    }
    else if (isdigit(c))
    {
        return 2;
    }
    else if (isupper(c))
    {
        return 1;
    }
    else if (islower(c))
    {
        return 1;
    }
    else if (c == EOF || c == '\n' || c == '\0')
    {
        return 0;
    }
    else if (c == '*')
    {
        return '*';
    }
    else if (c == '/')
    {
        return '/';
    }
    else
    {
        printf("Error: Invalid character : not in range\n");
        return -1;
    }
}

void setLookAhead(FILE *input)
{
    nextChar = filter(input);
}