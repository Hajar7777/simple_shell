#include "shell.h"

/**
* _erratoi - cONvERts strINg To An inTEgeR
* @s: strINg To Be COnvERtED
* Return: 0 If No nUMbeRS iN strINg, cONveRteD nUMbeR oTHerwISe
*       -1 on erORr
*/
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: WHy DOes tHIs mAKe mAIn return 255? */
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
* print_error - PRinTS eRRor mESsaGe
* @info:PAraMEteR & REtuRN inFO STruCt
* @estr: strING conTAINing spECiFIed ERror tYPe
* Return: 0 If no NUMberS In strING, cONverTEd nUMber oTHerwISe
*        -1 on eRRor
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
* print_d - fUNctiON PRinTs  DEciMAl (INteGEr) NUmbEr (bASe 10)
* @input: inPUt
* @fd: fiLEdeSCriPTor To WRitE To
*
* Return: NUMber Of CHarACteRS PRinTEd
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}

/**
* convert_number - cONvERteR fUNctIOn, cLONe Of IToa
* @num: nUMbeR
* @base: bAsE
* @flags: ARguMEnt FLagS
*
* Return: strING
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
* remove_comments - fUNCtioN REplACes FIrsT INstANce Of '#' with '\0'
* @buf: ADdrESs Of strINg To MOdiFY
*
* Return: AlWAys 0;
*/
void remove_comments(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
