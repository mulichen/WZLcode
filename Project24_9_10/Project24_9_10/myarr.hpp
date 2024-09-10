#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class myarr
{
public:
	myarr(int cc)
	{
		this->m_cc = cc;
		this->m_size = 0;
		this->paddress = new T[this->m_cc];
	}
	~myarr()
	{
		if (this->paddress != nullptr)
		{
			delete[] this->paddress;
			this->paddress = nullptr;
		}
	}
	myarr(const myarr& arr)
	{
		this->m_cc = arr.m_cc;
		this->m_size = arr.m_size;
		if(this->paddress != nullptr)
		{
			delete[] this->paddress;
		}
		this->paddress = new T[this->m_cc];
		for (int a = 0; a < this->m_size; a++)
		{
			this->paddress[a] = arr.paddress[a];
		}
	}
	myarr& operator=(const myarr arr)
	{
		this->m_cc = arr.m_cc;
		this->m_size = arr.m_size;
		if(this->paddress != nullptr)
		{
			delete[] this->paddress;
		}
		this->paddress = new T[this->m_cc];
		for (int a = 0; a < this->m_size; a++)
		{
			this->paddress[a] = arr.paddress[a];
		}
		return *this;
	}
	void tailadd(T A)
	{
		if (this->m_cc == this->m_size)
		{
			cout << "ÒÑÂú" << endl;
			return;
		}
		this->paddress[this->m_size] = A;
		this->m_size++;
	}
	void tatldel()
	{
		if (this->m_size == 0)
		{
			cout << "ÎÞÔªËØ" << endl;
		}
		this->m_size--;
	}
	T& operator[](int num)
	{
		return this->paddress[num];
	}
	int Rsize()
	{
		return this->m_size;
	}
	int Rcc()
	{
		return this->m_cc;
	}
private:
	T* paddress;
	int m_size;
	int m_cc;
};
