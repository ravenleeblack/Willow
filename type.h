#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
  _none, _done,

	//preprocessor associated
	_seedling, _link, _use, _define, _translate, _system, _haven, _io,

	//new_line, space, end_file
	_neli, _space, _enfi, _tab,

	//number associated tokens
	_number, _addition, _subtract, _multiply, _divide, _increment, _decrement, _modulo,

	//seperating associated tokens
	_hash, _colon, _comma, _semicolon, _period,

	//grouping associated tokens
	_lparen, _rparen, _lbrace, _rbrace, _lbracket, _rbracket, _larrow, _rarrow,

	//work making associated tokens
	_word, _ident, _keyword,

	//equalizers or relational associated tokens
	_g_equal, _l_equal, _equal, _not_equal, _assign,

	//literal associated tokens
	_char_literal, _strand_literal, _constant_literal,

	//manager or class making associated tokens
	_manager, _private, _public, _elem, _object,

	//data type associated tokens
	_hollow, _num, _mark, _deci,_decii,
	_placeholder,
	_return, _decimal, _comment, _yield,

	_pointer_num, _pointer_mark, _pointer_deci, _pointer_decii, _pointer_hollow,

	//file related associated tokens
	_file, _read, _write,

	// statement tokens / data tool tokens
	_loop, _set, _check, _else, _pare, _compare, _list, _construct, _log, _bridge, _act,

	_external, _internal, _static, _register, _short, _long, _signed, _unsigned, _table
}token_type;

typedef struct token
{
	token_type token_represent;
	char * token_strand;
} token;
extern token new_token;


struct entry
{
	char *str_ptr;
	token_type enum_tokens;
};

typedef enum
{
  _none_node, _done_node,

	//preprocessor associated
	_seedling_node, _link_node, _use_node, _define_node, _translate_node, _system_node, _haven_node, _io_node,

	//number associated nodes
	_number_node, _addition_node, _subtract_node, _multiply_node, _divide_node, _increment_node, _decrement_node, _modulo_node,

	//equalizers or relational associated nodes
	_g_equal_node, _l_equal_node, _equal_node, _not_equal_node, _assign_node,  _larrow_node, _rarrow_node,

	//literal associated nodes
	_char_literal_node, _strand_literal_node, _constant_literal_node,

	//manager or class making associated nodes
	_manager_node, _function_node, _manager_list_node, _fun_list_node,

	//data type associated nodes
	_return_node,

	//file related associated nodes
  _write_node, _read_node,

	// statement nodes / data tool nodes
	_loop_node, _set_node, _check_node, _else_node, _pare_node, _compare_node, _list_node, _construct_node, _log_node, _bridge_node, _act_node, _call_node, _statement_list_node, _arg_list_node, _ident_node, _table_node,


} node_type;

typedef struct node
{
  node_type node_represent;

  struct node* head;
  struct node* next;
  struct node* tail;

  union
  {
    char* ident;
    char* strand_literal;
    int number;

    // _check_node, _loop_node
    struct
    {
      struct node* expr;
      struct node* statement_list;
    } block;

    // _function_node
    struct
    {
      char * ident;
      token_type type;
      struct node* statement_list;
    } fun;

    // _assign_node
    struct 
    {
      token_type type;
      char * ident;
      struct node* expr;
    } assign;

    // _call_node
    struct 
    {
      char * ident;
      struct node* arg_list;
    } call;

    
    // _addition_node ,_subtract_node ,_multiply_node ,_divide_node ,_equal_node ,_g_equal_node ,_l_equal_node ,_not_equal_node, _rarrow_node, _larrow_node
    struct
    {
      struct node* left, *right;
    } op;

    // _manager_node
    struct 
    {
      char * ident;
      struct node* fun_list;
    } manager;

    // _table_node
    struct
    {
      char* ident;
      token_type type;
      struct node* num;
      struct node* arg_list;
    } table;
  };
} node;


extern struct entry preprocess_header[];
extern struct entry system_header[];
extern struct entry sub_header[];

extern struct entry file_type[];

extern struct entry manager_type[];
extern struct entry function_type[];


extern struct entry data_type[];
extern struct entry data_tools[];
extern struct entry data_modifier[];


extern FILE * file;
extern char lexer_buffer[1000];

extern token new_token;
extern int line_num;










#endif // !TYPE_H
