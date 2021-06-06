#include "check_word.h"


bool user_function(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 3; i++)
	{
		if (strcmp(function_type[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(function_type[i].str_ptr, "read") == 0)
			{
				new_token->token_represent = _read;
				return true;
			}
			if (strcmp(function_type[i].str_ptr, "write") == 0)
			{
				new_token->token_represent = _write;
				return true;
			}
			if (strcmp(function_type[i].str_ptr, token_strand) == 0)
			{
				if (strcmp(function_type[i].str_ptr, "assign") == 0)
				{
					new_token->token_represent = _assign;
					return true;
				}
			}

		}
	}
	return false;
}

bool data_types(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;


	for (i = 0; i < 8; i++)
	{
		if (strcmp(data_type[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(data_type[i].str_ptr, "hollow") == 0)
			{
				new_token->token_represent = _hollow;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "num") == 0)
			{
				new_token->token_represent = _num;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "deci") == 0)
			{
				new_token->token_represent = _deci;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "mark") == 0)
			{
				new_token->token_represent = _mark;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "strand") == 0)
			{
				new_token->token_represent = _strand_literal;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "return") == 0)
			{
				new_token->token_represent = _return;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "yield") == 0)
			{
				new_token->token_represent = _yield;
				return true;
			}
		}
	}
	return false;
}

bool manager_types(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 5; i++)
	{

		if (strcmp(manager_type[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(manager_type[i].str_ptr, "manager") == 0)
			{
				new_token->token_represent = _manager;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "hide") == 0)
			{
				new_token->token_represent = _private;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "show") == 0)
			{
				new_token->token_represent = _public;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "elem") == 0)
			{
				new_token->token_represent = _elem;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "object") == 0)
			{
				new_token->token_represent = _object;
				return true;
			}
		}
	}
	return false;
}

bool header_types(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 4; i++)
	{
		if (strcmp(preprocess_header[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(preprocess_header[i].str_ptr, "use") == 0)
			{
				new_token->token_represent = _use;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "define") == 0)
			{
				new_token->token_represent = _define;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "link") == 0)
			{
				new_token->token_represent = _link;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "translate") == 0)
			{
				new_token->token_represent = _translate;
				return true;
			}
		}
	}
	return false;
}



bool subheader_types(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 2; i++)
	{
		if (strcmp(sub_header[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(sub_header[i].str_ptr, "haven") == 0)
			{
				new_token->token_represent = _haven;
				return true;
			}
			if (strcmp(sub_header[i].str_ptr, "io") == 0)
			{
				new_token->token_represent = _io;
				return true;
			}
		}
	}
	return false;
}

bool file_types(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 1; i++)
	{
		if (strcmp(file_type[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(file_type[i].str_ptr, "file") == 0)
			{
				new_token->token_represent = _file;
				return true;
			}
		}
	}
	return false;
}

bool data_tool(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 12; i++)
	{
		if (strcmp(data_tools[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(data_tools[i].str_ptr, "check") == 0)
			{
				new_token->token_represent = _check;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "else") == 0)
			{
				new_token->token_represent = _else;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "loop") == 0)
			{
				new_token->token_represent = _loop;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "set") == 0)
			{
				new_token->token_represent = _set;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "pare") == 0)
			{
				new_token->token_represent = _pare;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "compare") == 0)
			{
				new_token->token_represent = _compare;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "list") == 0)
			{
				new_token->token_represent = _list;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "construct") == 0)
			{
				new_token->token_represent = _construct;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "log") == 0)
			{
				new_token->token_represent = _log;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "bridge") == 0)
			{
				new_token->token_represent = _bridge;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "table") == 0)
			{
				new_token->token_represent = _table;
				return true;
			}
		}
	}
	return false;
}

bool data_modifier_type(token * new_token)
{
	int i = 0;
	char *token_strand = new_token->token_strand;
	int length = 0;

	for (i = 0; i < 8; i++)
	{
		if (strcmp(data_modifier[i].str_ptr, token_strand) == 0)
		{
			if (strcmp(data_modifier[i].str_ptr, "short") == 0)
			{
				new_token->token_represent = _short;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "long") == 0)
			{
				new_token->token_represent = _long;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "signed") == 0)
			{
				new_token->token_represent = _signed;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "unsigned") == 0)
			{
				new_token->token_represent = _unsigned;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "static") == 0)
			{
				new_token->token_represent = _static;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "extern") == 0)
			{
				new_token->token_represent = _external;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "extern") == 0)
			{
				new_token->token_represent = _internal;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "register") == 0)
			{
				new_token->token_represent = _register;
				return true;
			}
		}
	}
	return false;
}



bool check_ident(token *new_token)
{
	new_token->token_represent = _ident;
	return true;
}
