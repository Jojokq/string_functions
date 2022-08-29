
//----------------------------------------------------------------------------------------------------
//! @brief Строковые функции
//!
//! @author Евгений Мелешенко
//! @file main.cpp
//! @date 26.08.2022
//!
//! @copyright Copyright (c) 2022
//----------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include "Functions.h"

int main()
{

    char s[20] = "something";
    char s1[30] = "fadsfdafmdskfsuis";

    printf("puts : ");
    my_puts(s);

    printf("\nstrchr : %d\n", my_strchr(s, 'o') - s);

    printf("strlen : %d\n", my_strlen(s));

    printf("strcpy : ");
    my_puts(my_strcpy(s1, s));

    printf("\nstrncpy(3) : ");
    my_puts(my_strncpy(s1, s, 3));

    printf("\n strcat : ");
    my_puts(my_strcat(s1, s));

    printf("\n strncat : ");
    my_puts(my_strncat(s1,s,3));

    printf("\n strcmp : ");
    printf("%d", my_strcmp(s,s1));

    FILE *fp;
    fp = fopen("test.txt", "r");
    printf("\n fgets : ");
    my_puts(my_fgets(s1, 3, fp));

    printf("\n strdup : ");
    char *s2 =  strdup(s);
    my_puts(s2);

}


