#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define HAN 9
#define LIE 9
#define HANS 11
#define LIES 11
#define NY 10
void G_shu(char board[HANS][LIES],int han,int ,char ch);
void D_shu(char board[HANS][LIES], int han, int lie);
void S_lie(char board[HANS][LIES], int han, int lie);
void P_lie(char mine[HANS][LIES], char show[HANS][LIES],int han,int lie);