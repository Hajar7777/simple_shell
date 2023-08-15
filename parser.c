#include "shell.h"























/**
* is_cmd - detERmines IF a fIle is
* An eXEcutaBle coMMand
*
* @info: tHe INFO stRucT
*
* @path: PATH to tHE fIlE
*
* Return: 1 iF trUe
* 0 IF NoT
*/
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}







































/**
* dup_chars - duPLicates CHAR
*
* @pathstr: tHe PATH strING
*
* @start: stARting INDex
*
* @stop: stoPS INDex
*
* Return: POinter TO nEw BuFFER
*/
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int ilo = 0, kia = 0;

	for (kia = 0, ilo = start; ilo < stop; ilo++)
		if (pathstr[ilo] != ':')
			buf[kia++] = pathstr[ilo];
	buf[kia] = 0;
	return (buf);
}





























/**
* find_path - fiNDs tHis cmd IN tHe PATH stRIng
*
* @info: tHe INFO sTRucT
*
* @pathstr: tHe PATH strINg
*
* @cmd: the cmd to fINd
*
* Return: fuLL path OF cmd iF fOUnd oR NULL
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int ilik = 0, currr_pos = 0;
	char *pathh;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[ilik] || pathstr[ilik] == ':')
		{
			pathh = dup_chars(pathstr, currr_pos, ilik);
			if (!*pathh)
				_strcat(pathh, cmd);
			else
			{
				_strcat(pathh, "/");
				_strcat(pathh, cmd);
			}
			if (is_cmd(info, pathh))
				return (pathh);
			if (!pathstr[ilik])
				break;
			currr_pos = ilik;
		}
		ilik++;
	}
	return (NULL);
}
