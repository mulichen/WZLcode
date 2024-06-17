#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Han 3
#define Lie 3
//³õÊ¼»¯ÆåÅÌ
#define void QiPan(char board[Han][Lie],int han,int lie);
//´òÓ¡ÆåÅÌ
void D_QiPan(char board[Han][Lie], int han, int lie);
int playermove(char board[Han][Lie], int han, int lie);
int computermove(char board[Han][Lie], int han, int lie);
int Win(char board[Han][Lie], int han, int lie);
int IsFull(char board[Han][Lie], int han, int lie);
