#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
class CPU
{
public:
	virtual void calcuate() = 0;
};
class Videocard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};
class computer
{
public:
	computer(CPU*cpu,Videocard* videocard, Memory* memory)
	{
		m_cpu=cpu;
		m_Videocard=videocard;
		m_Memory=memory;
	}
	~computer()
	{
		cout << "ִ����������" << endl;
		if (m_cpu != nullptr)
		{
			delete m_cpu;
			m_cpu = nullptr;
		}
		if (m_Videocard = nullptr)
		{
			delete m_Videocard;
			m_Videocard = nullptr;
		}
		if (m_Memory != nullptr)
		{
			delete m_Memory;
			m_Memory = nullptr;
		}
	    
	}
	void work()
	{
		m_cpu->calcuate();
		m_Videocard->display();
		m_Memory->storage();
	}
private:
	CPU* m_cpu;
	Videocard* m_Videocard;
	Memory* m_Memory;
};
class intelcpu :public CPU
{
	virtual void calcuate()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
class intelVideocard :public Videocard
{
	virtual void display()
	{
		cout << "Intel���Կ���ʼ����ʾ" << endl;
	}
};
class intelMemory :public Memory
{
	virtual void storage()
	{
		cout << "Intel���ڴ濪ʼ�洢" << endl;
	}
};
class lenovocpu :public CPU
{
	virtual void calcuate()
	{
		cout << "lenovo��CPU��ʼ����" << endl;
	}
};
class lenovoVideocard :public Videocard
{
	virtual void display()
	{
		cout << "lenovo���Կ���ʼ����ʾ" << endl;
	}
};
class lenovoMemory :public Memory
{
	virtual void storage()
	{
		cout << "lenovo���ڴ濪ʼ�洢" << endl;
	}
};
void test()
{
	cout << "������һ̨����" << endl;
	computer *com1=new computer(new intelcpu,new intelVideocard,new intelMemory);
	com1->work();
	delete com1;
	cout << "------------------" << endl;
	cout << "�����ڶ�̨����" << endl;
	computer* com2 = new computer(new lenovocpu, new lenovoVideocard, new lenovoMemory);
	com2->work();
	delete com2;
	cout << "------------------" << endl;
	cout << "��������̨����" << endl;
	computer* com3 = new computer(new intelcpu, new lenovoVideocard, new intelMemory);
	com3->work();
	delete com3;
}
int main()
{
	test();
	return 0;
}