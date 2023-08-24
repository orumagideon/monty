#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct dlist_s - The global structure to hold data
 * @size: size of double linked list
 * @head: pointer to the head of double linked list
 * @tail: pointer to the tail of double linked list
 */
typedef struct mlist_s
{
	size_t size;
	unsigned int ln;
	stack_t *head;
	stack_t *tail;
	FILE *fd;
	void *buffer;
	int intarg;
	int mode;
} mlist_t;

extern mlist_t gs;

/* monty_list.c */
void mlist_init(void);
void mlist_destroy(void);
int mlist_ins_end(const int data);
int mlist_ins_beg(const int data);
int mlist_remove(stack_t *node);

/* run_opcode.c */
int run_opcode(char *buf);
void myexit(int code, char *string);
int chk_int(const char *argint);
void nop(stack_t **stack, unsigned int data);

/* functions.c */
void push(stack_t **stack, unsigned int data);
void pint(stack_t **stack, unsigned int data);
void pall(stack_t **stack, unsigned int data);
void pop(stack_t **stack, unsigned int data);
void swap(stack_t **stack, unsigned int data);

/* functions3.c */
void rotl(stack_t **head, unsigned int data);
void rotr(stack_t **head, unsigned int data);
void pchar(stack_t **head, unsigned int data);
void pstr(stack_t **head, unsigned int data);
void chgmode(stack_t **head, unsigned int data);

/* mathFunc.c */
void _add(stack_t **head, unsigned int data);
void _sub(stack_t **head, unsigned int data);
void _div(stack_t **head, unsigned int data);
void _mod(stack_t **head, unsigned int data);
void _mul(stack_t **head, unsigned int data);

#endif /* MONTY_H */
