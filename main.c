#include "shell.h"




































/**
* main - EntryY PoinT
*
* @ac: arg coUNT
*
* @av: arg VecTOr
*
* Return: 0 sUCcesS
* 1 IF eRRor
*/
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fed = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fed)
			: "r" (fed));

	if (ac == 2)
	{
		fed = open(av[1], O_RDONLY);
		if (fed == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fed;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
