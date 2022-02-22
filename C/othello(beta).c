#include <stdio.h>

int legal(int, int, char, char[][8]);
int possible(char, char[][8]);
int end(char[][8]);

int main()
{
	int i;
	int j;
	int k;
	int x;
	int y;

	char turn = 'B';
	char board[8][8];
	//board[x][y]
	for(j = 0; j < 8; j++)
	{
		for(i = 0; i < 8; i++)
		{
			board[i][j] = '-';
		}
	}

	board[3][3] = 'W';
	board[4][4] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';

	printf(" ");
	for(i = 1; i < 9; i++)
	printf(" %d",i);

	puts("");

	for(i = 0; i < 8; i++)
	{
		printf("%d ",i+1);

		for(j = 0; j < 8; j++)
		{
			printf("%c ",board[j][i]);
		}

		printf("%d ",i+1);

		puts("");
	}

	printf(" ");
	for(i = 1; i < 9; i++)
	printf(" %d",i);

	puts("");

	while(end(board))
	{
		printf("\n%c\n",turn);

		do
		{
			printf("x: ");
			scanf("%d",&x);

			printf("y: ");
			scanf("%d",&y);
		}
		while(x<1 || x>8 || y<1 || y>8 || board[x-1][y-1] != '+' || legal(x,y,turn,board) == 0);

		//up
		for(j = y - 2; j >= 0; j--)
		{
			if((board[x-1][j] == '+') || (board[x-1][y-2] == turn))
			break;

			if(board[x-1][j] == turn)
			{
				for(i = y-1; i > j; i--)
				{
					board[x-1][i] = turn;
				}
			}
		}

		//up and right
		i = x;
		for(j = y-2; j >= 0; j--)
		{
			if((board[i][j] == '+') || (board[x][y-2] == turn))
			break;

			if(board[i][j] == turn)
			{
				i = x-1;
				for(k = y-1; k > j; k--)
				{
					board[i][k] = turn;
					i++;
				}
			}

			i++;

			if( i == 8)
			break;
		}

		//right
		for(i = x; i < 8; i++)
		{
			if((board[i][y-1] == '+') || (board[x][y-1] == turn))
			break;

			if(board[i][y-1] == turn)
			{
				for(k = x-1; k < i; k++)
				{
					board[k][y-1] = turn;
				}
			}
		}

		//right and down
		i = x;
		for(j = y; j < 8; j++)
		{
			if((board[i][j] == '+') || (board[x][y] == turn))
			break;

			if(board[i][j] == turn)
			{
				i = x-1;
				for(k = y-1; k < j; k++)
				{
					board[i][k] = turn;
					i++;
				}
			}

			i++;

			if(i == 8)
			break;
		}

		//down
		for(j = y; j < 8; j++)
		{
			if((board[x-1][j] == '+') || (board[x-1][y] == turn))
			break;

			if(board[x-1][j] == turn)
			{
				for(k = y-1; k < j; k++)
				{
					board[x-1][k] = turn;
				}
			}
		}

		//down and left
		i = x - 2;
		for(j = y; j < 8; j++)
		{
			if((board[i][j] == '+') || (board[x-2][y] == turn))
			break;

			if(board[i][j] == turn)
			{
				i = x-1;
				for(k = y-1; k < j; k++)
				{
					board[i][k] = turn;
					i--;
				}
			}

			i--;

			if(i == 0)
			break;
		}

		//left
		for(i = x-2; i >= 0; i--)
		{
			if((board[i][y-1] == '+') || (board[x-2][y-1] == turn))
			break;

			if(board[i][y-1] == turn)
			{
				for(k = x-1; k > i; k--)
				{
					board[k][y-1] = turn;
				}
			}
		}

		//left and up
		i = x - 2;
		for(j = y-2; j >= 0; j--)
		{
			if((board[i][j] == '+') || (board[x-2][y-2] == turn))
			break;

			if(board[i][j] == turn)
			{
				i = x-1;
				for(k = y-1; k > j; k--)
				{
					board[i][k] = turn;
					i--;
				}
			}

			i--;

			if(i == 0)
			break;
		}

		puts("");
		printf(" ");

		for(i = 1; i < 9; i++)
		printf(" %d",i);

		puts("");

		for(i = 0; i < 8; i++)
		{
			printf("%d ",i+1);

			for(j = 0; j < 8; j++)
			{
				printf("%c ",board[j][i]);
			}

			printf("%d ",i+1);

			puts("");
		}

		printf(" ");

		for(i = 1; i < 9; i++)
		printf(" %d",i);

		puts("");

		if(turn == 'B')
		turn = 'W';

		else
		turn = 'B';

		if(possible(turn, board) == 0)
		{
			if(turn == 'B')
			turn = 'W';

			else
			turn = 'B';
		}
	}

	return 0;
}

int legal(int x, int y, char turn, char board[][8])
{
	int i;
	int j;
	int checker = 0;

	//up
	for(j = y - 2; j >= 0; j--)
	{
		if((board[x-1][j] == '+') || (board[x-1][y-2] == turn))
		break;

		if(board[x-1][j] == turn)
		{
			checker++;
		}
	}

	//up and right
	i = x;
	for(j = y-2; j >= 0; j--)
	{
		if((board[i][j] == '+') || (board[x][y-2] == turn))
		break;

		if(board[i][j] == turn)
		{
			checker++;
		}

		i++;

		if( i == 8)
		break;
	}

	//right
	for(i = x; i < 8; i++)
	{
		if((board[i][y-1] == '+') || (board[x][y-1] == turn))
		break;

		if(board[i][y-1] == turn)
		{
			checker++;
		}
	}

	//right and down
	i = x;
	for(j = y; j < 8; j++)
	{
		if((board[i][j] == '+') || (board[x][y] == turn))
		break;

		if(board[i][j] == turn)
		{
			checker++;
		}

		i++;

		if(i == 8)
		break;
	}

	//down
	for(j = y; j < 8; j++)
	{
		if((board[x-1][j] == '+') || (board[x-1][y] == turn))
		break;

		if(board[x-1][j] == turn)
		{
			checker++;
		}
	}

	//down and left
	i = x - 2;
	for(j = y; j < 8; j++)
	{
		if((board[i][j] == '+') || (board[x-2][y] == turn))
		break;

		if(board[i][j] == turn)
		{
			checker++;
		}

		i--;

		if(i == 0)
		break;
	}

	//left
	for(i = x-2; i >= 0; i--)
	{
		if((board[i][y-1] == '+') || (board[x-2][y-1] == turn))
		break;

		if(board[i][y-1] == turn)
		{
			checker++;
		}
	}

	//left and up
	i = x - 2;
	for(j = y-2; j >= 0; j--)
	{
		if((board[i][j] == '+') || (board[x-2][y-2] == turn))
		break;

		if(board[i][j] == turn)
		{
			checker++;
		}

		i--;

		if(i == 0)
		break;
	}

	return checker;
}

int possible(char turn, char board[][8])
{
	int i;
	int j;

	for(j = 0; j < 8; j++)
	{
		for(i = 0; i < 8; i++)
		{
			if(legal(i, j, turn, board) != 0)
			return 1;
		}
	}

	return 0;
}

int end(char board[][8])
{
	if(possible('B', board) == 1)
	return 1;

	if(possible('W', board) == 1)
	return 1;

	return 0;
}