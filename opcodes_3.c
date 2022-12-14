#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	int hold_this, hold_this_again;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, nline);
	}

	hold_this = (*stack)->n;
	temp = *stack;

	while (temp)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}

	hold_this_again = temp->n;
	(*stack)->n = hold_this_again;
	temp->n = hold_this;
}

/**
 * rotlop - rotates stack to left
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = tmp;
	tmp->prev = last;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	tmp->next = NULL;
}

/**
 * rotrop - rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	tmp->prev = last;
	last->next = tmp;
	*stack = last;
}

/**
 * qpush - pushes for queue instead of stack
 * @stack: pointer to the head node pointer of stack
 * @nline: the line number
 * Return: Nothing.
 */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
