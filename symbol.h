#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "type.h"

typedef enum 
{
	_universal, _global, _local, _nested
}Scope;

typedef struct symbol
{
	char *symbol_name;
	token_type symbol_type;
	Scope scope;
	struct symbol_link *prev_link;
	struct symbol_link *next_link;
} symbol_link;


symbol_link* look_up(symbol_link* head_link, token* traited_token, Scope scope);
symbol_link* create_symbol(char *name, token_type type, Scope scope);
symbol_link* insert_symbol(symbol_link* head_link, char* symbol_name, token_type type);
void print_symbol_table(symbol_link *head_link);



#endif