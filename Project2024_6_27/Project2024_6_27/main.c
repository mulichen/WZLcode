#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int test(const int* str)
{
	return 0;
}
//int main()
//{
//	int(*pf)(const int*) = test;//(*pf)括号得有，不然pf会和参数类型先结合
//	//解引用可以用*pf也可以把*不写
//	//因为pf和test此时存的都是test函数的地址 即：
//	//test(1);
//	//pf(1);
//	return 0;
//
//}
//int main()
//{
//	//理解
//	( *( void (*)() )0 )();//《C陷阱和缺陷》
//	//以上代码是一次函数调用，调用的是0作为地址处的函数。
//	// 1.把0强制类型转换为: 无参，返回类型是void的函数的地址
//	// 2.调用0地址处的这个函数
//	return 0;
//}