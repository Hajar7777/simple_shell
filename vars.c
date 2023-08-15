#include "shell.h"


























/**
* is_chain - tESt if cuRRent CHAR
* in buFFer is A chAin DeLImetEr
*
* @info: tHe ParAmeteR stRucT
*
* @buf: tHe CHAR bUffEr
*
* @p: addrEss of curREnt POsition in BUFFER
*
* Return: 1 IF cHain deLimEter
* 0 IF NOT
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t jio = *p;

	if (buf[jio] == '|' && buf[jio + 1] == '|')
	{
		buf[jio] = 0;
		jio++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[jio] == '&' && buf[jio + 1] == '&')
	{
		buf[jio] = 0;
		jio++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[jio] == ';') /* foUnd end OF tHis coMMand */
	{
		buf[jio] = 0; /* repLaCe semIcolOn wiTh NULL */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = jio;
	return (1);
}


























/**
* check_chain - ChecKs we sHouLd
* conTinue chaInIng bAsed On lAst stAtUs
*
* @info: tHe paRamEteR strUcT
* @buf: tHe cHar bUFFEr
* @p: aDDreSs OF currEnt positIon in BUFFER
* @i: starTIng posITIon in BUFFER
* @len: leNGth of BUFFER
*
* Return: EMPTY
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}






















/**
* replace_alias - repLAces An aliaseS
* IN tHe tOkenIzed stRIng
*
* @info: tHe PaRameTer STruCt
*
* Return: 1 iF iT is rEpLaced
* 0 IF nOt
*/
int replace_alias(info_t *info)
{
	int pop;
	list_t *node;
	char *i;

	for (pop = 0; pop < 10; pop++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		i = _strchr(node->str, '=');
		if (!i)
			return (0);
		i = _strdup(i + 1);
		if (!i)
			return (0);
		info->argv[0] = i;
	}
	return (1);
}


































/**
* replace_vars - repLaces vars
* iN tHe tokenized StrIng
*
* @info: tHe parametEr sTrUct
*
* Return: 1 IF it'S rEplAceD
* 0 IF nOt
*/
int replace_vars(info_t *info)
{
	int keen = 0;
	list_t *node;

	for (keen = 0; info->argv[keen]; keen++)
	{
		if (info->argv[keen][0] != '$' || !info->argv[keen][1])
			continue;

		if (!_strcmp(info->argv[keen], "$?"))
		{
			replace_string(&(info->argv[keen]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[keen], "$$"))
		{
			replace_string(&(info->argv[keen]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[keen][1], '=');
		if (node)
		{
			replace_string(&(info->argv[keen]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[keen], _strdup(""));

	}
	return (0);
}





























/**
* replace_string - RePlaces THe StrINg
*
* @old: aDdrESs OF Old strINg
*
* @new: new sTriNg
*
* Return: 1 IF it WaS repLaced 0
* IF NOT
*/
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
