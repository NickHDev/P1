#ifndef scanner_h
#define scanner_h
#include <iostream>
#include <fstream>
#include <string>
#include "token.h"

token_t scanner(FILE *);
token_t token_IN(int, std::string);
inputChar filter(FILE *);
int getColNum(char);
void setLookAhead(FILE *);
#endif