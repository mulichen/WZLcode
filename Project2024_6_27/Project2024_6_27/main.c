#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int test(const int* str)
{
	return 0;
}
//int main()
//{
//	int(*pf)(const int*) = test;//(*pf)���ŵ��У���Ȼpf��Ͳ��������Ƚ��
//	//�����ÿ�����*pfҲ���԰�*��д
//	//��Ϊpf��test��ʱ��Ķ���test�����ĵ�ַ ����
//	//test(1);
//	//pf(1);
//	return 0;
//
//}
//int main()
//{
//	//���
//	( *( void (*)() )0 )();//��C�����ȱ�ݡ�
//	//���ϴ�����һ�κ������ã����õ���0��Ϊ��ַ���ĺ�����
//	// 1.��0ǿ������ת��Ϊ: �޲Σ�����������void�ĺ����ĵ�ַ
//	// 2.����0��ַ�����������
//	return 0;
//}