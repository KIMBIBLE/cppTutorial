#include "trim.h"

char *lTrim(char *string)
{
	int idx = 0;
	while (string)
	{
		if (string[idx] != ' ' && string[idx] != '\t' && string[idx] != '\n')
			return string;
		string++;
	}

	return string;	//default : left whitespace가 없는 경우 원본 문자열 시작 주소 리턴
}

char *rTrim(char *string)
{
	int len = strlen(string) - 1;
	for (int i = len; i >= 0; i--)
		if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
		{
			string[i + 1] = NULL;
			return string;
		}

	return string;	//default : right whitespace가 없는 경우 원본 문자열 시작 주소 리턴
}

char *trim(char *string)
{
	return lTrim(rTrim(string));
}