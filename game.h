#pragma once

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
#define CHNR_SET 3

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘

void Boardoutput(char chessboard[ROW][COL], int row, int col);//打印棋盘

void Boardinput(char board[ROW][COL], int row, int col);//玩家在棋盘上输入

void Computerinput(char board[ROW][COL], int row, int col);//电脑输入

char WIN_judge(char board[ROW][COL], int row, int col);//判断系统

void judge_winer(char JDM);