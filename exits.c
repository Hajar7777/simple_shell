#include "shell.h"

/**
**_strncpy - coPIes strINg
*@dest:dEStiNAtIOn strINg To Be coPIed To
*@src: SOuRCe strINg
*@n: amOUnt Of chARactERs To Be COpIEd
*Return: cONcatENateD strINg
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}

/**
**_strncat - cONcaTEnatEs TwO strINgS
*@dest: fIRst strINg
*@src:seCOnd strINg
*@n: amOUnt Of bYTes To Be mAXimALly uSEd
*Return: cONcaTEnaTEd strINg
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr - loCAteS  CHarACter In  strINg
*@s:strINg To Be pARsed
*@c: chARacTEr To lOOk fOr
*Return: (s) POinTEr To  MEmoRY aREa s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
