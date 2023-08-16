#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
int length = 0;

while (*s != '\0')
{
length++;
s++;
}

return (length);
}


/**
* _strncmp - compare string values with number of byte
* @s1: input value
* @s2: input value
* @n: number of byte to compare
* Return: s1[i] - s2[i]
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
for( i = 0; i < n; i++)
{
if(s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
if(s1[i] == '\0')
{
break; 
}
}

return (0);
}

/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

size_t a;

for (a = 0; src[a] != '\0'; a++)
{
dest[a] = src[a];
}
dest[a] = '\0';

return (dest);
}
