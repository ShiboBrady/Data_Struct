#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char* s)
{
    int i = 0, j = 0;
    /*删除开头的空白符*/
    while (s[j] == 32)
    {
        ++j;
    }

    /*删除后面的空白符*/
    int len = strlen(s);
    while (s[len - 1] == 32)
    {
        --len;
    }

    s[len] = '\0';

    while (s[j] != '\0')
    {
        while (s[j] == 32)
        {
            ++j;
        }
        /*将中间连续的空白符变为一个，判断i!=0是为了防止将头部的连续字符变为1个*/
        if (s[j - 1] == 32 && s[j - 2] == 32 && i != 0)
        {
            s[i++] = 32;
        }
        s[i++] = s[j++];
    }

    s[i] = '\0';
}

int main(int argc, const char *argv[])
{
    char str[100] = "   a   bc      defg  h  n   ";
    puts(str);
    fun(str);
    puts(str);
    return 0;
}
