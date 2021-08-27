#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdio.h>
#include<cstdlib>
void Iniboard(int board[ROW][COL], int row, int col);
void DisplayBoard(int board[ROW][COL], int row, int col);
void PlayerMove(int board[ROW][COL], int row, int col);
void ComputerMove(int board[ROW][COL], int row, int col);
char InWin(int board[ROW][COL], int row, int col);
