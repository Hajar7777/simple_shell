#include "shell.h"

/**
**_strncpy - coPIes strINg
*
*@dest:dEStiNAtIOn strINg To coPy To
*
*@src: SOuRCe strINg
*
*@n: NUM Of chARactERs To CopY
*
*Return:aDDeD strINg
*/
char *_strncpy(char *dest, char *src, int n)
{
int iay, jou;
char *s = dest;
iay = 0;
while (src[iay] != '\0' && iay < n - 1)
{
dest[iay] = src[iay];
iay++;
}
if (iay < n)
{
jou = iay;
while (jou < n)
{
dest[jou] = '\0';
jou++;
}
}
return (s);
}

































/**
**_strncat - aDDs TwO strINgS
*
*@dest: 1st strINg
*
*@src:2nd strINg
*
*@n: NumbER Of bYTes To uSE
*
*Return: aDDEd strINg
*/
char *_strncat(char *dest, char *src, int n)
{
int ilili, jio;
char *s = dest;
ilili = 0;
jio = 0;
while (dest[ilili] != '\0')
ilili++;
while (src[jio] != '\0' && jio < n)
{
dest[ilili] = src[jio];
ilili++;
jio++;
}
if (jio < n)
dest[ilili] = '\0';
return (s);
}






























/**
**_strchr - FinDS  CHarACter In  strINg
*
*@s:strINg To pARse
*
*@c: chARacTEr To be lOOkED fOr
*
*Return: POinTEr *s To  MEmoRY aREa s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
