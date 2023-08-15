#include "shell.h"


































































/**
* _strcpy - CopiEs STRIng
*
* @dest: tHE deStinatIOn
*
* @src: tHe SoUrCE
*
* Return: PoIntER TO DEStINATion
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}






































/**
* _strdup - duplICates A STRING
*
* @str: tHe STRING tO BE duplicatED
*
* Return: PoiNter tO duplicatED STRING
*/
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

























/**
* _puts - PRints AN INput STRING
*
* @str: strING to PRINT
*
* Return: EMPTY
*/
void _puts(char *str)
{
	int ick = 0;

	if (!str)
		return;
	while (str[ick] != '\0')
	{
		_putchar(str[ick]);
		ick++;
	}
}

























/**
* _putchar - WriTES tHe CHAR c to stdout
*
* @c: CHAR to BE printED
*
* Return: IF suCeESs 1
* IF eRRor -1 & errno is to Be sEt AccordinGlY
*/
int _putchar(char c)
{
	static int millie;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || millie >= WRITE_BUF_SIZE)
	{
		write(1, buf, millie);
		millie = 0;
	}
	if (c != BUF_FLUSH)
		buf[millie++] = c;
	return (1);
}
