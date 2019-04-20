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

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string to compare to first string
 * @n: count of the comparison between s1 and s2
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 * Description: Credit code.woboq.org/userspace/glibc/string/test-strncmp
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	char charstr1, charstr2;

	while (n--)
	{
		charstr1 = *s1++;
		charstr2 = *s2++;
		if (charstr1 == '\0' || charstr1 != charstr2)
			return (charstr1 > charstr2 ? 1 : (charstr1 < charstr2 ? -1 : 0));
	}
				return (0);
}
/**
 * _getenv - prints environment like getenv
 * @var: environ variable
 *
 * Return: 0
 */
char *_getenv(char *var)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], var, _strlen(var)) == 0)
			return (&environ[i][_strlen(var)]);
	}
	return (NULL);
}
