#include<stdio.h>
#include<time.h>

#define X 8
#define Y 8

int chess[X][Y];	//定义一个X*Y的棋盘

void printChess(int chess[X][Y])
{
	for(int i = 0; i < X; i++)
	{
		for(int j = 0; j < Y; j++)
		{
			printf("%d\t", chess[i][j]);
		}
		putchar('\n');
		putchar('\n');
	}
		putchar('\n');
		putchar('\n');
}

//找下一个马要踏的格子的规则
int next_XY(int *next_x, int *next_y, int count)
{
	switch(count)
	{
		case 0:
			if( *next_x+2<=X-1 && *next_y-1>=0 && chess[*next_x+2][*next_y-1]==0 )
			{
				*next_x = *next_x + 2;
				*next_y = *next_y - 1;
				return 1;
			}
			break;

		case 1:
			if( *next_x+2<=X-1 && *next_y+1<=Y-1 && chess[*next_x+2][*next_y+1]==0 )
			{
				*next_x = *next_x + 2;
				*next_y = *next_y + 1;
				return 1;
			}
			break;

		case 2:
			if( *next_x+1<=X-1 && *next_y-2>=0 && chess[*next_x+1][*next_y-2]==0 )
			{
				*next_x = *next_x + 1;
				*next_y = *next_y - 2;
				return 1;
			}
			break;

		case 3:
			if( *next_x+1<=X-1 && *next_y+2<=Y-1 && chess[*next_x+1][*next_y+2]==0 )
			{
				*next_x = *next_x + 1;
				*next_y = *next_y + 2;
				return 1;
			}
			break;

		case 4:
			if( *next_x-2>=0 && *next_y-1>=0 && chess[*next_x-2][*next_y-1]==0 )
			{
				*next_x = *next_x - 2;
				*next_y = *next_y - 1;
				return 1;
			}
			break;

		case 5:
			if( *next_x-2>=0 && *next_y+1<=Y-1 && chess[*next_x-2][*next_y+1]==0 )
			{
				*next_x = *next_x - 2;
				*next_y = *next_y + 1;
				return 1;
			}
			break;

		case 6:
			if( *next_x-1>=0 && *next_y-2>=0 && chess[*next_x-1][*next_y-2]==0 )
			{
				*next_x = *next_x - 1;
				*next_y = *next_y - 2;
				return 1;
			}
			break;

		case 7:
			if( *next_x-1>=0 && *next_y+2<=Y-1 && chess[*next_x-1][*next_y+2]==0 )
			{
				*next_x = *next_x - 1;
				*next_y = *next_y + 2;
				return 1;
			}
			break;

		default:
			break;
	}

	return 0;
}

//tag为马走过的步数 当tag为X*Y的时候说明马踏完棋盘
int travelChessBoard(int x, int y, int tag)
{
	tag++;
	chess[x][y] = tag;
	if(tag == X*Y)	//说明马踏完最后一个格子
	{ 
		printChess(chess);
		return 1;
		
	}

	
	int next_x = x, next_y = y, flag = 0,count = 0;
	
	for(; !(flag =next_XY(&next_x,&next_y, count)) && count < 8; count++);

	while(flag)
	{
		if(travelChessBoard(next_x, next_y, tag))
			return 1;

		next_x = x;
		next_y = y;
		for(count++; !(flag =next_XY(&next_x,&next_y, count)) && count < 8; count++);

	}
	if(!flag)
	{
		chess[x][y] = 0;
	}

	return 0;

}


int main()
{
	clock_t start, finish;
	
	start = clock();

	travelChessBoard(0,0,0);


	printChess(chess);

	finish = clock();
	
	printf("一共用时:%f\n", (double)(finish-start)/CLOCKS_PER_SEC);

	return 0;
}