#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argument_number - function to check the correct number of argument
 * @argc: number of arguments
 *
 * Return: void
 */
void argument_number(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_2 - a function to check that file_from exists or can be read
 * @check: checks file
 * @file: file_from name
 *
 * @fd_from: file descriptor of file_from
 * @fd_to: file descriptor for file_to
 *
 * Return: void
 */
void check_2(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * check_3 - function checks to creat or write into file_to
 *
 * @check: checks file
 * @file: file_to
 *
 * @fd_from: file descriptor for file_from
 * @fd_to: file descriptor for file_to
 *
 * Return: void
 */
void check_3(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * check_1 - function checks if file descriptors were closed properly
 * @check: checks file
 * @fd: file descriptor
 *
 * Return: void
 */
void check_1(int check, int fd)
{
        if (check == -1)
        {
                dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
                exit(100);
        }
}


/**
 * main - function that copies the content of a file to another file.
 *
 * @argc: number of arguments
 * @argv: string parameters
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	argument_number(argc);
	fd_from = open(argv[1], O_RDONLY);
	check_2((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	check_3((ssize_t)fd_to, argv[2], fd_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, buffer, 1024);
		check_2(lenr, argv[1], fd_from, fd_to);
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		check_3(lenw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	check_1(close_to, fd_to);
	check_1(close_from, fd_from);
	return (0);
}
