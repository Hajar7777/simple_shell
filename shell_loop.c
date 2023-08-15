#include "shell.h"

/**
* hsh - MaIn SheLL Loop
*
* @info: tHe ParaMEter AND RetUrn INFO stRuct
*
* @av: tHe aRgumEnt vectoR FrOm main()
*
* Return: 0 SuccEss
*         1 ErroR OR ERror Code
*/
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}


/**
* find_builtin - FinDs a builtIN commanD
*
* @info: tHe ParametEr AND reTurn INFO stRuct
*
* Return: -1 IF builtin is not being founD
* return 0 IF builTIN executED suCCessfullY
* return 1 IF builtIN is found but is NOT successfuL
* return 2 IF builtIN signalS exit()
*/
int find_builtin(info_t *info)
{
	int mil, buiilt_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (mil = 0; builtintbl[mil].type; mil++)
		if (_strcmp(info->argv[0], builtintbl[mil].type) == 0)
		{
			info->line_count++;
			buiilt_in_ret = builtintbl[mil].func(info);
			break;
		}
	return (buiilt_in_ret);
}




















/**
* find_cmd - FinDs a coMMand in PATH
*
* @info: tHe parametEr AND retuRn INFO struct
*
* Return: EMPTY
*/
void find_cmd(info_t *info)
{
	char *path = NULL;
	int ijk, kirel;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (ijk = 0, kirel = 0; info->arg[ijk]; ijk++)
		if (!is_delim(info->arg[ijk], " \t\n"))
			kirel++;
	if (!kirel)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}






/**
* fork_cmd - FOrks exec THread TO run cmd
*
* @info: tHe PArameter AND retuRn INFO stRuct
*
* Return: EMPTY
*/
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
