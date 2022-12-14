#include "monty.h"

/**
 * get_op_func - function searches for a match between opcode and text
 * and returns the corresponding function
 * @line: struct containing line contents and line number
 * @meta: struct containing all allocated memory
 *
 * Return: pointer to the matching function
 */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addop},
		{"sub", subop},
		{"div", divop},
		{"mul", mulop},
		{"mod", modop},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotlop},
		{"rotr", rotrop},
		{"stack", addst},
		{"queue", addqu},
		{NULL, NULL}
	};

	if (comment_check(line))
		return (nop);

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line, meta, ops[i].opcode);
			if (arg.flag == 1 &&
			strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (qpush);
			}
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free(line.content);
	free(meta->buf);
	free_stack(&(meta->stack));
	fclose(meta->file);
	free(meta);
	exit(EXIT_FAILURE);
}
