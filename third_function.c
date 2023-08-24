#include "monty.h"
/**
 * rotl - function rotates the stack to the top
 * @head: the beginning of stack
 * @data: the integer in stack
 */
void rotl(stack_t **head, unsigned int data)
{
	(void) head;
	if (gs.size == 0)
		myexit(0, NULL);

	data = gs.tail->n;
	mlist_ins_beg(data);
	mlist_remove(gs.tail);
}
/**
 * rotr - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @data: the integer in stack
*/
void rotr(stack_t **head, unsigned int data)
{
	(void) head;
	if (gs.size == 0)
		myexit(0, NULL);

	data = gs.head->n;
	mlist_ins_end(data);
	mlist_remove(gs.head);
}
/**
 * pchar - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @data: the integer in stack
*/
void pchar(stack_t **head, unsigned int data)
{
	int num;
	(void) head;
	(void) data;

	if (gs.size == 0)
		myexit(-6, "pchar");
	num = gs.tail->n;
	if (num < 0 || num > 127)
		myexit(-10, NULL);
	printf("%c\n", num);
}
/**
 * pstr - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @data: integer in stack
 */
void pstr(stack_t **head, unsigned int data)
{
	stack_t *list;
	(void) head;
	(void) data;

	list = gs.tail;
	for (; list; list = list->prev)
	{
		if (list->n == 0)
			break;
		printf("%c", list->n);
	}
	printf("\n");
}
/**
 * chgmode - function changes mode: stack to que
 * @head: Unused
 * @data: Unused
 */
void chgmode(stack_t **head, unsigned int data)
{
	(void) head;
	(void) data;

	gs.mode *= -1;
}
