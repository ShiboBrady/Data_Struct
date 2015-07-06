#include <stdio.h>
#include <string.h>

void SpaceReplace(char* str)
{
	if (NULL == str)
	{
		return;
	}

	//统计空格数量
	int iSpaceNum = 0;
	char* p = str;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			++iSpaceNum;
		}
		++p;
	}

	//移动到最后位置
	int iOldLength = strlen(str);
	int iNewLength = iOldLength + iSpaceNum * 2;
	char* pNewEnd = str + iNewLength;
	char* pOldEnd = str + iOldLength;

	//开始移动和替换
	while (iNewLength)
	{
		if (*pOldEnd == ' ')
		{
			*pNewEnd-- = '0';
			*pNewEnd-- = '2';
			*pNewEnd-- = '%';
			--pOldEnd;
			iNewLength -= 3;
		}
		else
		{
			*pNewEnd-- = *pOldEnd--;
			iNewLength--;
		}
	}

}

int main()
{
	char str[1024] = "I am a student.";
	SpaceReplace(str);
	puts(str);
	return 0;
}