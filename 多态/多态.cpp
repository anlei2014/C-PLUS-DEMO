#include<iostream>

using namespace std;

// ��̬

//��̬��̬��������
// 1.�м̳й�ϵ
// 2.������д������麯��
// 
// ��̬��̬��ʹ��
// �����ָ��������� ִ���������   Animal &animal = cat
// ���ȶ���һ�����ࣺ����
class Animal
{
public:
	virtual void speak()
	{
		cout << "�����ڽ�" << endl;
	};

};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "cat�ڽ�" << endl;

	};
};

//����һ��˵���ĺ���
// ��ַ��󶨣��ڱ���׶�ȷ��������ַ    Animal &animal = cat
// �����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ��󶨣���virtual
void doSpeak(Animal &animal)
{
	animal.speak();
};

// ������
void Test01()
{
	Cat cat;
	doSpeak(cat);

};

/*
int main()
{
	// ���ò�����

	Test01();

	return 0;
}
*/