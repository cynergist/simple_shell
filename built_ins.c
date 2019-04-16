#include "simple_shell.h"

/**
 * _printenv - prints environment like printenv
 *
 * Return: 0
 */
int _printenv(void)
{
        char *s = environ[0];
        int i = 0;

        while (s)
        {
		write(1, s, _strlen(s));
                write(1, "\n", 1);
                s = environ[++i];
        }
        return (0);
}
