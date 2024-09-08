#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
void myDY(T arr[], int num)
{
	for (int a = 0; a < num; a++)
	{
		cout << arr[a] <<" ";
	}
	cout << endl;
}
template<class T>
void myJH(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
void myPx(T arr[],int num)
{
	for (int a = 0; a < num - 1; a++)
	{
		bool tem = false;
		for (int b = 0; b < num - a - 1; b++)
		{
			if (arr[b] > arr[b + 1])
			{
				myJH(arr[b], arr[b + 1]);
				tem = true;
			}
		}
		if (!tem)
		{
			break;
		}
	}
}
void test()
{
	int arr[] = { 2,5,3,6,4,1};
	int num=sizeof(arr) / sizeof(int);
	myPx(arr, num);
	myDY(arr, num);
}
void test1()
{
	char arr[] = "dtchsr";
	int num = sizeof(arr) / sizeof(char)-1;
	// »ò int num = strlen(arr);
	myPx(arr, num);
	myDY(arr, num);
}
int main()
{
	test();
	test1();
}
