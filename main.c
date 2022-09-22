//----------------------------------------------------------------------------------------------------
//! @brief ��������� �������
//!
//! @author ������� ���������
//! @file main.cpp
//! @date 26.08.2022
//!
//! @copyright Copyright (c) 2022
//----------------------------------------------------------------------------------------------------
#include <stdlib.h>
#include "Functions.h"

int main()
{
    FILE *file_read = NULL;

    file_read = fopen("test.txt", "r"); // в функцию
    
    fseek(file_read, 0, SEEK_END); //
    
    int k = ftell(file_read); //

    fseek(file_read, 0, SEEK_SET); //

    char *ptr_string = (char *) calloc (k, sizeof(char)); //
    
    my_fgets(ptr_string, 500, file_read); //

    fclose(file_read); //
    
    // printf("%s\n", ptr_string); check for good
    
    int t = count_lines (ptr_string);
    
    printf("%d\n", t);
    // till this point all works good
    //printf("%s\n", ptr_string);

    struct LINE *my_lines = make_array(t, ptr_string);

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < my_lines[i].size; j++)
            printf("%c", my_lines[i].ptr[j]);
        printf("\n----------------------\n");
    }

    free(my_lines);
    free(ptr_string);
}

