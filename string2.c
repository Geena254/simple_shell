#include "shell.h"
/**
* _strcat - concatenates two strings
* @dest: input value
* @src: input value
*
* Return: void
*/
char *_strcat(char *dest, char *src)
{
int i;
int j;

i = 0;
while (dest[i] != '\0')
{
i++;
}
j = 0;
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}

dest[i] = '\0';
return (dest);
}

/**
* _strncpy - copy a string
* @dest: input value
* @src: input value
* @n: input value
*
* Return: (dest)
*/

char *_strncpy(char *dest, char *src, size_t n)
{
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
  dest[i] = src[i];
for ( ; i < n; i++)
  dest[i] = '\0';

return (dest);
}
