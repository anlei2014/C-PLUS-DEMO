#include <iostream>

using namespace std;


class Person
{
public:
	Person()
	{
		cout << "Person构造函数" << endl;
	 };


	Person(const Person &p)
	{
		m_Age = p.m_Age;
		m_Height = p.m_Height;
		cout << "Person拷贝构造函数" << endl;
		m_Height = new int(*p.m_Height);
	};



	~Person()
	{
		cout << "Person析构函数" << endl;
	};

	int m_Age;
	int* m_Height;

};

void test01()
{
	Person p1;
	Person p2(p1);
};

int main()
{
	test01();

	system("pause");
	return 0;
}