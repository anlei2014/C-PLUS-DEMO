#include<iostream>
#include<string>

using namespace std;



//  �������
class Building;

class googGay
{
public:
	//���캯��
	googGay();

	void visit();
private:
	Building* building;

};


class Building
{
	//  ��Ԫ������Ҫ�����������
	friend void googGay::visit();
public:
	Building();
	string m_Settingroom;

private:
	string m_Bedroom;
};

// ���캯����ʼ��
Building::Building()
{
	m_Settingroom = "����";
	m_Bedroom = "����";
}

// ��googGay�Ĺ��캯���г�ʼ������һ��Building��ʵ��
googGay::googGay()
{
	building = new Building;
}

void googGay::visit()
{
	cout << "���ڲι�" << building->m_Settingroom << endl;
	cout << "���ڲι�" << building->m_Bedroom << endl;
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