#include "speechManager.h"
#include <deque>

/*

功能描述：
	提供菜单界面与用户交互
	对演讲比赛流程进行控制
	与文件的读写交互

*/

// 构造函数的实现
SpeechManager::SpeechManager()
{
	// 调用初始化函数
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();
}

//菜单功能
void SpeechManager::showMenu()
{
	cout << "**********************************************************************" << endl;
	cout << "**************************  欢迎参加演讲比赛  ************************" << endl;
	cout << "**************************   1.开始演讲比赛  *************************" << endl;
	cout << "**************************   2.查看往届记录  *************************" << endl;
	cout << "**************************   3.清空比赛记录  *************************" << endl;
	cout << "**************************   0.退出比赛程序  *************************" << endl;
	cout << "**********************************************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


//初始化
void SpeechManager::initSpeech()
{
	// 容器都是空
	this->v1.clear();
	this->v2.clear();
	this->vVivtory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.length(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		// 创建演讲者
		Speaker sp;

		// 给演讲者赋值
		sp.m_Name = name;

		// 初始化演讲者的分数
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并放入到v1容器中
		this->v1.push_back(i + 10001);

		// 选手编号以及对应选手  放入到map 容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

}

void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	// 3.显示晋级结果

	// 第二轮开始比赛

	//1.抽签

	//2.比赛

	// 3.显示晋级结果

	//4.保存分数到文件中
}

void SpeechManager::speechDraw()
{
	cout << "第<<" << this->m_Index << ">> 轮比赛选手正在抽签" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_Index == 1)
	{
		// 第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (auto i : v1)
		{
			cout << i << "   ";
		}
		cout << endl;
	}
	else
	{
		// 第二轮比赛
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
	cout << "-------------- 第" << this->m_Index << "轮比赛正式开始----------------------" << endl;

	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0;   // 记录人员个数，6人一组

	vector<int> v_Src;   //比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// 遍历所有选手进行比赛
	for (auto i : v_Src)
	{
		num++;
		//评委打分
		deque<double> dq;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;   //600 ` 1000
			//cout << score << " ";
			dq.push_back(score);
		}

		sort(dq.begin(), dq.end(),greater<double>());   // 排序

		dq.pop_front();    // 去除最高分
		dq.pop_back();		//去除最低分

		double sum = accumulate(dq.begin(), dq.end(), 0.0f);
		double avg = sum / (double)dq.size();     // 平均分

		//打印评分均
		//cout << "编号：" << i << "姓名：" << this->m_Speaker[i].m_Name << "获取平均分：" << avg << endl;


		// 将平均分放入到map
		this->m_Speaker[i].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, i));   // key是得分，vaule是具体选手编号

		// 每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (auto j : groupScore)
			{
				cout << "编号：" << j.second << "姓名：" << this->m_Speaker[j.second].m_Name << "成绩：" << this->m_Speaker[j.second].m_Score[this->m_Index - 1] << endl;
			}




			groupScore.clear();   //小组清空

		}





	}
	cout << endl;

}

//析构函数的实现
SpeechManager::~SpeechManager()
{


}