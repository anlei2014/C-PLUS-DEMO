#include<iostream>


using namespace std;

class Person 
{
	// �Ǿ�̬��Ա������������Ķ�����
	int m_A;

	// ��̬��Ա��������������Ķ����ϡ�������Ҫ�����ʼ��
	static int m_B;


	// ��Ա����
	void func() {};     // �Ǿ�̬��Ա��������������Ķ���

	static void func2() {};       //��̬��Ա��������������Ķ���
};

// �����ʼ����ʽ
int Person::m_B = 0;

// �յ�����󣬴�СΪ1    Ϊ����������һ����һ�޶��ĵĶ���
int main()
{

	



}