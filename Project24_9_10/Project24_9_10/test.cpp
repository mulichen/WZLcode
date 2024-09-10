#define  _CRT_SECURE_NO_WARNINGS
#include"myarr.hpp"
class person
{public:
	person() {};
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void test02()
{
	myarr<person>arr(4);
	person p1("�����", 1000);
	person p2("��˽�", 200);
	person p3("ɳ��", 200);
	person p4("��ɮ", 20);
	arr.tailadd(p1);
	arr.tailadd(p2);
	arr.tailadd(p3);
	arr.tailadd(p4);
	for (int a = 0; a < 4; a++)
	{
		cout << arr[a].m_name <<arr[a].m_age<<endl;
	}
	cout << "��С:" << arr.Rsize() << endl;
	cout << "����:" << arr.Rcc() << endl;
}
void test01()
{
	myarr<int>arr(5);
	for (int a = 1; a <= 5; a++)
	{
		arr.tailadd(a);
	}
	for (int a = 0; a < 5; a++)
	{
		cout << arr[a] << " ";
	}
	cout << endl;
	cout << "��С:" << arr.Rsize() << endl;
	cout << "����:" << arr.Rcc() << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}