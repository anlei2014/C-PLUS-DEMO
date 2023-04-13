#include<iostream>


using namespace std;

class Person 
{
	// 非静态成员变量，属于类的对象上
	int m_A;

	// 静态成员变量，不属于类的对象上。而且需要类外初始化
	static int m_B;


	// 成员函数
	void func() {};     // 非静态成员函数，不属于类的对象

	static void func2() {};       //静态成员函数，不属于类的对象
};

// 类外初始化方式
int Person::m_B = 0;

// 空的类对象，大小为1    为了区分这是一个独一无二的的对象
int main()
{

	



}