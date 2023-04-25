#include <iostream>
#include <list>

using namespace std;

//list容器 排序demo 对于自定义数据类型做排序
// 排序规则：
//按照年龄进行升序，如果年龄相同按照身高进行降序

// 自定义数据类型Person类
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;    //姓名
	int m_Age;        //年龄
	int m_Height;     //身高
};

bool ComparePerson(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

void test01()
{
	list<Person> L;

	//定义几个数据
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);


	//添加数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	//打印一下
	for (auto i : L)
	{
		cout << "姓名：" << i.m_Name << "年龄：" << i.m_Age << "身高：" << i.m_Height << endl;
	}

	// 排序
	cout << "--------------------------------------------------------" << endl;
	cout << "排序后" << endl;

	L.sort(ComparePerson);

	//打印一下
	for (auto i : L)
	{
		cout << "姓名：" << i.m_Name << "年龄：" << i.m_Age << "身高：" << i.m_Height << endl;
	}
}

int main() 
{
	test01();

	system("pause");
	return 0;
}