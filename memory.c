#include "shell.h"

/**
 * bfree - This frees a pointer and NULLs the address
 * @ptr: This means the address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int main()
{
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
}
