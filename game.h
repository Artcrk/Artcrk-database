#pragma once

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
#define CHNR_SET 3

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������

void Boardoutput(char chessboard[ROW][COL], int row, int col);//��ӡ����

void Boardinput(char board[ROW][COL], int row, int col);//���������������

void Computerinput(char board[ROW][COL], int row, int col);//��������

char WIN_judge(char board[ROW][COL], int row, int col);//�ж�ϵͳ

void judge_winer(char JDM);