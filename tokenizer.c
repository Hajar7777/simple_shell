#include "shell.h"





































/**
* **strtow - SplItS STRING inTO words
* DElimiTers That RepeteD are TO Be ignored
*
* @str: INput strING
*
* @d: DelimETer strING
*
* Return: a pointer TO ArraY OF strIngs
* NULL IF failurE
*/

char **strtow(char *str, char *d)
{
	int hi, jio, kia, mel, numwrds = 0;
	char **r;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (hi = 0; str[hi] != '\0'; hi++)
		if (!is_delim(str[hi], d) && (is_delim(str[hi + 1], d) || !str[hi + 1]))
			numwrds++;

	if (numwrds == 0)
		return (NULL);
	r = malloc((1 + numwrds) * sizeof(char *));
	if (!r)
		return (NULL);
	for (hi = 0, jio = 0; jio < numwrds; jio++)
	{
		while (is_delim(str[hi], d))
			hi++;
		kia = 0;
		while (!is_delim(str[hi + kia], d) && str[hi + kia])
			kia++;
		r[jio] = malloc((kia + 1) * sizeof(char));
		if (!r[jio])
		{
			for (kia = 0; kia < jio; kia++)
				free(r[kia]);
			free(r);
			return (NULL);
		}
		for (mel = 0; mel < kia; mel++)
			r[jio][mel] = str[hi++];
		r[jio][mel] = 0;
	}
	r[jio] = NULL;
	return (r);
}









































/**
* **strtow2 - spliTS STRing TO worDs
*
* @str: tHe INput stRING
*
* @d: tHe dElimEter
*
* Return: PoiNter to aRRay of strINgs
* NULL IF failUre
*/
char **strtow2(char *str, char d)
{
	int hi, jio, kia, mel, numwrds = 0;
	char **r;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (hi = 0; str[hi] != '\0'; hi++)
		if ((str[hi] != d && str[hi + 1] == d) ||
				    (str[hi] != d && !str[hi + 1]) || str[hi + 1] == d)
			numwrds++;
	if (numwrds == 0)
		return (NULL);
	r = malloc((1 + numwrds) * sizeof(char *));
	if (!r)
		return (NULL);
	for (hi = 0, jio = 0; jio < numwrds; jio++)
	{
		while (str[hi] == d && str[hi] != d)
			hi++;
		kia = 0;
		while (str[hi + kia] != d && str[hi + kia] && str[hi + kia] != d)
			kia++;
		r[jio] = malloc((kia + 1) * sizeof(char));
		if (!r[jio])
		{
			for (kia = 0; kia < jio; kia++)
				free(r[kia]);
			free(r);
			return (NULL);
		}
		for (mel = 0; mel < kia; mel++)
			r[jio][mel] = str[hi++];
		r[jio][mel] = 0;
	}
	r[jio] = NULL;
	return (r);
}
