#include <iostream>
#include "speechManager.h"


using namespace std;

int main()
{
	//�������������
	SpeechManager sm;

	//����12��ѡ�ִ���
	//for (auto it : sm.m_Speaker)
	//{
	//	cout << "ѡ����" << it.first << "������" << it.second.m_Name << "������" << it.second.m_Score[0] << endl;
	//}

	//�����洢�û���ѡ��
	int choice = 0;  

	while (true)
	{
		sm.showMenu();

		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:		//��ʼ����
			sm.startSpeech();
			break;
		case 2:		//�鿴���������¼
			break;
		case 3:		//��ձ�����¼
			break;
		case 0:		//�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");	//����
			break;
		}
	}

	system("pause");
	return 0;
}