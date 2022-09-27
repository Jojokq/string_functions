#ifndef FUNCTIONS
#define FUNCTIONS

#define nullptr NULL;

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct LINE 
{
    char *ptr;
    int size;

};

int my_puts (const char *s);

char *my_strchr(const char *cs, int c);

size_t my_strlen (const char *cs);

char *my_strcpy(char *s, const char *ct);

char *my_strncpy(char *s, const char *ct, size_t n);

char *my_strcat(char *s, const char *ct);

char *my_strncat(char *s, const char *ct, size_t n);

char my_strcmp (const char *cs, const char *ct);

char *my_fgets(char *s, int n, FILE *stream);

char *my_strdup (const char *s);

int my_getline(char *line, int max);

int strcmp_pro(const struct LINE line1, const struct LINE line2);

int count_lines (char *ptr);

void bubble_sort (struct LINE *line, int line_count);

struct LINE *make_array(const int count, char *ptr);
#endif
