#define  _CRT_SECURE_NO_WARNINGS
#include"main.h"
using namespace std;
class animal
{
public:
	virtual void speak()
	{
		cout << "动物在speak" << endl;
	}
};
class dog:public animal
{
	virtual void speak()
	{
		cout << "dogzaispeak" << endl;
	}
};
class cat:public animal 
{
	virtual void speak()
	{
		cout << "cat在speak" << endl;
	}
};
void test01(animal &ani)
{
	ani.speak();
}
int main()
{
	cat cat;
	dog dog;
	test01(cat);
	test01(dog);
	return 0;
}