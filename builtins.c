#include "shell.h"

/* Declarations for new_exit and new_unsetenv functions */
void new_exit(vars_t *vars);
void new_unsetenv(vars_t *vars);

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
    unsigned int i;
    builtins_t check[] = {
        {"exit", new_exit},
        {"env", _env},
        {"setenv", new_setenv},
        {"unsetenv", new_unsetenv},
        {NULL, NULL}
    };

    for (i = 0; check[i].f != NULL; i++)
    {
        if (_strcmpr(vars->av[0], check[i].name) == 0)
            break;
    }
    if (check[i].f != NULL)
        check[i].f(vars);
    return (check[i].f);
}

/* Rest of your code remains unchanged */

