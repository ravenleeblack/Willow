
#ifndef PARSE_H_
#define PARSE_H_

#include "type.h"

node* create_node(node_type type);
void add_child_node(node* parent, node* child);

token next_token(token_type type);
bool is_eof();
void skip_whitespace();
void skip_space();
node* parse();
void parse_error();

node* parse_number();
node* parse_manager(token ident);
node* parse_member_function(token type);
node* parse_check();
node* parse_statement();
node* parse_expression();
node* parse_arguments();
node* parse_loop();
node* parse_function_call(token ident);
node* parse_assignement(token type);
node* parse_table_assignement(token type);
node* parse_write();
node* parse_read();
node* parse_statement_list();

void print_ast(node* root);

#endif // !PARSE_H_
