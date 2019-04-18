#include "simple_shell.h"

/**
 **_strcat(char *dest, char *src)- a function that concatenates two strings.
 *@dest: Char input
 *@src: Char input
 *
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int j = 0;

	int length = _strlen(dest);

	while (src[j] != '\0')
	{
		dest[length] = src[j];
		length++;
		j++;
	}
	dest[length] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string to compare to first string
 *
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
	if (*s1 == '\0')
	{
	return (0);
	}
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}

/**
 * char *_strcpy- Copies a string
 *@dest: The new, coppied string
 *@src: The original string to copy
 *
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int length, i;

	length = _strlen(src);

	for (i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen(char *s)- a function that returns the length of a string.
 *@s: Char
 *
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
		}
	return (i);
}

/**
 * *_strdup - copies the input string
 * @string: input string
 *
 * Return: *ptr to the copied string or  NULL (if Error)
 */
char *_strdup(char *string)
{
	char *dup;
	unsigned int i = 0, length = 0;

	if (string == NULL)
		return (NULL);

	while (string[length])
		length++;

	dup = malloc(sizeof(char) * (length + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = string[i]) != '\0')
		i++;

	return (dup);
}
