#include "speechManager.h"
#include <deque>

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
	this->speechContest();
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

void SpeechManager::speechContest()
{
	cout << "-------------- ��" << this->m_Index << "�ֱ�����ʽ��ʼ----------------------" << endl;

	//׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0;   // ��¼��Ա������6��һ��

	vector<int> v_Src;   //����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// ��������ѡ�ֽ��б���
	for (auto i : v_Src)
	{
		num++;
		//��ί���
		deque<double> dq;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;   //600 ` 1000
			//cout << score << " ";
			dq.push_back(score);
		}

		sort(dq.begin(), dq.end(),greater<double>());   // ����

		dq.pop_front();    // ȥ����߷�
		dq.pop_back();		//ȥ����ͷ�

		double sum = accumulate(dq.begin(), dq.end(), 0.0f);
		double avg = sum / (double)dq.size();     // ƽ����

		//��ӡ���־�
		//cout << "��ţ�" << i << "������" << this->m_Speaker[i].m_Name << "��ȡƽ���֣�" << avg << endl;


		// ��ƽ���ַ��뵽map
		this->m_Speaker[i].m_Score[this->m_Index - 1] = avg;

		//��������� ���뵽��ʱС��������
		groupScore.insert(make_pair(avg, i));   // key�ǵ÷֣�vaule�Ǿ���ѡ�ֱ��

		// ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (auto j : groupScore)
			{
				cout << "��ţ�" << j.second << "������" << this->m_Speaker[j.second].m_Name << "�ɼ���" << this->m_Speaker[j.second].m_Score[this->m_Index - 1] << endl;
			}




			groupScore.clear();   //С�����

		}





	}
	cout << endl;

}

//����������ʵ��
SpeechManager::~SpeechManager()
{


}