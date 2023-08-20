#include "shell.h"





































/**
* get_environ - PrintS strINg aRRay cOPy Of environ
*
* @info: StRUctURe havINg pRobABle arGs
*
* Return: ALWays 0( SuccEss)
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}





































/**
* _unsetenv - DeleTes ENviROnmENt vARiaBLe
*
* @info: Structure HAVing probAble argS
*
* @var: strINg env variablE pROpERty
*
* Return: 1 IF deletED 0 IF NOT
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t exo = 0;
char *x;

if (!node || !var)
return (0);

while (node)
{
x = starts_with(node->str, var);
if (x && *x == '=')
{
info->env_changed = delete_node_at_index(&(info->env), exo);
exo = 0;
node = info->env;
continue;
}
node = node->next;
exo++;
}
return (info->env_changed);
}



















































/**
* _setenv - StartS nEw ENv VAriabLe
*
* @info: StRUcTUre HaVIng probAble ArgS
*
* @var: strINg env variabLe pROpERty
*
* @value:strINGg env variABle VAluE
*
* Return: AlwAYs 0(SuccESS)
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *r;
if (!var || !value)
return (0);
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
r = starts_with(node->str, var);
if (r && *r == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
