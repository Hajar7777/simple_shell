#include "shell.h"

























/**
* get_history_file - printS hIStoRY fIlE
*
* @info: PaRAmeTEr strUCt
*
* Return: aLLocaTEd strINg HAVIng HIstORy fILe
*/

char *get_history_file(info_t *info)
{
char *bufr, *dirry;
dirry = _getenv(info, "HOME=");
if (!dirry)
return (NULL);
bufr = malloc(sizeof(char) * (_strlen(dirry) + _strlen(HIST_FILE) + 2));
if (!bufr)
return (NULL);
bufr[0] = 0;
_strcpy(bufr, dirry);
_strcat(bufr, "/");
_strcat(bufr, HIST_FILE);
return (bufr);
}





































/**
* write_history - crEAtes fILe
* OR aDDs It To EXistINg fILe
*
* @info: PAraMEter strUCt
*
* Return: 1 IF suCCess
* -1 IF noT
*/
int write_history(info_t *info)
{
ssize_t fed;
char *filename = get_history_file(info);
list_t *node = NULL;
if (!filename)
return (-1);

fed = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fed == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fed);
_putfd('\n', fed);
}
_putfd(BUF_FLUSH, fed);
close(fed);
return (1);
}

































/**
* read_history - rEAds HIstORy fROm fILe
*
* @info: PArAMetER stRUcT
*
* Return: HIstCOuNt ON sUCceSs
* 0 If Not
*/
int read_history(info_t *info)
{
int ilala, last = 0, linecount = 0;
ssize_t fed, rdlen, fsize = 0;
struct stat st;
char *bufr = NULL, *filename = get_history_file(info);
if (!filename)
return (0);

fed = open(filename, O_RDONLY);
free(filename);
if (fed == -1)
return (0);
if (!fstat(fed, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
bufr = malloc(sizeof(char) * (fsize + 1));
if (!bufr)
return (0);
rdlen = read(fed, bufr, fsize);
bufr[fsize] = 0;
if (rdlen <= 0)
return (free(bufr), 0);
close(fed);
for (ilala = 0; ilala < fsize; ilala++)
if (bufr[ilala] == '\n')
{
bufr[ilala] = 0;
build_history_list(info, bufr + last, linecount++);
last = ilala + 1;
}
if (last != ilala)
build_history_list(info, bufr + last, linecount++);
free(bufr);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}
























/**
* build_history_list - aDDs enTRy To  HIstORy lINkeD lISt
*
* @info: STRucTUre HviNG pRObaBLe ARgS
*
* @buf: buFFeR
*
* @linecount: HIStorY lINecOUnT hIStcOUnt
*
* Return: AlWAyS 0(SuccESS)
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);
if (!info->history)
info->history = node;
return (0);
}























/**
* renumber_history - rENumBErS HIstORy
* InKEd LITt afTEr CHanGEs
*
* @info: STRuCTurE cONtaINiNg probABle aRGs
*
* Return: nEw hIStcOUNt
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int ior = 0;
while (node)
{
node->num = ior++;
node = node->next;
}
return (info->histcount = ior);
}
