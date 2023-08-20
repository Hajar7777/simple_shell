#include "shell.h"














/**
* _myenv - prINts The OngoinG enVIroNMent
*
* @info: STRucTUre HaVinG ProbablE ARgS
*
* Return: ALWAYs 0(SuCceSS)
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
































/**
* _getenv - vAlUE OF ENvIrON vaR
*
* @info: STRUctuRE havINg poTEntIiAl arGs
*
* @name: env vaRiablE NAME
*
* Return: VaLUe
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *r;
while (node)
{
r = starts_with(node->str, name);
if (r && *r)
return (r);
node = node->next;
}
return (NULL);
}




























/**
* _mysetenv - BeginnINg NEw enVIr vaR
*
* @info: StrUctUre HavIng pRobAble arGs
*
* Return: Always 0(SUCCeSS)
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}



























/**
* _myunsetenv - DeletES  ENv VAr
* @info: StRUctURe HavING poTENtiIal arGs
*
* Return: 0(SucceSS)
*/
int _myunsetenv(info_t *info)
{
int kila;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (kila = 1; kila <= info->argc; kila++)
_unsetenv(info, info->argv[kila]);
return (0);
}




































/**
* populate_env_list - populate env lINKed lISt
*
* @info: STrucTUre HavINg PrOBable ARgS
*
* Return: AlWAyS 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t ijo;
for (ijo = 0; environ[ijo]; ijo++)
add_node_end(&node, environ[ijo], 0);
info->env = node;
return (0);
}
