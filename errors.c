#include "shell.h"

/**
*_eputs - PRinTs INpuT stRIng
* @str: strING To Be PRinTEd
*
* Return: NOThiNg
*/
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
* _eputchar - WRitES  CHarACteR c To sTDErr
* @c: CHarACtER To PRinT
*
* Return: ON SUccEss 1.
* ON ERroR, -1 Is REtuRNed, ANd eRRno Is SEt aPProPrIAteLY.
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
* _putfd - WRitES  CHaRActER c To GIveN fd
* @c: CHarACteR To PRinT
* @fd:fiLEdeSCriPTor To WRiTe To
*
* Return: ON SUccESs 1.
* On eRRor, -1 Is reTUrNED, anD eRRno IS sEt aPProPRiaTElY.
*/
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
*_putsfd - PRinTs INpuT STriNG
* @str: STrINg To BE PRinTEd
* @fd: FILEDEscRIpToR To WRiTe To
*
* Return:NUmbER of CHarS pUt
*/
int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
