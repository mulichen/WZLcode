#define  _CRT_SECURE_NO_WARNINGS
int add()
{
	return 0;
}
int main()
{
	int (*pf)(int, int) = add;
	int (*arr[4])(int, int) = {add};//函数指针数组，数组的函数返回值和参数类型要相同
	//应用:回调函数
	//指向函数指针数组的指针
	int(*(*ppf)[4])(int, int) = &arr;
}