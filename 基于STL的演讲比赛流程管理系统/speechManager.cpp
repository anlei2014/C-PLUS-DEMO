#include "speechManager.h"

/*

����������
	�ṩ�˵��������û�����
	���ݽ��������̽��п���
	���ļ��Ķ�д����

*/

// ���캯����ʵ��
SpeechManager::SpeechManager()
{
	// ���ó�ʼ������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();
}

//�˵�����
void SpeechManager::showMenu()
{
	cout << "**********************************************************************" << endl;
	cout << "**************************  ��ӭ�μ��ݽ�����  ************************" << endl;
	cout << "**************************   1.��ʼ�ݽ�����  *************************" << endl;
	cout << "**************************   2.�鿴�����¼  *************************" << endl;
	cout << "**************************   3.��ձ�����¼  *************************" << endl;
	cout << "**************************   0.�˳���������  *************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


//��ʼ��
void SpeechManager::initSpeech()
{
	// �������ǿ�
	this->v1.clear();
	this->v2.clear();
	this->vVivtory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.length(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		// �����ݽ���
		Speaker sp;

		// ���ݽ��߸�ֵ
		sp.m_Name = name;

		// ��ʼ���ݽ��ߵķ���
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ţ������뵽v1������
		this->v1.push_back(i + 10001);

		// ѡ�ֱ���Լ���Ӧѡ��  ���뵽map ������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1.��ǩ
	this->speechDraw();
	//2.����

	// 3.��ʾ�������

	// �ڶ��ֿ�ʼ����

	//1.��ǩ

	//2.����

	// 3.��ʾ�������

	//4.����������ļ���
}

void SpeechManager::speechDraw()
{
	cout << "��<<" << this->m_Index << ">> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		// ��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (auto i : v1)
		{
			cout << i << "   ";
		}
		cout << endl;
	}
	else
	{
		// �ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (auto i : v2)
		{
			cout << i << "";
		}
		cout << endl;
	}
	cout << "----------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

//����������ʵ��
SpeechManager::~SpeechManager()
{


}