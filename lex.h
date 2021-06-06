#ifndef LEX_H
#define LEX_H

#include "type.h"



token lexer();
token retrieve_tokens();

extern token create_token(token_type token_represent, const char *buffer, int length);
extern void destroy_token(token new_token);


void print_token(token new_token, int line_num);
#endif // !LEX_H


