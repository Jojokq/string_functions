#include "Functions.h"

int my_puts(const char *s)
{
    int i = 0;

    while (*s)
    {
        putc(*s++, stdout);
    }

    if (i !=0)
        return 1;
    else
        return '\0';


}

char *my_strchr(const char *cs, int c)
{
    int i = 0;

    while (*cs)
    {
        if (*cs == c)
            return (char *) cs;
        else
            cs++;
    }
    return nullptr;
}

size_t my_strlen (const char *cs)
{
    size_t i = 0;

    while (cs[i++] != '\0');

    return i;
}

char *my_strcpy(char *s, const char *ct)
{
    int i = 0;

    while (*ct)
    {

        *s++ = *ct++;

         i++;
    }

    *s = '\0';

    return s-i;
}

char *my_strncpy(char *s, const char *ct, size_t n)
{
    char *ptr = s;

    while (*ct && (n > 0))
    {
        *ptr++ = *ct++;

         n--;
    }

    *ptr = '\0';

    while(n > 0)
    {
        *ptr++ = '\0';

         n--;
    }

    return s;
}

char *my_strcat(char *s, const char *ct)
{
    char *ptr = s + my_strlen(s) - 1;

    while (*ct )
        *ptr++ = *ct++;

    *ptr = '\0';

    return s;
}

char *my_strncat(char *s, const char *ct, size_t n)
{
    char *ptr = s + my_strlen(s) - 1;

    while (*ct)
    {
        *ptr++ = *ct++;

         n--;

        if (n == 0)
            break;
    }

    *ptr = '\0';

    while ( n > 0)
    {
        *ptr++ = '\0';

         n--;
    }

    return s;
}

char my_strcmp (const char *cs, const char *ct)
{
    int i = 0;

    while (*cs == *ct)
    {
        if (*cs == '\0')
            return 0;

        cs++;
        ct++;
    }

    if (*cs > *ct)
        return 1;
    else
        return -1;
}

char *my_fgets(char *s, int n, FILE *stream)
{
    char *ptr = s;

    *ptr++ = fgetc(stream);

    while ((--n>0) && *ptr != EOF)
        {
            *ptr++ = fgetc(stream);
        }

    *ptr = '\0';

    return s;
}

char *my_strdup (const char *s)
{
    char *p = NULL;
    char *str = NULL;

    p = (char*)calloc(my_strlen(s+1));

    str = p;

    while(*s)
        *p++ = *s++;
    *p = '\0';
    return str;
}

int getline(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}

