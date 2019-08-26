/*KPM算法*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void get_next(char *T, int *next);	//获得数组值
int KMP(char *S, char *T);			//KMP算法

int main(){

	char *T = "abababca";
	char *S = "ca";

	int n = KMP(T, S);
	printf("%d\n",n);

	return 0;
}

void get_next(char *T, int *next){
	int Tlen = strlen(T);

	int i = 1, j = 0;
	next[0] = 0;
	while(i < Tlen){
		if(T[i] == T[j])
			next[i++] = ++j;
		else
			next[i++] = j = 0;	
	}

	for(i = Tlen - 1; i >0; i--){
		next[i] = next[i-1];
	}
}

int KMP(char *S, char *T){
	int Slen = strlen(S);
	int Tlen = strlen(T);
	int *next = (int *) malloc( Tlen * sizeof(int) );
	get_next(T, next);
	
	int i = 0, j = 0;
	while(j < Tlen && i < Slen){
		if(T[j] == S[i]){
			j++;
			i++;
		}else{
			j = next[j];
			if(T[j] != S[i])
				i++;
		}
	}
	free(next);	//释放堆上分配的内存

	if(j == Tlen)
		return i - Tlen;
	else
		return -1;
}