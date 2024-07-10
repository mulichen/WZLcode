#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_memmove(const void* st,const void* st1, char num)
{
	assert(st && st1);
	char* str1 = st;
	while (num--)
	{
		if (st < st1)
		{
			*(char*)st = *(char*)st1;
			st = (char*)st + 1;
			st1 = (char*)st1 + 1;
		}
		else if(st>st1)
		{
			*((char*)st + num) = *((char*)st1 + num);
		}
	}
	return str1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
	my_memmove(arr,arr+2,20);
	for (int i = 0 ; i < 9 ; i++)
	{
		printf("%d", arr[i]);
	}
	//int arr1[] = {};
	return 0;
}