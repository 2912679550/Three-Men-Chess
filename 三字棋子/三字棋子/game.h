#define ROW 3
#define COL 3
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void IntBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row,int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void computerMove( char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row, int col);