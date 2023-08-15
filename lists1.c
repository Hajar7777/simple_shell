#include "shell.h"































/**
* list_len - deterINEes lenGTHh of lINked LIST
*
* @h: POintEr TO 1st nodE
*
* Return: siZE of ThE lIst
*/
size_t list_len(const list_t *h)
{
	size_t imamah = 0;

	while (h)
	{
		h = h->next;
		imamah++;
	}
	return (imamah);
}


























/**
* list_to_strings - rETurns an aRRay of stRiNgs of tHe list->str
*
* @head: POintER TO 1st NodE
*
* Return: aRRay of sTRINGS
*/
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t iraa = list_len(head), jio;
	char **strs;
	char *str;

	if (!head || !iraa)
		return (NULL);
	strs = malloc(sizeof(char *) * (iraa + 1));
	if (!strs)
		return (NULL);
	for (iraa = 0; node; node = node->next, iraa++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (jio = 0; jio < iraa; jio++)
				free(strs[jio]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[iraa] = str;
	}
	strs[iraa] = NULL;
	return (strs);
}
































/**
* print_list - prINTs all eLEments of A list_t liNKed LiST
*
* @h: poiNTer TO 1st noDE
*
* Return: sIZe of tHe LiSt
*/
size_t print_list(const list_t *h)
{
	size_t ilala = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		ilala++;
	}
	return (ilala);
}


































/**
* node_starts_with - retUrns noDe
* WITH stRing stArts wiTH PREFIX
*
* @node: poINter TO lIst hEAd
*
* @prefix: strINg to BE maTCchED
*
* @c: 2nd CHAR aftEr preFIx to mAtCh
*
* Return: mATch nOde
* oR NULL
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *r = NULL;

	while (node)
	{
		r = starts_with(node->str, prefix);
		if (r && ((c == -1) || (*r == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}



























/**
* get_node_index - gEts tHe INdEX of A nOde
*
* @head: pOINter to lISt hEad
*
* @node: PoNtEr TO THe nOde
*
* Return: INDEX of nOde OR -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t iraa = 0;

	while (head)
	{
		if (head == node)
			return (iraa);
		head = head->next;
		iraa++;
	}
	return (-1);
}
