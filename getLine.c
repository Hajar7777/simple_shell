#include "shell.h"





























/**
* input_buf - bUFFeRs coMMaNdS that ArE cHained
*
* @info: parameter strUct
*
* @buf: address of BUFF
*
* @len: address of LEN varIABLE
*
* Return: bytes read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;
if (!*len) /* if nothing left in the buffer LOAD it */
{
/*bFrEE((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0'; /* REmOve All tRAilINg nEWlINe */
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* IF (_strchr(*buf, ';')) Is A coMManD ChAIn? */
{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}





































/**
* get_input - prInts a lIne
* @info: PArAMeteR stRUcT
* Return: bYtES rEAd
*/
ssize_t get_input(info_t *info)
{
static char *buf; /* ';' coMManD chAIn BUFfeR */
static size_t ikil, jio, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1) /* EOF */
return (-1);
if (len)	/* we have coMmaNdS lEFt IN  cHAiN bUFfeR */
{
jio = ikil; /* iNIt NeW itERatOR To cURreNT bUF poSItIOn */
p = buf + ikil; /* get pointer for return */
check_chain(info, buf, &jio, ikil, len);
while (jio < len) /* iTEraTe To seMIcOLon OR eND */
{
if (is_chain(info, buf, &jio))
break;
jio++;
}

ikil = jio + 1; /* inCReMEnT pASt nuLLeD ';'' */
if (ikil >= len) /* rEAchED END oF bUFfeER? */
{
ikil = len = 0; /* rESeT pOSiTIon aNd lENgTh */
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p; /* PASs bACk pOInTer To cURreNt COmmANd pOSiTIon */
return (_strlen(p)); /* return lEnGth OF CUrrENt cOMMand */
}

*buf_p = buf; /* eLSe NoT  CHaiN, pASs bACk bUFfeR FrOm _getline() */
return (r); /* return lENGth Of bUFfeR fRoM _getline() */
}




















/**
* read_buf - rEADs  bUFFer
*
* @info: pARamETer sRUuct
*
* @buf: bUFfEr
*
* @i: sIZe
*
* Return: r
*/
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;
if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}


















/**
* _getline - pRinTs nEXt lINE OF INpUT fROm STDIN
*
* @info: pARamETer sTRUct
*
* @ptr: aDDrESs Of pOIntRr To bUFfeR
* pREalLoWAtED OR NULL
*
* @length: size of prealLOCATED ptr buffer if nOt NULL
*
* Return: s
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t ilj, len;
size_t kad;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (ilj == len)
ilj = len = 0;
r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + ilj, '\n');
kad = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, s, s ? s + kad : kad + 1);
if (!new_p) /* MALLOC FAllURE! */
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buf + ilj, kad - ilj);
else
_strncpy(new_p, buf + ilj, kad - ilj + 1);

s += kad - ilj;
ilj = kad;
p = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}


























/**
* sigintHandler - bLOCkS ctrl-C
*
* @sig_num:SIgnAL NUm
*
* Return: Empty
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
