#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Han 3
#define Lie 3
//��ʼ������
#define void QiPan(char board[Han][Lie],int han,int lie);
//��ӡ����
void D_QiPan(char board[Han][Lie], int han, int lie);
int playermove(char board[Han][Lie], int han, int lie);
int computermove(char board[Han][Lie], int han, int lie);
int Win(char board[Han][Lie], int han, int lie);
int IsFull(char board[Han][Lie], int han, int lie);
