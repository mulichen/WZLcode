#define  _CRT_SECURE_NO_WARNINGS
int add()
{
	return 0;
}
int main()
{
	int (*pf)(int, int) = add;
	int (*arr[4])(int, int) = {add};//����ָ�����飬����ĺ�������ֵ�Ͳ�������Ҫ��ͬ
	//Ӧ��:�ص�����
	//ָ����ָ�������ָ��
	int(*(*ppf)[4])(int, int) = &arr;
}
//������ 
// sizeof
int main()
{
	char arr[] = {'a','b','c','d','e','f'};
	printf("%d\n", sizeof(arr));//6
	//sizeof(������)
	printf("%d\n",sizeof(arr + 0));//4/8
	//arr + @ ��������Ԫ�صĵ�ַ
	printf("%d n",sizeof(*arr));//1
	//*arr�����������Ԫ�أ���С��1�ֽ�
	//*arr --> arr[@]
	//*(arr+0) --> arr[@]
	printf("%d\n",sizeof(arr[1]));//1
	printf("%dn",sizeof(&arr));//4/8
	//&arr������ĵ�ַ���ǵ�ַ����4/8���ֽ�
	printf("%d\n",sizeof(&arr + 1));//4/8
	//&arr + 1�������ĵ�ַ1
	printf("%dn",sizeof(&arr[0] + 1));//4/8
	//&arr[e] + 1�ǵڶ���Ԫ�صĵ�ַ
	printf("%dn", sizeof(arr[0] + 1));//4
	//arr[0]��'a',+1��1�����λᷢ�������������ʻ����һ�����εĴ�С
	return 0;
	}
//strlen �����ַ����ĳ�������\0ֹͣ,����\0֮ǰ���ַ�����
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%dn",strlen(arr));//���ֵ
	printf("%d\n",strlen(arr + 0));//���ֵ
	printf("%d\n",strlen(*arr));//--> strlen('a');-->strlen(97);//Ұָ��
	printf("%d\n",strlen(arr[1]));//-->strlen("b')-->strlen(98);
	printf("%d n",strlen(&arr));//���ֵ
	printf("%d\n",strlen(&arr +1));//���ֵ-6
	printf("%d\n",strlen(&arr[0] + 1));//���ֵ-1
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
	printf("%d\n",strlen(*p));//Ұָ��
	printf("%d n",strlen(p[0]));//Ұָ��
	printf("%d\n",strlen(&p));//���
	printf("%d\n",strlen(&p + 1));//��Ϊ+1���ܰ�\0���������������
	printf("%d\n",strlen(&p[0] + 1));//5
	return 0;
}
