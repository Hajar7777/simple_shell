#include "shell.h"

















/**
*_eputs - LisTs INpuT stRIng
*
* @str: strING To pRinT
*
* Return: NOThiNg
*/
void _eputs(char *str)
{
int imko = 0;
if (!str)
return;
while (str[imko] != '\0')
{
_eputchar(str[imko]);
imko++;
}
}




































/**
* _eputchar - LiSTs CHar c To sTDErr
*
* @c: CHarACtER To be PRinTED
*
* Return: 1 IF SUccEss
* -1 IF ERror & eRRno Is SEt accOrdinlY
*/
int _eputchar(char c)
{
static int ilp;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || ilp >= WRITE_BUF_SIZE)
{
write(2, buf, ilp);
ilp = 0;
}
if (c != BUF_FLUSH)
buf[ilp++] = c;
return (1);
}


























/**
* _putfd - PrinTs CHaRActER c To fd thaT is GivEn
*
* @c: CHarACteR To be PRinTed
*
* @fd: fiLEdeSCriPTor To be WRiTten To
*
* Return: 1 If sUCCess
* -1 IF ErrOR & eRRno IS sEt aCCORDINGlY
*/
int _putfd(char c, int fd)
{
static int tiara;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || tiara >= WRITE_BUF_SIZE)
{
write(fd, buf, tiara);
tiara = 0;
}
if (c != BUF_FLUSH)
buf[tiara++] = c;
return (1);
}



































/**
*_putsfd - LisTs INpuT STriNG
*
* @str: STrINg To PRinT
*
* @fd: FILEDEscRIpToR To be WRiTten To
*
* Return:NUmbER of CHarS pUt
*/
int _putsfd(char *str, int fd)
{
int kiko = 0;
if (!str)
return (0);
while (*str)
{
kiko += _putfd(*str++, fd);
}
return (kiko);
}
