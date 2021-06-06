#include <stdio.h>
#include "lex.h"
#include "check_word.h"
#include "symbol.h"
#include "print_token.h"


token lexer()
{
	int length = 0;
	char ch = 0;
	int line_num = 0;
	int comment = 0;

	token *token_ptr;
	token new_token;
	token_ptr = &new_token;


	//remove comments
	if((ch = fgetc(file)) != EOF && length < 1000)
	{
		ungetc(ch, file);

		line_num++;

		char ch = fgetc(file);

		if (ch == '/')
		{
			char ch_two = fgetc(file), can_finish = 0, finish_char = '\0';
			if (ch_two == '/')
			{
				finish_char = '\n';
				comment = 1;
			}
			else if (ch_two == '*')
			{
				finish_char = '*';
				comment = 1;
			}
			else
			{
				ungetc(ch_two, file);
			}
			if (finish_char)
			{
				while (true)
				{
					ch_two = fgetc(file);
					if (ch_two == finish_char && finish_char == '\n')
					{
						break;
					}
					else if (ch_two == finish_char && finish_char == '*')
					{
						can_finish = 1;
					}
					else if (ch_two == '/' && can_finish == 1)
					{
						break;
					}
					else
					{
						can_finish = 0;
					}
				}
			}
			else
			{
				ungetc(ch, file);
			}
		}
		else
		{
			ungetc(ch, file);
		}
		if (comment)
		{
			
		}

		//get the next token
		new_token = retrieve_tokens();   //function that gets all the tokens

		//print_token(new_token, line_num);     //uncomment to get a list of all the tokens
		//destroy_token(new_token);
	}

	return new_token;
}

token create_token(token_type token_represent, const char *buffer, int length)
{
	token new_token; 

	char *token_strand = malloc(length + 1);

	if (!token_strand)
	{
		//lexical_error(line_num, "out of memory allocating the new token");
	}

	memcpy(token_strand, buffer, length);
	token_strand[length] = '\0';

	new_token.token_represent = token_represent;
	new_token.token_strand = token_strand;

	return new_token;
}

void destroy_token(token new_token)
{
	free((void *)new_token.token_strand);
}

token retrieve_tokens()
{
	int length = 0;
	int ch_two = 0;
	int check = 0;
	char ch = 0;

	if ((ch = fgetc(file)) == EOF)
	{
		return create_token(_enfi, lexer_buffer, 0);
	}

	lexer_buffer[length++] = ch;

	switch (ch)
	{
	case '\n':  return create_token(_neli, lexer_buffer, length);
	case ' ':   return create_token(_space, lexer_buffer, length);

	case '#':   return create_token(_hash, lexer_buffer, length);
	case ':':   return create_token(_colon, lexer_buffer, length);
	case '.':   return create_token(_period, lexer_buffer, length);
	case ',':   return create_token(_comma, lexer_buffer, length);
	case ';':   return create_token(_semicolon, lexer_buffer, length);

	case '(':   return create_token(_lparen, lexer_buffer, length);
	case ')':   return create_token(_rparen, lexer_buffer, length);
	case '{':   return create_token(_lbracket, lexer_buffer, length);
	case '}':   return create_token(_rbracket, lexer_buffer, length);
	case '[':   return create_token(_lbrace, lexer_buffer, length);
	case ']':   return create_token(_rbrace, lexer_buffer, length);

	case '<':
	{
		ch_two = fgetc(file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_l_equal, lexer_buffer, length);
		}
		ungetc(ch_two, file);
		return create_token(_larrow, lexer_buffer, length);
	}

	case '>':
	{
		ch_two = fgetc(file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_g_equal, lexer_buffer, length);
		}
		ungetc(ch_two, file);
		return create_token(_rarrow, lexer_buffer, length);
	}

	case '!':
	{
		ch_two = fgetc(file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_not_equal, lexer_buffer, length);
		}
		break;
	}

	case '=':
	{
		ch_two = fgetc(file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_equal, lexer_buffer, length);
		}
		ungetc(ch_two, file);
		return create_token(_assign, lexer_buffer, length);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	case '%':         return create_token(_modulo, lexer_buffer, length);
	case '*':         return create_token(_multiply, lexer_buffer, length);
	case '/':         return create_token(_divide, lexer_buffer, length);
	case '+':
	{
		ch_two = fgetc(file);

		if (ch_two == '+')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_increment, lexer_buffer, length);
		}
		ungetc(ch_two, file);
		return create_token(_addition, lexer_buffer, length);
	}
	case '-':
	{
		ch_two = fgetc(file);

		if (ch_two == '-')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_decrement, lexer_buffer, length);
		}
		ungetc(ch_two, file);
		return create_token(_subtract, lexer_buffer, length);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	default:   break;
	}


	if (ch == '"')
	{
		while (ch_two != '"')
		{
			ch_two = fgetc(file);

			if (ch_two == '"')
			{
				lexer_buffer[length] = 0;
			}
			lexer_buffer[length++] = ch_two;
		}
		return create_token(_strand_literal, lexer_buffer, length);
	}

	if (ch >= '0' && ch <= '9')
	{
		int real = 0;

		return create_token(_number, lexer_buffer, length);

		while (true)
		{
			ch_two = fgetc(file);

			if (ch_two == '.' || ch_two == 'e' || ch_two == 'E')
			{
				real = 1;
				lexer_buffer[length++] = ch_two;
				return create_token(_decimal, lexer_buffer, length);

				if (ch_two >= '0' && ch_two <= '9')
				{
					lexer_buffer[length++] = ch_two;
					return create_token(_number, lexer_buffer, length);
				}
			}
			else
			{
				ungetc(ch_two, file);
				break;
			}
		}
	}

	while ((ch = fgetc(file)) != EOF && length < 1000)
	{
		if (!letter(ch))
		{
			ungetc(ch, file);
			break;
		}
		lexer_buffer[length++] = ch;
	}

	if (length >= 1000)
	{
		//lexical_error("lexical buffer error: token exceeds maximum length", line_num);
	}

	lexer_buffer[length] = 0;


	token build = create_token(_word, lexer_buffer, length);
	//these functions are for getting reserved words and the identifiers in check_word.c

	if (user_function(&build))
	{
		return build;
	}
	if (data_types(&build))
	{
		return build;
	}
	if (manager_types(&build))
	{
		return build;
	}

	if (header_types(&build))
	{
		return build;
	}
	if (subheader_types(&build))
	{
		return build;
	}
	if (file_types(&build))
	{
		return build;
	}
	if (data_modifier_type(&build))
	{
		return build;
	}
  if(data_tool(&build))
  {
    return build;
  }
	if (check_ident(&build))
	{
		return build;
	}
}



