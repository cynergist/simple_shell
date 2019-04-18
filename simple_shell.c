#include "simple_shell.h"
char *name;
/**
 * main - print prompt, handle EOF, read file_stream
 * @argc: arg count (not needed)
 * @argv: argv for command
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *s = NULL;
	size_t buffer_size = 0;
	ssize_t file_stream = 0;

	(void) argc;
	name = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		file_stream = getline(&s, &buffer_size, stdin);
		if (file_stream == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (s[file_stream - 1]  == '\n')
			s[file_stream - 1]  = '\0';
		if (*s == '\0')
			continue;
		if (cmd_read(s, file_stream) == 2)
			break;
	}
	free(s);
	s = NULL;
	return (0);
}
/**
 * cmd_read - handles command line and tokenizes it
 *@s: string
 *@file_stream: getline input
 * Return: 0
 */
int cmd_read(char *s, size_t __attribute__((unused))file_stream)
{
	char *token = NULL;
	char *cmd_arr[100];
	int i;

	if (_strcmp(s, "exit") == 0)
		return (2);
	if (_strcmp(s, "env") == 0)
		return (_printenv());
	token = strtok(s, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;
/* Return status code */
	return (call_command(cmd_arr));
}
/**
 * print_not_found - prints when cmd is not found in path
 *
 * @cmd: a string provided by the stdin
 */
void print_not_found(char *cmd)
{
	write(2, name, _strlen(name));
	write(2, ": 1: ", 5);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
/**
 * call_command - calls cmd, forks, execve
 *
 * @cmd_arr: a string provided by the stdin
 * Return: 0
 */
int call_command(char *cmd_arr[])
{
	char *exe_path_str = NULL;
	char *cmd = NULL;
	pid_t is_child;
	int status;

	cmd = cmd_arr[0];
	exe_path_str = pathfinder(cmd);
	if (exe_path_str == NULL)
	{
		print_not_found(cmd);
		return (3);
	}
	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
		wait(&status);
	else if (is_child == 0)
	{
		(execve(exe_path_str, cmd_arr, environ));
		perror("Error:");
		exit(1);
	}
	free(exe_path_str);
	return (0);
}
