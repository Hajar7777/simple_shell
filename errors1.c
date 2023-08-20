#include "shell.h"























/**
* _erratoi - cONvERts strINg To An inT
*
* @s: strINg To COnvERt
*
* Return: 0 If No nUMbeRS iN StrING
* -1 IF erORr
*/
int _erratoi(char *s)
{
int iki = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: WHy DOes tHIs one mAKe mAin retUrn 255? */
for (iki = 0;  s[iki] != '\0'; iki++)
{
if (s[iki] >= '0' && s[iki] <= '9')
{
result *= 10;
result += (s[iki] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}






















/**
* print_error - LisTS eRRor mESsaGe
*
* @info: PAraMEteR and REtuRN inFO STruCt
*
* @estr: strING having identifIed ERror tYPe
*
* Return: 0 If no NUM exisTS In strING
* cONverTEd nUMber if NOT
* -1 on eRRor
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
* print_d - fUNctiON Lists DEcimal
*
* @input: inPUt
*
* @fd: fiLEdeSCriPTor To be WRittEn To
*
* Return: NUMber Of CHarACteRS thaT aRE PRinTEd
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int ipo, count = 0;
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
for (ipo = 1000000000; ipo > 1; ipo /= 10)
{
if (_abs_ / ipo)
{
__putchar('0' + current / ipo);
count++;
}
current %= ipo;
}
__putchar('0' + current);
count++;
return (count);
}





















/**
* convert_number - cONvERteR fUNctIOn cLONe
*
* @num: nUMbeR
*
* @base: bAsE
*
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
unsigned long b = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
b = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = array[b % base];
b /= base;
} while (b != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

































/**
* remove_comments - fUN changes 1st appearance Of '#' with '\0'
*
* @buf: ADdrESs Of strINg To be MOdiFied
*
* Return: 0 on SuccESs
*/
void remove_comments(char *buf)
{
int iak;

for (iak = 0; buf[iak] != '\0'; iak++)
if (buf[iak] == '#' && (!iak || buf[iak - 1] == ' '))
{
buf[iak] = '\0';
break;
}
}
