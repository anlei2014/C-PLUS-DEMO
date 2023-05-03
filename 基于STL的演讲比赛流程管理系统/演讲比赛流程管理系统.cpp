#include <iostream>
#include "speechManager.h"


using namespace std;

int main()
{
	//创建管理类对象
	SpeechManager sm;

	//测试12名选手创建
	//for (auto it : sm.m_Speaker)
	//{
	//	cout << "选后编号" << it.first << "姓名：" << it.second.m_Name << "分数：" << it.second.m_Score[0] << endl;
	//}

	//用来存储用户的选项
	int choice = 0;  

	while (true)
	{
		sm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:		//开始比赛
			sm.startSpeech();
			break;
		case 2:		//查看往届比赛记录
			break;
		case 3:		//清空比赛记录
			break;
		case 0:		//退出系统
			sm.exitSystem();
			break;
		default:
			system("cls");	//清屏
			break;
		}
	}

	system("pause");
	return 0;
}