#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringReverse(char *str)
{
	char *start = str;
	char *end = start + (strlen(str) -1);
	char temp;

	while(start !=  end)
	{
		temp = *start;
		*(start++) = *end;
		*(end--) = temp;
	}
}

int main()
{
	char *str = (char *)malloc(5);
	strcpy(str, "abcde");
	printf("%s\n", str);
	stringReverse(str);
	printf("%s\n", str);
}