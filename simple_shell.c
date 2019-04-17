#include "simple_shell.h"
/**
 * main - print prompt, handle EOF, read file_stream
 *
 * Return: Always 0.
 */
int main(void)
{
	char *s = NULL;
	size_t buffer_size = 0;
	ssize_t file_stream = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 3);
		file_stream = getline(&s, &buffer_size, stdin);
		if (file_stream == -1)
		{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "\n", 2);
			break;
		}
		s[file_stream - 1]  = '\0';
		if (*s == '\0')
			continue;
		if (cmd_read(s, file_stream) == 2)
			file_stream = EOF;
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
	char *cmd = NULL;
	char *exe_path_str = NULL;
	pid_t is_child;
	int status, i;

	if (strcmp(s, "exit") == 0)
		return (2);
	if (strcmp(s, "env") == 0)
		return (_printenv());
	token = strtok(s, " "), i = 0;
	while (token)
	{
		cmd_arr[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_arr[i] = NULL;
	cmd = cmd_arr[0];
	exe_path_str = pathfinder(cmd);
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
		exit(-1);
	}
	free(exe_path_str);
	return (0);
}
