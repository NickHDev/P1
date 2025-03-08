#ifndef token.h
#define token.h
#include <string>
enum tokenID {t1_tk,t2_tk,t3_tk};
std::string tokenNames[] = {"t1 token", "t2 token", "t3 token"};
struct token_t
{
    tokenID id;
    std::string instance;
    int lineNum;
};

#endif