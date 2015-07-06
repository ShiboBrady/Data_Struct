#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* pBegin, char* pEnd)
{
	if (pBegin != NULL && pEnd != NULL)
	{
		char temp;
		while (pBegin < pEnd)
		{
			temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
			++pBegin;
			--pEnd;
		}
	}
}

void reverseEachWord(char* str)
{
	if (str != NULL)
	{
		char* pBegin = str;
		char* pEnd = str + strlen(str) - 1;

		reverse(pBegin, pEnd);

		while (*str != '\0')
		{
			if (*str == ' ')
			{
				++str;
				continue;
			}
			pBegin = str;
			pEnd = pBegin;
			while (*pEnd != ' ' && *pEnd != '\0')
			{
				pEnd++;
			}
			reverse(pBegin, --pEnd);
			str = ++pEnd;
		}
	}
}

int main(int argc, char* argv[])
{
	char str[] = "I am a student.";
	reverseEachWord(str);
	puts(str);
	return 0;
}