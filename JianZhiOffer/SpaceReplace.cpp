#include <stdio.h>
#include <string.h>

void SpaceReplace(char* str)
{
	if (NULL == str)
	{
		return;
	}

	//ͳ�ƿո�����
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

	//�ƶ������λ��
	int iOldLength = strlen(str);
	int iNewLength = iOldLength + iSpaceNum * 2;
	char* pNewEnd = str + iNewLength;
	char* pOldEnd = str + iOldLength;

	//��ʼ�ƶ����滻
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