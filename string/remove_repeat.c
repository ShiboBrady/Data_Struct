#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_repeat(char* str);

int main(int argc, const char *argv[])
{
    char str[100] = "abcacdeekbj";
    remove_repeat(str);
    puts(str);
    return 0;
}

char* remove_repeat(char* str)
{
    int len = strlen(str);
    int i, j, tail = 1;

    for (i = 1; i < len; ++i)
    {
        /*从头到tail位置扫描*/
        for (j = 0; j < tail; ++j)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        
        /*str[i]的字符没有出现过*/
        if (tail == j)
        {
            str[tail++] = str[i];
        }
    }
    str[tail] = '\0';
    return str;
}
