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
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string to compare to first string
 *
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	while ((*s1 == *s2) && (n--))
	{
	if (*s1 == '\0')
	{
	return (0);
	}
	s1++;
	s2++;
	}
	return (*s1 != *s2);
}
/**                                                                                                
 * _getenv - prints environment like getenv                                                        
 *                                                                                                 
 * Return: 0                                                                                       
 */
char * _getenv(char * var)
{
 	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], var, _strlen(var)) == 0)
			return (&environ[i][_strlen(var)]);
	}
	return (NULL);
}
