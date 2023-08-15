#include "shell.h"







































/**
* _memset - fiLLs memory wiTH a CONSTANT bYte
*
* @s: tHHe pOinTEr to tHe meMORy arEA
*
* @b: tHe bYTe to fiLL CHAR s wITh
*
* @n: THe amoUNt of bYTes to FiLL
*
* Return: PoInter s to tHe mEmoRy aREa s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ila;

	for (ila = 0; ila < n; ila++)
		s[ila] = b;
	return (s);
}






















/**
* ffree - frEEs a sTring Of stRIngs
*
* @pp: strINg Of stRiNgs
*/
void ffree(char **pp)
{
	char **k = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(k);
}

/**
* _realloc - REallocates a BlOck of MemOry
*
* @ptr: pOInter TO prevIOUs maLLocated blOCk
* @old_size: byTE sIZe OF prEvIOUs blOCk
* @new_size: byTE sIzE of nEw block
*
* Return: poINtEr
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *r;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	r = malloc(new_size);
	if (!r)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		r[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (r);
}
