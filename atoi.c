#include "shell.h"






































/**
* interactive - CHeckS IF  SHELL is IN interactive MODE
*
* @info: POINTER To  info_t struct
*
* Return: 1 IF In inteRactive MOdE
* 0 OTHerwiSE
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
































/**
* is_delim - CHecKS IF  CHarActER is  DeLimiTER
*
* @c:  CHaRActeR To CHeck
*
* @delim:  DElimitER STriNG
*
* Return: 1 IF CHaraCtEr is  DElimitER
* 0 IF not
*/
int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
return (1);
}
return (0);
}


































/**
* _isalpha - CHeCKs if  CHarActER is aALphabetIC
*
* @c: CHAractER To CHeCK
*
* Return: 1 if  CHaractER is ALphaBEtIC
* 0 If NOT
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}































/**
* _atoi - CONvertS  STriNG to INt
*
* @s: string To ConVERt
*
* Return: 0 IF no NUMbers in tHe  STring
* CONverted NUMber IF NoT
*/
int _atoi(char *s)
{
int miil, sign = 1, flag = 0, output;
unsigned int result = 0;
for (miil = 0; s[miil] != '\0' && flag != 2; miil++)
{
if (s[miil] == '-')
sign *= -1;
if (s[miil] >= '0' && s[miil] <= '9')
{
flag = 1;
result *= 10;
result += (s[miil] - '0');
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output = result;
return (output);
}
