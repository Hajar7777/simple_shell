#include "shell.h"

/**
* interactive - CHeckS IF  SHELL is IN interactive MODE
* @info: POINTER To  info_t struct
*
* Return: 1 IF In interactive MOdE, 0 OTHerwiSE
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - CHecKS IF  CHarActER is  DeLimiTER
* @c:  CHaRActeR To CHeck
* @delim:  DElimitER STriNG
*
* Return: 1 IF CHaraCtEr is  DElimitER, 0 IF not
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
* @c: CHAractER To CHeCK
*
* Return: 1 if  CHaractER is ALphaBEtIC, 0 OTherwiSE
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
* _atoi - CONvertS a STriNG to AN INtegER
* @s: string To be ConVERted
*
* Return: 0 IF no NUMbers in  STring,  CONverted NUMber OTHerwiSE
*/
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
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
