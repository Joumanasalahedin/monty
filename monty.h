#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef stack_t dlistint_t;
/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct args_s - structure of arguments from main
  * @av: name of the file
  * @ac: number of arguments
  * @line_no: number of the current line in the file
  *
  * Description: arguments passed to main from command line
  * used in different functions
  */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_no;
} args_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @words: parsed line
 * @stack: pointer to the stack
 * @file_ptr: file pointer
 * @q_flag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *file_ptr;
	int q_flag;
} data_t;

extern data_t data;

#define UNKOWN "L%u: unknown nstruction %s\n"

/** use_func.c **/
void (*use_func(char **bytecode_tok))(stack_t **, unsigned int);

/** free.c **/
void free_memory(int all);
void free_array(char **args);

/** double linked list function **/
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

/** split_string **/
char **split_string(char *str);

#endif
