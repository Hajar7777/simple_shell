#include "shell.h"













































/**
* bfree - FrEes a POinter
* & TurNES tHE aDDress NULL
*
* @ptr: aDdrRESs OF tHe poinTEr to BE freeD
*
* Return: 1 iF IT GOT Free
* 0 IF nOt
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
