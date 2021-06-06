#include "print_node.h"

void print_node(node* n, int depth)
{
  for(int i=0; i<depth; ++i) {
    printf("  ");
  }

  switch(n->node_represent)
  {
    case _ident_node:
      printf("ident        %s\n", n->ident);
      break;
    case _manager_list_node:
      printf("manager list\n");
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _manager_node:
      printf("manager      %s\n", n->manager.ident);
      n = n->manager.fun_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _function_node:
      printf("function      %s\n", n->fun.ident);
      n = n->fun.statement_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _assign_node:
      printf("assignement      %s\n", n->assign.ident);
      print_node(n->assign.expr, depth+1);
      break;
    case _call_node:
      printf("call      %s\n", n->call.ident);
      n = n->call.arg_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _write_node:
      printf("write\n");
      n = n->call.arg_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _strand_literal_node:
      printf("strand_literal      %s\n", n->strand_literal);
      break;
    case _addition_node:
      printf("addition\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _subtract_node:
      printf("substract\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _multiply_node:
      printf("multiply\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _divide_node:
      printf("divide\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _equal_node:
      printf("equal\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _g_equal_node:
      printf("g_equal\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _l_equal_node:
      printf("l_equal\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _not_equal_node:
      printf("not_equal\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _larrow_node:
      printf("larrow\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _rarrow_node:
      printf("larrow\n");
      print_node(n->op.left, depth+1);
      print_node(n->op.right, depth+1);
      break;
    case _number_node:
      printf("number %d\n", n->number);
      break;
    case _check_node:
      printf("check\n");
      print_node(n->block.expr, depth+1);
      n = n->block.statement_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _loop_node:
      printf("loop\n");
      print_node(n->block.expr, depth+1);
      n = n->block.statement_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _read_node:
      printf("read\n");
      n = n->call.arg_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+1);
      }
      break;
    case _table_node:
      printf("table  %s\n", n->table.ident);
      print_node(n->table.num, depth+1);
      n = n->table.arg_list;
      for(node* c = n->head; c; c = c->next)
      {
        print_node(c, depth+2);
      }
      break;
    default:
      break;
  }
}
