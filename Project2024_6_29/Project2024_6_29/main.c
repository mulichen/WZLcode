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