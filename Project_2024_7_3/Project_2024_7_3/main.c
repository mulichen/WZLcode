#define  _CRT_SECURE_NO_WARNINGS
struct Test
{
	int Num;
char* pcName;
short sDate; char cha[2]; short sBa[4];
}*p = (struct Test*)0x100000;
//����p ��ֵΪ0x10000�����±���ʽ��ֵ�ֱ�Ϊ����?
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
//x86 
int main()
{
	printf("%p\n", p + 0x1);//0x1-->1,%p-->��ӡָ��
	//0x100000+20-->0x100014
	printf("%pn",(unsigned long)p + 0x1);
	//1,048,576+1 --> 1,048,577
	// 0x100001
	// ������ǿ���޷��ų�����
	printf("%p\n",(unsigned int*)p + 0x1);
	//0x100000+4-->0x100004
	//����������ָ��
	return 0;
}
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], * ptr2);//�˴��漰��С�˴洢
	//a-->01000000020000000300000004000000
	//��ת�������Σ���һ���Ǽ�һ���ֽڣ�ת������ָ��󣬼�ָ��ڶ����ֽڣ�
	// �����þ���02000000����ӡ��16���ƾ���2000000����ӡ���:4��2000000
	return 0;
}