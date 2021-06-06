#include <stdio.h>
#include "symbol.h"
#include "parse.h"
#include "print_node.h"
#include "lex.h"

#define TOKEN(x) (new_token.token_represent == x)

node* parse()
{
  line_num = 1;

  node* n = create_node(_manager_list_node);

  new_token = lexer();

	while(!is_eof())
	{
    skip_whitespace();

    token ident = next_token(_ident);
    skip_whitespace();
    next_token(_manager);
    node* child = parse_manager(ident );
    add_child_node(n, child);
	}

  print_node(n, 0);

  return n;
}

node* create_node(node_type type)
{
  node* n = malloc(sizeof(node));
  n->node_represent = type;
  n->head = NULL;
  return n;
}

void skip_whitespace()
{
  while(!is_eof()) {

    if(TOKEN(_space)  || TOKEN(_tab)) 
    {
      new_token = retrieve_tokens();
      continue;
    }

    if(TOKEN(_neli)) 
    {
      new_token = retrieve_tokens();
      line_num++;
      continue;
    }

    break;
  }
}

void skip_space()
{
  while(!is_eof()) {

    if(TOKEN(_space)  || TOKEN(_tab)) 
    {
      new_token = retrieve_tokens();
      continue;
    }

    break;
  }
}


token next_token(token_type type)
{
  if(TOKEN(type)) {
    token cur_token = new_token;
    new_token = retrieve_tokens();
    return cur_token;
  }

  parse_error();
  return new_token;
}

void parse_error()
{
  printf("Error: Unexpected Token\n");
  print_token(new_token, line_num);
  
  new_token = create_token(_enfi, NULL, 0);
}

bool is_eof()
{
  return TOKEN(_enfi);
}

node* parse_manager(token ident)
{
  skip_whitespace();
  next_token(_lbracket);
  skip_whitespace();

  node* n = create_node(_manager_node);
  n->manager.ident = ident.token_strand;
  n->manager.fun_list = create_node(_fun_list_node);

  while(!is_eof()) 
  {
    if(TOKEN(_hollow) || TOKEN(_num) || TOKEN(_deci) || TOKEN(_mark) || TOKEN(_decii)) 
    {
      skip_whitespace();
      token type = new_token;
      new_token = retrieve_tokens();
      node* child = parse_member_function(type);
      add_child_node(n->manager.fun_list, child);
    }
    else if(TOKEN(_rbracket))
    {
      new_token = retrieve_tokens();
      break;
    }
  }
  skip_whitespace();

  return n;
}

node* parse_member_function(token type)
{
  skip_whitespace();
  token ident = next_token(_ident);
  skip_whitespace();
  next_token(_colon);

  node* n = create_node(_function_node);
  n->fun.type = type.token_represent;

  n->fun.ident = ident.token_strand;
  n->fun.statement_list = parse_statement_list();
  return n;
}

node* parse_statement()
{
  skip_whitespace();

  token first_token = new_token;

  switch(new_token.token_represent) {
  case _ident:
    skip_whitespace();
    new_token = retrieve_tokens();
    return parse_function_call(first_token);
  case _num:
    new_token = retrieve_tokens();
    skip_whitespace();
    if(TOKEN(_table)) 
    {
      new_token = retrieve_tokens();
      skip_whitespace();
      return parse_table_assignement(first_token);
    }
    else
    {
      return parse_assignement(first_token);
    }
  case _mark:
    new_token = retrieve_tokens();
    skip_whitespace();
    if(TOKEN(_table)) 
    {
      new_token = retrieve_tokens();
      skip_whitespace();
      return parse_table_assignement(first_token);
    }
    else
    {
      return parse_assignement(first_token);
    }
  case _write:
    new_token = retrieve_tokens();
    return parse_write();
  case _read:
    new_token = retrieve_tokens();
    return parse_read();
  case _check:
    new_token = retrieve_tokens();
    return parse_check();
  case _loop:
    new_token = retrieve_tokens();
    return parse_loop();
  default:
    break;
  }

  parse_error();
  return create_node(_none_node);
}

void add_child_node(node* parent, node* child)
{
  if(parent->head == NULL) {
    parent->head = child;
    parent->tail = child;
    child->next = NULL;
    return;
  }

  parent->tail->next = child;
  parent->tail = child;
  child->next = NULL;
}

node* parse_assignement(token type)
{
  node* n = create_node(_assign_node);
  skip_whitespace();
  token ident = next_token(_ident);

  n->assign.type = type.token_represent;
  n->assign.ident = ident.token_strand;

  skip_whitespace();
  next_token(_assign);

  n->assign.expr = parse_expression();
  skip_whitespace();
  next_token(_semicolon);

  return n;
}

node* parse_function_call(token ident)
{
  node* n = create_node(_call_node);
  next_token(_colon);
  n->call.ident = ident.token_strand;
  n->call.arg_list = parse_arguments();
  skip_whitespace();

  return n;
}

