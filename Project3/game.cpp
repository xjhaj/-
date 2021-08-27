#define ROW 3
#define COL 3
#include "game.h"
#include<stdio.h>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Iniboard(int board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col;j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(int board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row;i++) {
		int j = 0;
		for (j = 0; j < col;j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
			//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if (i < row - 1) {
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1) {
					printf("|");
				}

			}
				//printf("---|---|---\n");
		}
		printf("\n");

	}

}
void PlayerMove(int board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	printf("������Ҫ�µ�����\n");
	while (1)
	{
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (board[x-1][y-1]==' ')
			{
				board[x - 1][y - 1] = '*';
				break;

			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������:\n");
		}

	}
	
}
void ComputerMove(int board[ROW][COL], int row, int col) 
{
	int x = 0;
	int y = 0;
	printf("������>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] ='#';
			break;

		}
	}
}
int IsFull(int board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for (j=0;j<col;j++) 
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}
char InWin(int board[ROW][COL], int row, int col) 
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0]== board[i][1]&& board[i][1]==board[i][2]&& board[i][0]!=' ')
		{
			return board[i][0];
		}

	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]&& board[0][i] != ' ')
		{
			return board[0][i];
		}

	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];

	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][0] != ' ')
	{
		return board[1][1];

	}
	if (1==IsFull(board,ROW,COL))
	{
		return 'P';
	}
	return 'C';
	
}