#pragma once
#include <iostream>
#include <vector>
#include "speaker.h"
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

//����ݽ������Ĺ�����
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void showMenu();
	

	//�˳�ϵͳ
	void exitSystem();
	
	//��������
	~SpeechManager();


	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ���� �����������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();



	//��Ա����
	// �����һ�ֱ���ѡ�ֱ������
	vector<int> v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int> vVivtory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker> m_Speaker;

	//��ű�������
	int m_Index;
};
