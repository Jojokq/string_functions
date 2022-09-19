
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

    file_read = fopen("test.txt", "r");
    
    int k = 0;

    fseek(file_read, 0, SEEK_END);
    
    k = ftell(file_read);

    fseek(file_read, 0, SEEK_SET);

    char *ptr_string = (char *) calloc (k, sizeof(char));
    
    while (!feof(file_read))
    {
        my_fgets(ptr_string, 500, file_read);    
    }
    fclose(file_read);
    //till this point all works good
    char *p = ptr_string;
    
    for (; *p != '\0'; ++*p)
    {
        if ((*p == '\n') && (*(p + 1) == '\n'))
            printf("|");
    }

    free(ptr_string);
}

