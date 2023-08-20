#include "shell.h"























/**
* _myhistory - disPLAYS  HIStoRY LIst 
* 1 COMmand BY LIne STARTing 0
*
* @info: StRUctURe HAVing ProBABle ARGs
*
* Return: ALWAYS 0(SUCCESs)
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}























/**
* unset_alias - PUTs Alias To strING
*
* @info: parAMetER strUCT
*
* @str: strING alias
*
* Return: 0 IF SUCcess
* 1  ERrOR
*/
int unset_alias(info_t *info, char *str)
{
char *o, v;
int ret;
o = _strchr(str, '=');
if (!o)
return (1);
v = *o;
*o = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*o = v;
return (ret);
}






















/**
* set_alias - SETs alias TO STRring
*
* @info: ParaMEtER strUCT
*
* @str: strING alias
*
* Retun: 0 sUccess
* 1 IF erRor
*/
int set_alias(info_t *info, char *str)
{
char *d;
d = _strchr(str, '=');
if (!d)
return (1);
if (!*++d)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}




























/**
* print_alias - LisTS alias STRING
* @node: Alias node
*
* Return: 0 IF SuCCeSS
* 1 IF ERRor
*/
int print_alias(list_t *node)
{
char *o = NULL, *s = NULL;
if (node)
{
o = _strchr(node->str, '=');
for (s = node->str; s <= o; s++)
_putchar(*s);
_putchar('\'');
_puts(o + 1);
_puts("'\n");
return (0);
}
return (1);
}






























/**
* _myalias - ImitaTES ALIAS builtin
*
* @info: STRUCTURE COntAInING PrObaLe ARGS
*
*  Return: Always 0(SuccESS)
*/
int _myalias(info_t *info)
{
int rial = 0;
char *o = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (rial = 1; info->argv[rial]; rial++)
{
o = _strchr(info->argv[rial], '=');
if (o)
set_alias(info, info->argv[rial]);
else
print_alias(node_starts_with(info->alias, info->argv[rial], '='));
}

return (0);
}
