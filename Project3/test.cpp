#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <time.h>
void menu() {
	printf("********************************\n");
	printf("*******1.play  0.exit***********\n");
	printf("********************************\n");
}
void game() {
	char ret = 0;
	int board [ROW][COL] = { 0 };
	Iniboard(board, ROW, COL);
	DisplayBoard(board, ROW,COL);
	while (1) {
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		ret=InWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = InWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret=='*')
	{
		printf("���Ӯ\n");
	}
	else if(ret=='#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);

		switch (input)
		{
		case 1:
			game();
			printf("������\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������\n");
			break;
		}
	} while (input);



}
int main() {
	test();
	return 0;
}