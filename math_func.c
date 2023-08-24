#include "monty.h"
/**
  * _add - function adds top two elements of the stack
  * @head: void
  * @data: void
  */
void _add(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "add");

	data = gs.tail->n;
	mlist_remove(gs.tail);
	data += gs.tail->n;
	gs.tail->n = data;
}
/**
  * _sub - function subtracts top two elements of the stack
  * @head: void
  * @data: function stores interger from node
  */
void _sub(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "sub");

	data = gs.tail->prev->n;
	data -= gs.tail->n;
	gs.tail->prev->n = data;
	mlist_remove(gs.tail);
}
/**
  * _div - function divides top two elements of the stack
  * @head: void
  * @data: function store integer from node
  */
void _div(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "div");

	data = gs.tail->n;
	if (data == 0)
		myexit(-9, NULL);
	mlist_remove(gs.tail);
	data /= gs.tail->n;
	gs.tail->n = data;
}
/**
  * _mod - top two modulo elements of the stack
  * @head: void
  * @data: the store integer from node
  */
void _mod(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "mod");

	data = gs.tail->n;
	if (data == 0)
		myexit(-9, NULL);
	mlist_remove(gs.tail);
	data %= gs.tail->n;
	gs.tail->n = data;
}
/**
  * _mul - function multiply top two elements of the stack
  * @head: void
  * @data: interger stored from node
  */
void _mul(stack_t **head, unsigned int data)
{
	(void)head;

	if (gs.size < 2)
		myexit(-8, "mul");

	data = gs.tail->n;
	mlist_remove(gs.tail);
	data *= gs.tail->n;
	gs.tail->n = data;
}
