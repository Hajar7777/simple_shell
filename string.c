#include "shell.h"












/**
* _strlen - RetuRns tHe Length of STRING
*
* @s: tHe string with length to BE checkED
*
* Return: INT LenGth of STRING
*/
int _strlen(char *s)
{
	int mil = 0;

	if (!s)
		return (0);

	while (*s++)
		mil++;
	return (mil);
}

















































/**
* _strcmp - PerfOrms LExicogarPHIC comparison OF 2 strAngs
*
* @s1: 1st strAng
*
* @s2: 2nd strAng
*
* Return: NEGAtive IF s1 < s2
* POSive IF s1 > s2
* ZERO IF s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}




















/**
* starts_with - ChEcks IF nEEdle STarts wIth haystack
*
* @haystack: StRinG to BE SearchED
*
* @needle: tHe SubsTring to BE found
*
* Return: aDDress OF nExt char OF haystack
* OR NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}































/**
* _strcat - cOncaTenates 2 STringS
*
* @dest: deStinatIon BUFFER
*
* @src: SOurCe BUFFER
*
* Return: THE POinter TO destiNAtion BUFFer
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
