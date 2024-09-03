#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std; 
#include<string>
class AbstractCaluclator
{
public:
	//AbstractCaluclator(int a,int b)
	//{
	//	m_num1=a;
	//	m_num2=b;
	//}
	//~AbstractCaluclator()
	//{
	//	if (this != nullptr)
	//	{
	//		delete this;
	//	}
	//}
	virtual int getresult() = 0;
	int m_num1;
	int m_num2;
};
class addCalucator :public AbstractCaluclator
{
public:
	virtual int getresult()
	{
		return m_num1+m_num2;
	}
};
class SubCalucator :public AbstractCaluclator
{
public:
	virtual int getresult()
	{
		return m_num1 - m_num2;
	}
};
class MulCalucator :public AbstractCaluclator
{
public:
	virtual int getresult()
	{
		return m_num1 * m_num2;
	}
};
//int test()
//{
//
//}
int main()
{
	AbstractCaluclator* a= new addCalucator;
	AbstractCaluclator* b = new SubCalucator;
	AbstractCaluclator* c = new MulCalucator;

	a->m_num1 = b->m_num1= c->m_num1=10;
	a->m_num2 = b->m_num2 = c->m_num2 = 10;
	cout<< a->m_num1 << "+" << a->m_num2 << "=" << a->getresult() <<endl;
	cout << b->m_num1 << "-" << b->m_num2 << "=" << b->getresult() << endl;
	cout << c->m_num1 << "*" << c->m_num2 << "=" << c->getresult() << endl;
	delete a, b, c;
	return 0;
}