#define  _CRT_SECURE_NO_WARNINGS
struct Test
{
	int Num;
char* pcName;
short sDate; char cha[2]; short sBa[4];
}*p = (struct Test*)0x100000;
//假设p 的值为0x10000。如下表表达式的值分别为多少?
//已知，结构体Test类型的变量大小是20个字节
//x86 
int main()
{
	printf("%p\n", p + 0x1);//0x1-->1,%p-->打印指针
	//0x100000+20-->0x100014
	printf("%pn",(unsigned long)p + 0x1);
	//1,048,576+1 --> 1,048,577
	// 0x100001
	// 这里是强制无符号长整形
	printf("%p\n",(unsigned int*)p + 0x1);
	//0x100000+4-->0x100004
	//这里是整形指针
	return 0;
}
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], * ptr2);//此处涉及大小端存储
	//a-->01000000020000000300000004000000
	//先转换成整形，加一就是加一个字节，转换整形指针后，即指向第二个字节，
	// 解引用就是02000000，打印成16进制就是2000000，打印结果:4，2000000
	return 0;
}