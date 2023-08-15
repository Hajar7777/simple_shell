#ifndef _SHELL_H_
#define _SHELL_H_









#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>







/* for convert_number() */
#define CONVERT_UNSIGNED        2
#define CONVERT_LOWERCASE       1






/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3










/* 1 if using system getline() */
#define USE_STROK       0
#define USE_GETLINE     0











/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1












#define HIST_FILE	    ".simple_shell_history"
#define HIST_MAX	    4096

extern char **environ;























/**
* struct liststr - SIingly lInkEd liST
*
* @num: the NUM fIeld
*
* @str: STrinG
*
* @next: PoinTs TO tHe Next Node
*/






typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;























/**
* struct passinfo - CONTains pseudo-arguements to be passed into A fUnction
*                   aLLowing uNiform PRototype foR functioN pointeR strUcT
* @arg: A striNg geNerateD frOm getline ContAininG arguEmentS
* @argv: An aRRay of StriNgs GeneraTed From arg
* @path: a string paTh fOr tHE currenT coMmanD
* @argc: The argumenT coUnt
* @line_count: tHe ErroR cOunt
* @err_num: The eRRor Code fOr exIt()s
* @linecount_flag: IF oN coUnt thIs line of input
* @fname: the PROGRAM filename
* @env: liNkeD liSt Local cOpy oF enViron
* @environ: custOM modiFied cOpy oF enViron from LL env
* @history: tHe hIstory Node
* @alias: tHe alias NodE
* @env_changed: on IF envIron wAs chANgeD
* @status: tHe retuRn sTaTus Of the laST execUTEd command
* @cmd_buf: AddrEss of PoinTer To cmd_buf on if chaining
* @cmd_buf_type: CMD_type ||, &&, ;
* @readfd: the Fd fRom whiCh To reaD liNe Input
* @histcount: tHe HistOry line NUMBER count
*/
















typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer TO cmd ; chain buffer, For Memory MangEment */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}





















/**
* struct builtin - CoNtains A builtIN string and RelAted FUnction
*
* @type: tHe builtIN coMMand flaG
*
* @func: tHe FUnction
*/
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;




























/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);


/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);




/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);




/* loophsh.c */
int loophsh(char **);






/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);





/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);







/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);







/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);






/* toem_memory.c */
int bfree(void **);








/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);






/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);






/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);







/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);






/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);










/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);







/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);









/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);








/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);










/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);






int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);





/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);




/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);







/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);







/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);












#endif