node* parse_write()
{
  node* n = create_node(_write_node);
  next_token(_colon);
  n->call.arg_list = parse_arguments();
  next_token(_semicolon);
  skip_whitespace();

  return n;
}

node* parse_arguments()
{
  node* n = create_node(_arg_list_node);
  skip_space();
  while(!TOKEN(_neli) && !TOKEN(_rbracket) && !is_eof()) {
    node* child = parse_expression();
    add_child_node(n, child);

    skip_space();
    if(TOKEN(_semicolon) || TOKEN(_neli) || TOKEN(_rbracket)) {
      break;
    }

    next_token(_comma);
    skip_space();
  }
  return n;
}

node* parse_expression()
{
  node* op = NULL;
  node* opnd = NULL;
  node* left = NULL;

  while(!TOKEN(_semicolon) && !TOKEN(_neli) && !TOKEN(_comma) && !TOKEN(_rbracket) && !is_eof()) {
    skip_space();

    opnd = NULL;
    if(TOKEN(_number)) 
    {
      opnd = parse_number();
    } 
    else if(TOKEN(_strand_literal)) 
    {
      opnd = create_node(_strand_literal_node);
      opnd->strand_literal = new_token.token_strand;
      new_token = retrieve_tokens();
    }

    else if(TOKEN(_ident)) 
    {
      opnd = create_node(_ident_node);
      opnd->strand_literal = new_token.token_strand;
      new_token = retrieve_tokens();
    }

    // If there was an operand link it to the corresponding
    // operator. The expression is parsed in a 
    // left-associative fashion.
    if(opnd) 
    {
      if(op) 
      {
        op->op.right = opnd;
        left = op;
      }
      else 
      {
        left = opnd;
      }
      skip_space();
      continue;
    }

    op = NULL;

    switch(new_token.token_represent)
    {
    case _addition:
      op = create_node(_addition_node);
      op->op.left = left;
      break;
    case _subtract:
      op = create_node(_subtract_node);
      op->op.left = left;
      break;
    case _multiply:
      op = create_node(_multiply_node);
      op->op.left = left;
      break;
    case _divide:
      op = create_node(_divide_node);
      op->op.left = left;
      break;
    case _equal:
      op = create_node(_equal_node);
      op->op.left = left;
      break;
    case _g_equal:
      op = create_node(_g_equal_node);
      op->op.left = left;
      break;
    case _l_equal:
      op = create_node(_l_equal_node);
      op->op.left = left;
      break;
    case _not_equal:
      op = create_node(_not_equal_node);
      op->op.left = left;
      break;
    case _larrow:
      op = create_node(_larrow_node);
      op->op.left = left;
      break;
    case _rarrow:
      op = create_node(_rarrow_node);
      op->op.left = left;
      break;
    default:
      break;
    }

    if(op == NULL) {
      break;
    }

    skip_space();
    new_token = retrieve_tokens();
  }
  
  if(op) {
    return op;
  }
  if(opnd) {
    return opnd;
  }

  parse_error();
  return create_node(_none_node);
}

node* parse_number()
{
  node* n = create_node(_number_node);
  n->number = 0;

  while(TOKEN(_number)) 
  {
    n->number *= 10;
    n->number += (int)(new_token.token_strand[0] - '0');
    new_token = retrieve_tokens();
  }
  return n;
}

node* parse_check()
{
  skip_whitespace();
  next_token(_colon);
  node* n = create_node(_check_node);
  n->block.expr = parse_expression();
  n->block.statement_list = parse_statement_list();
  return n;
}

node* parse_statement_list()
{
  skip_whitespace();
  next_token(_lbracket);

  node* n = create_node(_statement_list_node);

  while(!is_eof()) 
  {
    skip_whitespace();
    if(TOKEN(_rbracket)) 
    {
      break;
    }

    node* child = parse_statement();
    add_child_node(n, child);
  }

  next_token(_rbracket);
  skip_whitespace();
  return n;
}

node* parse_read()
{
  node* n = create_node(_read_node);
  next_token(_colon);
  n->call.arg_list = parse_arguments();
  next_token(_semicolon);
  skip_whitespace();

  return n;
}

node* parse_loop()
{
  skip_whitespace();
  next_token(_colon);

  node* n = create_node(_loop_node);
  n->block.expr = parse_expression();
  n->block.statement_list = parse_statement_list();
  return n;
}

node* parse_table_assignement(token type)
{
  token ident = next_token(_ident);

  node* n = create_node(_table_node);
  n->table.type = type.token_represent;
  n->table.ident = ident.token_strand;


  skip_whitespace();
  next_token(_larrow);
  skip_whitespace();
  n->table.num = parse_number();
  skip_whitespace();
  next_token(_rarrow);

  skip_whitespace();

  next_token(_lbracket);
  n->table.arg_list = parse_arguments();
  next_token(_rbracket);

  skip_whitespace();
  next_token(_semicolon);

  return n;
}
