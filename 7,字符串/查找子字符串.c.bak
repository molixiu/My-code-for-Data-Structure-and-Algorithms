/*KPM算法*/
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>

int compare_rString(char *fPcur, char *fEnd,  char *sPcur, char *sEnd)
{
	if( (fEnd - fPcur) < (sEnd - sPcur) )
		return -1;

	for(; sPcur <= sEnd && *sPcur == *fPcur; sPcur++,fPcur++);
	if(sPcur <= sEnd)
		return -1;
	else
		return 1;
}

int find_sonString_position(char *father, char *son)
{
	char *fPcur = father;	
	char *fEnd = father + ( strlen(father) - 1 );
	char *sPcur = son;
	char *sEnd = son + ( strlen(son) -1 );
	int position = -1;

	for(; fPcur<= fEnd; fPcur++)
	{
		if(*fPcur  == *sPcur)
		{
			sPcur = son;
			position = compare_rString(fPcur, fEnd,  sPcur, sEnd);
			if(position != -1)	//找到子字符串了
				return fPcur - father;
		}
	}
	return position;
}

int main()
{
	char *father = "1234abcdefg";
	char *son = "fgaa";
	int position = find_sonString_position(father, son);
	printf("%d\n", position);
}