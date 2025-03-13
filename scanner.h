#ifndef scanner_h
#define scanner_h
#include <iostream>
#include <fstream>
#include <string>
#include "token.h"

token_t scanner(char,int);
token_t token_IN(int, std::string);
#endif