#include <iostream>
#include <string>
#include <vector>


using namespace std;


//����һ����
class Person
{
public:
	//���췽��
	Person(string name,int age)
	{
		this->age = age;
		this->name = name;
	}

	//��Ա����
	string name;
	int age;
};

//���Ժ���
void Test()
{
	//����һ���洢Person�����͵�����vector
	vector<Person> vp;

	//ʵ��������Perosn��

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//��ʵ����ӵ�������ʹ��β�巨
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	//���������е�����
	for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it ++)
	{
		//cout << "�����ǣ�" << (*it).name << "�����ǣ�" << (*it).age << endl;
		cout << "�����ǣ�" << it->name << "�����ǣ�" << it->age << endl;
	}
};



int main()
{
	//
	Test();

	//
	return 0;
}