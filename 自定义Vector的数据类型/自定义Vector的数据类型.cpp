#include <iostream>
#include <string>
#include <vector>


using namespace std;


//定义一个类
class Person
{
public:
	//构造方法
	Person(string name,int age)
	{
		this->age = age;
		this->name = name;
	}

	//成员变量
	string name;
	int age;
};

//测试函数
void Test()
{
	//定义一个存储Person类类型的容器vector
	vector<Person> vp;

	//实例化几个Perosn类

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//把实例添加到容器，使用尾插法
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it ++)
	{
		//cout << "姓名是：" << (*it).name << "年龄是：" << (*it).age << endl;
		cout << "姓名是：" << it->name << "年龄是：" << it->age << endl;
	}
};



int main()
{
	//
	Test();

	//
	return 0;
}