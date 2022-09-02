#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void recursively_read_directory(char *path);

/**
 * main - opens a directory, and lists its contents
 * @argc: number of arguments supplied
 * @argv: pointer to arguments array
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path>\n", argv[0]);
		exit(1);
	}
	recursively_read_directory(argv[1]);
	return (0);
}

/**
 * recursively_read_directory - opens and reads contents of all
 * directories from the specified path recursively
 * @path: path to the starting directory
 * system calls used: opendir(), readdir(), closedir()
 * prototypes :
 * - DIR *opendir(const char *path);
 * - struct dirent *readdir(DIR *directorypointer);
 * - int closedir(DIR *directorypointer);
 *
 * Return: void
 */

void recursively_read_directory(char *path)
{
	DIR * dir_reader;
	struct dirent *dir_entry;
	int new_path_len;
	char *name, *new_path;

	dir_reader = opendir(path);
	if (dir_reader == NULL)
	{
		fprintf(stderr, "Unable to open %s\n", path);
	}
	else
	{
		while ((dir_entry = readdir(dir_reader)) != NULL)
		{
			name = dir_entry->d_name;
			printf("%d %s/%s\n", dir_entry->d_type, path, name);
			if (dir_entry->d_type == DT_DIR && strcmp(name, ".") != 0 && strcmp(name, "..") != 0)
			{
				new_path_len = strlen(path) + strlen(dir_entry->d_name) + 2;
				new_path = malloc(sizeof(new_path) * new_path_len);
				if (new_path == NULL)
					return;
				strcpy(new_path, path);
				strcat(new_path, "/");
				strcat(new_path, dir_entry->d_name);
				recursively_read_directory(new_path);
				free(new_path);
			}
		}
		closedir(dir_reader);
	}
}
