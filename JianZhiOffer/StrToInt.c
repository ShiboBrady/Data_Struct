#include <stdio.h>
#include <stdlib.h>

int StrToIntCore(char* str, int minus);

static const int True = 1;
static const int False = 0;

enum Status {Valid = 0, Invalid};//0��ʾ��Ч��1��ʾ��Ч
int g_invalid = Valid;//������ʶת�����ֵ�Ƿ���Ч��ȫ�ֱ���

int strToInt(char* str)
{
	g_invalid = Invalid;
	
	int num = 0;

	if (str != NULL && *str != '\0')
	{
		int minus = False;//��ʾ�ַ���ǰ���Ƿ��и���
		if (*str == '-')
		{
			minus = True;
			++str;
		}
		else if (*str == '+')
		{
			++str;
		}

		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}

	return num;
}

int StrToIntCore(char* str, int minus)
{
	long long sum = 0;
	int Flag = minus ? -1 : 1;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			sum = sum * 10 + Flag * (*str - '0');
			if ((!minus && sum > 0x7FFFFFFF) || (minus && sum < (signed int)0x80000000))//Խ����
			{
				sum = 0;
				break;
			}
		}
		else
		{
			sum = 0;
			break;
		}
		++str;
	}

	if (*str == '\0')//ת���ɹ�
	{
		g_invalid = Valid;
	}

	return (int)sum;
}

int main(int argc, char* argv[])
{
	char* str = "4294967295";
	int value = strToInt(str);
	printf("%d\n", value);
	printf("%d\n", g_invalid);
	return 0;
}
