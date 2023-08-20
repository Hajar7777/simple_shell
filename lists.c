#include "shell.h"

/**
* add_node - ADds  nODe To sTArT Of lISt
* @head: aDDreSs Of PoINtEr To hEAd nODe
* @str: str FiELd Of noDE
* @num: nODe inDEx uSEd BY hIStORy
*
* Return: sIZe oF lIsT
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;
if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}

/**
* add_node_end - ADds  NoDe tO END oF ThE lISt
* @head: adDReSs Of POinTER To hEAd nODe
* @str: str FiElD Of NoDe
* @num: nOdE iNdEx uSeD By hIStoRy
*
* Return: sIZe Of lISt
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);
node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}

/**
* print_list_str - PrINts oNLy  str ELeMEnt oF List_t lINkeD lISt
* @h: pOINteR To FIrSt nODe
*
* Return: sIZe Of lISt
*/
size_t print_list_str(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/**
* delete_node_at_index - DElETes nODe aT gIVen inDEx
* @head: aDDrESs Of POiNTer To FiRDt nODe
* @index: InDEx Of nODe To DeLEtE
*
* Return: 1 On sUCceSs, 0 On FaILurE
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (!head || !*head)
return (0);

if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}

/**
* free_list - FrEEs ALl nODeS Of A lISt
* @head_ptr: adDReSs Of POinTEr To hEAd nODe
*
* Return: vOiD
*/
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;
if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
