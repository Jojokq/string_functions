#include "Functions.h"
//----------------------------------------------------------------------------------------------------
//! @brief �������, ��������������� ������
//!
//! @param[in] *s ��������� �� ��������������� ������
//!
//! @return 1, ���� �� ������, EOF, ���� ��������� ������
//----------------------------------------------------------------------------------------------------
int my_puts(const char *s)
{
    int i = 0;

    while (*s && i != EOF)
    {
        i = putc(*s++, stdout);
    }

    if (i != EOF)
        return 1;
    else
        return EOF;


}

//----------------------------------------------------------------------------------------------------
//! @brief �������, ������� ���� ������ � ������
//!
//! @param[in] *cs ��������� �� ������, � ������� ���� ������
//! @param[in] c ������� ������
//!
//! @return ���������� ��������� �� ������� ������, ���� �� ������, �� nullptr
//----------------------------------------------------------------------------------------------------
char *my_strchr(const char *cs, int c)
{

    while (*cs)
    {
        if (*cs == c)
            return (char *) cs;
        cs++;
    }
    return nullptr;
}

//----------------------------------------------------------------------------------------------------
//! @brief �������, ��������� ����� ������
//!
//! @param[in] *cs ������, � ������� ��������� ��������� �����
//!
//! @return ���������� ����� ������
//----------------------------------------------------------------------------------------------------
size_t my_strlen (const char *cs)
{
    size_t i = 0;

    while (cs[i++] != '\0') {}

    return i-1;
}

//----------------------------------------------------------------------------------------------------
//! @brief �������, ������� �������� ���������� ������ ct � ������ s
//!
//! @param[in] *ct ������, �� ������� ���������� ����������
//! @param[out] *s ������, � ������� ���������� ����������
//!
//! @return ��������� �� ������, � ������� ������������� ���������� ������ ������
//----------------------------------------------------------------------------------------------------
char *my_strcpy(char *s, const char *ct)
{
    char *ptr = s;

    while (*ct)
    {

        *s++ = *ct++;
    }

    *s = '\0';

    return ptr;
}

//----------------------------------------------------------------------------------------------------
//! @brief ������, ������� �������� �� ����� n �������� �� ������ ct � ������ s
//!
//! @param[in] *ct ������, �� ������� ���������� ����������
//! @param[in] n ������������ ����� ������������� ��������
//! @param[out] *s ������, � ������� ���������� ����������
//!
//! @return ��������� �� ������, � ������� ������������� ���������� ������ ������
//----------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------
//! @brief �������� ���������� ������ ct � ����� ������ s
//!
//! @param[in] *ct ������, �� ������� ���������� ����������
//! @param[out] *s ������, � ������� ���������� ����������
//!
//! @return ��������� �� ������, ����������� ����� ����������
//----------------------------------------------------------------------------------------------------
char *my_strcat(char *s, const char *ct)
{
    char *ptr = s + my_strlen(s) ;

    while (*ct )
        *ptr++ = *ct++;

    *ptr = '\0';

    return s;
}

//----------------------------------------------------------------------------------------------------
//! @brief �������� �� ����� n �������� �� ct � s
//!
//! @param[in] *ct ������, �� ������� ���������� ����������
//! @param[in] n ����������� ����� ������������� ��������
//! @param[out] *s ������, � ������� ���������� ����������
//!
//! @return ��������� �� ������, ����������� ����� ����������
//----------------------------------------------------------------------------------------------------
char *my_strncat(char *s, const char *ct, size_t n)
{
    char *ptr = s + my_strlen(s);

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

//----------------------------------------------------------------------------------------------------
//! @brief ���������� ��� ������
//!
//! @param[in] *cs,*ct ������������ ������
//!
//! @return 1, ���� cs>ct, -1 � �������� ������, 0 ��� ���������
//----------------------------------------------------------------------------------------------------
char my_strcmp (const char *cs, const char *ct)
{
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

//----------------------------------------------------------------------------------------------------
//! @brief �������, ����������� ������ �� �����
//!
//! @param[in] *stream ��������� �� ����� �����
//! @param[in] n ������������ ����� ��������� ������
//! @param[out] *s ��������� �� ������, � ������� �������� ���������� �����
//!
//! @return ��������� �� ������, � ������� �������� ���������� �����
//----------------------------------------------------------------------------------------------------
char *my_fgets(char *s, int n, FILE *stream)
{
    //printf("%s\n", s);

    char *ptr = s;

    *ptr++ = fgetc(stream);

    while ((n-- > 0) && !(feof(stream))) 
        *ptr++ = fgetc(stream);

    *ptr = '\0';
    
    return s;
}

//----------------------------------------------------------------------------------------------------
//! @brief �������, ������������� ���������� ������
//!
//! @param[in] *s ������, ������� ���������� ��������������
//!
//! @return ��������� �� ������ � ���������� �����������
//----------------------------------------------------------------------------------------------------
char *my_strdup (const char *s)
{
    char *p = NULL;
    char *str = NULL;

    p = (char*)calloc(my_strlen(s) + 1, sizeof (char));

    str = p;

    while(*s)
        *p++ = *s++;
    *p = '\0';
    return str;
}

//----------------------------------------------------------------------------------------------------
//! @brief �������, ����������� ������ �� stdin
//!
//! @param[in] max ������������ ����� ��������� ��������
//! @param[out] *line ��������� �� ������, � ������� �������� ���������� stdin
//!
//! @return ����� ������
//----------------------------------------------------------------------------------------------------
int my_getline(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}

/* int strsmp_pro(const char *cs, const char*ct)
{
    while (*cs && *ct)
        if(*cs == ' ' || *cs == ',' || *cs == '[' || *cs == ']' )

}

char *copy_strs(str *old_strs[i], const char i)
{
    str new_strs[i*2];

    for (int k = 0; k < i; k++)
        new_strs =
} 

struct LINE *one_string_to_lot( char *ptr_to_str)
{
    while (*ptr_to_str)
    {
        if (*ptr_to_str == '\n')
        {
            struct 
        }
        else
        {}
    }
    return 
}*/

int count_lines (char *ptr)
{
    int count = 0;
    
    char *p = ptr;

    while(*p)
    {
        if (*p == '\n')
        {
            count++; 
        }
        p++;
    }
    
    count++;
    p = ptr;
    printf("||||||||||||||\n%s\n||||||||||||||\n", p);
    return count;
}

struct LINE *make_array(const int count, char *ptr)
{
    //printf("OK1\n");
    struct LINE *lines = (struct LINE*) calloc(count, sizeof(struct LINE));
    char *temp = NULL;
    int counter = 0;
    //printf("OK2\n");
    temp = ptr;
    //printf("OK3\n");
    for (int i = 0; i < count; i++)
    {
        counter = 0;
        //printf("OK11\n");
        lines[i].ptr = temp;
        //printf("OK12\n");
        while((*temp != '\n') && (*temp != '\0'))
        {
            counter++;
            
            temp++;
        }
        
        //printf("OK13\n");
        lines[i].size = counter;
        temp++;

        
    }
    //printf("OK4\n");
    return lines;
}