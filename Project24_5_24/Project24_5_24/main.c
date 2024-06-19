#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<assert.h>
//void nixu(char*p,char*y)
//{
//	while (p<y)
//	{
//		char x = *p;
//		*p = *y;
//		*y = x;
//		p++;
//		y--;
//	}
//}
int main()
{/*
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b = 0;
	for (b = 0;  b<=10; b++)
	{
		a[b] = 0;
		printf("%s\n","hehe");
	} */
	//int i = 0;
	//int j = 0;
	//int n = 0;
	//scanf("%d %d",&i,&j);
	//int m = i;
	//int x = i;
	//if (j > 1)
	//{
	//	for (n = 1; n < j; n++)
	//	{
	//		i = i * 10 + x;
	//		m += i;
	//	}
	//}
	//¿ÕÆ¿×Ó»»Ë®
	/*int money = 0;
	scanf("%d",&money);
	int e = money;
	int k = money;
	while (k>=2)
	{
		e = e + k/2;
		k = k / 2 + k % 2;
	}
	printf("%d\n",e);*/
	/*char e[100] = {0};
	gets(e);
	int n = strlen(e);
	nixu(e,e+n-1);
	char* left = e;
	char* right = e;
	while (*e != '\0')
	{
		while (*right != ' '&& *right != '\0')
		{
			right++;
		}
		if (*right != '\0')
			break;
		nixu(left, right - 1);
		left = ++right;
		right = left;
	}
	printf("%s\n",e);*/
	int n = 0;
	int m = 0;
	scanf("%d",&n);
	scanf("%d",&m);
	int arr[1000] = { 0 };
	int arr1[1000] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &arr1[i]);
	}
	int k = 0;
	int j = 0;
	while (k < n && j < m)
	{
		if (arr[k] < arr1[j])
		{
			printf("%d ",arr[k]);
			k++;
		}
		else
		{
			printf("%d ",arr1[j]);
			j++;
		}
	}
	if (k == n)
	{
		for (j; j < m; j++)
		{
			printf("%d ", arr1[j]);
		}
	}
	else
		for (k; k < n; k++)
		{
			printf("%d ", arr[k]);
		}
	return 0;
}