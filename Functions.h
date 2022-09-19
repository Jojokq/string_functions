#ifndef FUNCTIONS
#define FUNCTIONS

#define nullptr NULL;

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

struct str
{
    char *s;
};

struct LINE 
{
    char *ptr_to_str;
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

//int strsmp_pro(const char *cs, const char*ct);

//char *copy_strs(char arr[i], const char i);


//char *one_string_to_lot(LINE *one_line, char *ptr_to_str);
#endif
