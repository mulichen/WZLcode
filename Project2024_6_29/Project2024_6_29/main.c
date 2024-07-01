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
//笔试题 
// sizeof
int main()
{
	char arr[] = {'a','b','c','d','e','f'};
	printf("%d\n", sizeof(arr));//6
	//sizeof(数组名)
	printf("%d\n",sizeof(arr + 0));//4/8
	//arr + @ 是数组首元素的地址
	printf("%d n",sizeof(*arr));//1
	//*arr就是数组的首元素，大小是1字节
	//*arr --> arr[@]
	//*(arr+0) --> arr[@]
	printf("%d\n",sizeof(arr[1]));//1
	printf("%dn",sizeof(&arr));//4/8
	//&arr是数组的地址，是地址就是4/8个字节
	printf("%d\n",sizeof(&arr + 1));//4/8
	//&arr + 1是数组后的地址1
	printf("%dn",sizeof(&arr[0] + 1));//4/8
	//&arr[e] + 1是第二个元素的地址
	printf("%dn", sizeof(arr[0] + 1));//4
	//arr[0]是'a',+1，1是整形会发生整形提升，故会计算一个整形的大小
	return 0;
	}
//strlen 计算字符串的长度遇到\0停止,计算\0之前的字符个数
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%dn",strlen(arr));//随机值
	printf("%d\n",strlen(arr + 0));//随机值
	printf("%d\n",strlen(*arr));//--> strlen('a');-->strlen(97);//野指针
	printf("%d\n",strlen(arr[1]));//-->strlen("b')-->strlen(98);
	printf("%d n",strlen(&arr));//随机值
	printf("%d\n",strlen(&arr +1));//随机值-6
	printf("%d\n",strlen(&arr[0] + 1));//随机值-1
	return 0;
}
int main()
{
	char* p = "abcdef";
	printf("%d\n",sizeof(p));//4/8
	printf("%d n",sizeof(p + 1));//4/8
	printf("%d\n",sizeof(*p));//1
	printf("%d\n",sizeof(p[0]));//1
	printf("%d\n",sizeof(&p));//4/8
	printf("%d\n",sizeof(&p + 1));//4/8
	printf("%d\n",sizeof(&p[0] + 1));//4/8

	printf("%d\n",strlen(p));//6
	strlen("%d\n",strlen(p + 1));//5
	printf("%d\n",strlen(*p));//野指针
	printf("%d n",strlen(p[0]));//野指针
	printf("%d\n",strlen(&p));//随机
	printf("%d\n",strlen(&p + 1));//因为+1可能把\0跳过，所以是随机
	printf("%d\n",strlen(&p[0] + 1));//5
	return 0;
}
