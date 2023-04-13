#include<iostream>
#include<string>

using namespace std;



//  类的声明
class Building;

class googGay
{
public:
	//构造函数
	googGay();

	void visit();
private:
	Building* building;

};


class Building
{
	//  友元函数需要加上类的名字
	friend void googGay::visit();
public:
	Building();
	string m_Settingroom;

private:
	string m_Bedroom;
};

// 构造函数初始化
Building::Building()
{
	m_Settingroom = "客厅";
	m_Bedroom = "卧室";
}

// 在googGay的构造函数中初始化创建一个Building的实例
googGay::googGay()
{
	building = new Building;
}

void googGay::visit()
{
	cout << "正在参观" << building->m_Settingroom << endl;
	cout << "正在参观" << building->m_Bedroom << endl;
}

void Test() 
{
	googGay gg;
	gg.visit();
}

int main()
{
	Test();

	return 0;
}