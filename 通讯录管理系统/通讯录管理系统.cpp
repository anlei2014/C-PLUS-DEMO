// ��װ������ʾ�ý��� ��void showMenu()
// ��main�����е��÷�װ�õĺ���

#include <iostream>
using namespace std;

#define MAX 1000
// �����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�  1 ��    2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

// ���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	// ͨѶ¼����Ա����
	int m_Size;
};

//�˵�����
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1�������ϵ��	*****" << endl;
	cout << "*****	2����ʾ��ϵ��	*****" << endl;
	cout << "*****	3��ɾ����ϵ��	*****" << endl;
	cout << "*****	4��������ϵ��	*****" << endl;
	cout << "*****	5���޸���ϵ��	*****" << endl;
	cout << "*****	6�������ϵ��	*****" << endl;
	cout << "*****	0���˳�ͨѶ¼	*****" << endl;
	cout << "*****************************" << endl;
}

int main()
{

	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;




	int select = 0;

	while (true)
	{
		//�˵��ĵ���
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  // 1.�����ϵ��
			addPerson(&abs);
			break;
		case 2:	 // 2.��ʾ��ϵ��
			break;
		case 3:  // 3.ɾ����ϵ��
			break;
		case 4:  // 4.������ϵ��
			break;
		case 5:  // 5.�޸���ϵ��
			break;
		case 6:  // 6.�����ϵ��
			break;
		case 0:  // 0.�˳�

			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}