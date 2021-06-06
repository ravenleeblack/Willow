#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "symbol.h"



symbol_link* create_symbol(char * name, token_type type, Scope scope)
{
	symbol_link *temp_symbol;
	temp_symbol = (symbol_link*)malloc(sizeof(symbol_link));
	temp_symbol->symbol_name = calloc(name, sizeof(char));

	
    strcpy(temp_symbol->symbol_name, name);
	

	temp_symbol->symbol_type = type;
	temp_symbol->scope = scope;

	temp_symbol->prev_link = NULL;
	temp_symbol->next_link = NULL;

	return temp_symbol;
}

symbol_link* insert_symbol(symbol_link* head_link, char* name, token_type type)
{
	if (type == _space || type == _neli)
	{
		return head_link;
	}

	if (head_link == NULL)
	{
		head_link = create_symbol(name, type, _universal);

	}
	else
	{
		symbol_link* link = head_link;

		Scope scope = link->scope;

		while(link->next_link != NULL)
		{
			link = link->next_link;
		}

		if (link->symbol_type == _lbracket)
		{
			switch (link->scope)
			{
			case _universal:	link->scope = _global;    break;
			case _global:       link->scope = _local;     break;
			case _local:        link->scope = _nested;    break;
			}
		}
		if (link->symbol_type == _rbracket)
		{
			switch (link->scope)
			{
			case _nested:   link->scope = _local;          break;
			case _local:    link->scope = _global;         break;
			case _global:	link->scope = _universal;      break;
			}
		}
		
	    symbol_link * new_link = create_symbol(name, type, scope);
		new_link->prev_link = link;
		link->next_link = new_link;
	}
	return head_link;
}

symbol_link* look_up(symbol_link *head_link, token *new_token, Scope scope)
{
	symbol_link* link = head_link;

	while(link != NULL)
	{
		if (link->symbol_name != NULL && strcmp(link->symbol_name, new_token->token_strand) == 0)
		{
			return link;
		}

		if (link->symbol_type, new_token->token_represent)
		{
			return link;
		}

		if (link->scope != NULL)
		{
			return link;
		}

		link = link->next_link;
	}
	return NULL;
}

void print_symbol_table(symbol_link *head_link)
{
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf(" universal          global          local          nested\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n");

	symbol_link* link = head_link;

	while (link != NULL)
	{
		if (link->scope == _universal) 
		{
			printf(" %s\n", link->symbol_name);
		}
		if (link->scope == _global)
		{
			printf(" |------------------%s\n", link->symbol_name);
		}
		if (link->scope == _local)
		{
			printf(" |---------------------------------%s\n", link->symbol_name);
		}
		if (link->scope == _nested) 
		{
			printf(" |------------------------------------------------%s\n", link->symbol_name);
		}

		link = link->next_link;
	}
}
