#include "print_token.h"

void print_token(token new_token, int line_num)
{
	const char *token_strand = new_token.token_strand;

	switch (new_token.token_represent)
	{
	case _space:                                    break;
	case _neli:                                     break;

	case _ident:              printf(" %03d:  %s\t                          ident\t          identifier\n", line_num, token_strand);                             break;
	case _strand_literal:     printf(" %03d:  %s\t\t          strand_literal\n", line_num, token_strand);                            break;

	case _use:                printf(" %03d:  %s\t                  use header\n", line_num, token_strand);                        break;
	case _link:               printf(" %03d:  %s\t                  link header\n", line_num, token_strand);                       break;
	case _translate:          printf(" %03d:  %s\t                  translate header\n", line_num, token_strand);                  break;
	case _system:             printf(" %03d:  %s\t                  system header\n", line_num, token_strand);                     break;
	case _haven:              printf(" %03d:  %s\t                  haven header\n", line_num, token_strand);                      break;
	case _io:                 printf(" %03d:  %s\t                  io header\n", line_num, token_strand);                         break;

	case _number:             printf(" %03d:  %s\t                          number\t  operator\n", line_num, token_strand);                            break;
	case _addition:           printf(" %03d:  %s\t                          addition\t  operator\n", line_num, token_strand);                 break;
	case _subtract:           printf(" %03d:  %s\t                          subtract\t  operator\n", line_num, token_strand);                 break;
	case _multiply:           printf(" %03d:  %s\t                          multiply\t  operator\n", line_num, token_strand);                 break;
	case _divide:             printf(" %03d:  %s\t                          divide\t  operator\n", line_num, token_strand);                   break;
	case _increment:          printf(" %03d:  %s\t                          increment\t  operator\n", line_num, token_strand);                break;
	case _decrement:          printf(" %03d:  %s\t                          decrement\t  operator\n", line_num, token_strand);                break;
	case _assign:             printf(" %03d:  %s\t                          assign\t  operator\n", line_num, token_strand);                   break;

	case _lparen:             printf(" %03d:  %s\t                          lparen\t  operator\n", line_num, token_strand);                   break;
	case _rparen:             printf(" %03d:  %s\t                          rparen\t  operator\n", line_num, token_strand);                   break;
	case _lbracket:           printf(" %03d:  %s\t                          lbracket\t  operator\n", line_num, token_strand);                 break;
	case _rbracket:           printf(" %03d:  %s\t                          rbracket\t  operator\n", line_num, token_strand);                 break;
	case _lbrace:             printf(" %03d:  %s\t                          lbrace\t  operator\n", line_num, token_strand);                   break;
	case _rbrace:             printf(" %03d:  %s\t                          rbrace\t  operator\n", line_num, token_strand);                   break;
	case _larrow:             printf(" %03d:  %s\t                          larrow\t  operator\n", line_num, token_strand);                   break;
	case _rarrow:             printf(" %03d:  %s\t                          rarrow\t  operator\n", line_num, token_strand);                   break;

	case _g_equal:            printf(" %03d:  %s\t                          great_equal\n", line_num, token_strand);                       break;
	case _l_equal:            printf(" %03d:  %s\t                          less_equal\n", line_num, token_strand);                        break;
	case _not_equal:          printf(" %03d:  %s\t                          not_equal\n", line_num, token_strand);                         break;
	case _equal:              printf(" %03d:  %s\t                          equal\n", line_num, token_strand);                             break;


	case _colon:              printf(" %03d:  %s\t                          colon\t          operator\n", line_num, token_strand);                    break;
	case _comma:              printf(" %03d:  %s\t                          comma\t          operator\n", line_num, token_strand);                    break;
	case _period:             printf(" %03d:  %s\t                          period\t  operator\n", line_num, token_strand);                   break;
	case _semicolon:          printf(" %03d:  %s\t                          semicolon\t  operator\n", line_num, token_strand);                break;



	case _manager:            printf(" %03d:  %s\t                          manager\t  manager_type\n", line_num, token_strand);                           break;
	case _private:            printf(" %03d:  %s\t                          private\t  manger_type\n", line_num, token_strand);                           break;
	case _public:             printf(" %03d:  %s\t                          public\t  manager_type\n", line_num, token_strand);                            break;
	case _elem:               printf(" %03d:  %s\t                          elem\t     manager_type\n", line_num, token_strand);                              break;
	case _object:             printf(" %03d:  %s\t                          object\t   manager_type\n", line_num, token_strand);                            break;

	case _read:               printf(" %03d:  %s\t                          read\t           user_function\n", line_num, token_strand);                     break;
	case _write:              printf(" %03d:  %s\t                          write\t          user_function\n", line_num, token_strand);                    break;

	case _file:               printf(" %03d:  %s\t                  file\n", line_num, token_strand);                              break;
	case _hollow:             printf(" %03d:  %s\t                          hollow\t  data_type\n", line_num, token_strand);                            break;
	case _num:                printf(" %03d:  %s\t                          num\t          data_type\n", line_num, token_strand);                               break;
	case _deci:               printf(" %03d:  %s\t                          deci\t          data_type\n", line_num, token_strand);                              break;
	case _mark:               printf(" %03d:  %s\t                          mark\t          data_type\n", line_num, token_strand);                              break;
	case _return:             printf(" %03d:  %s\t                          return\t       data_type\n", line_num, token_strand);                            break;
	case _yield:              printf(" %03d:  %s\t                          yield\t          data_type\n", line_num, token_strand);                             break;

	case _check:              printf(" %03d:  %s\t                          check\n", line_num, token_strand);                             break;
	case _else:               printf(" %03d:  %s\t                  else\n", line_num, token_strand);                              break;
	case _loop:               printf(" %03d:  %s\t                  loop\n", line_num, token_strand);                              break;
	case _set:                printf(" %03d:  %s\t                  set\n", line_num, token_strand);                               break;
	case _pare:               printf(" %03d:  %s\t                  pare\n", line_num, token_strand);                              break;
	case _compare:            printf(" %03d:  %s\t                  compare\n", line_num, token_strand);                           break;
	case _list:               printf(" %03d:  %s\t                  list\n", line_num, token_strand);                              break;
	case _construct:          printf(" %03d:  %s\t                  construct\n", line_num, token_strand);                         break;
	case _log:                printf(" %03d:  %s\t                  log\n", line_num, token_strand);                               break;
	case _bridge:             printf(" %03d:  %s\t                  bridge\n", line_num, token_strand);                            break;

	case _short:              printf(" %03d:  %s\t                  short\n", line_num, token_strand);                             break;
	case _long:               printf(" %03d:  %s\t                  long\n", line_num, token_strand);                              break;
	case _signed:             printf(" %03d:  %s\t                  signed\n", line_num, token_strand);                            break;
	case _unsigned:           printf(" %03d:  %s\t                  unsigned\n", line_num, token_strand);                          break;
	case _static:             printf(" %03d:  %s\t                  static\n", line_num, token_strand);                            break;
	case _external:           printf(" %03d:  %s\t                  external\n", line_num, token_strand);                          break;
	case _internal:           printf(" %03d:  %s\t                  internal\n", line_num, token_strand);                          break;
	case _register:           printf(" %03d:  %s\t                  register\n", line_num, token_strand);                          break;
	case _decimal:            printf(" %03d:  %s\t                  decimal\n", line_num, token_strand);                           break;


	case _enfi:               break;

	default:                 /* lexical_error("Unknown Token:  unknown token in the print_token function", line_num); */                      break;
	}
}
