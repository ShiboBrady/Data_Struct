#include <stdio.h>
#include <stdlib.h>

int strLen(const char* str);
char* strCpy(char* dest, const char* src);
char* strNCpy(char* dest, const char* src, size_t length);

int main(int argc, const char *argv[])
{
    char str[100] = "Hello"; 
    printf("%d\n", strLen(str));
    char str1[100];
    //strCpy(str1, str);
    strNCpy(str1, str, 3);
    puts(str1);
    return 0;
}

int strLen(const char* str)
{
    if (NULL == str)
    {
        return 0;
    }

    const char* strEnd = str;
    while ('\0' != *strEnd)
    {
        ++strEnd;
    }
    
    return strEnd - str;
}

void* my_memcopy(void* dest, const void* src, size_t length)
{
    if (NULL == dest || NULL == src)
    {
        return dest;
    }

    char* str_dest = (char*)dest;
    const char* str_src = (const char*)src;
    void* original = dest;

    if (str_src <= str_dest && str_dest <= str_src + length - 1)
    {
        str_dest += (length - 1); 
        str_src += (length - 1);
        while (length--)
        {
            *str_dest-- = *str_src--;
        }
    }
    else
    {
        while (length--) 
        {
            *str_dest++ = *str_src++;
        }
    }
}

char* strCpy(char* dest, const char* src)
{
    if (NULL == dest || NULL == src)
    {
        return dest;
    }

    char* original = dest;

    //while ('\0' != (*dest++ = *src++));
    my_memcopy(dest, src, strLen(src) + 1);

    return original;
}

char* strNCpy(char* dest, const char* src, size_t length)
{
    if (NULL == dest || NULL == src)    
    {
        return dest;
    }

    char* original = dest;

    my_memcopy(dest, src, length);

    return original;
}
