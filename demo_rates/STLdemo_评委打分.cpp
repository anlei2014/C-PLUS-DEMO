#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/*
有5名先手：先手ABCDE,10个评委分别对每一个选手打分，去除最高分，去除最低分，取平均分
*/

class Person
{
public:
	Person(string name, int score);

	string name;   // 姓名
	int m_Score;   // 分数
};

Person::Person(string name, int score)
{
	this->name = name;
	this->m_Score = score;
}

void createPerson(vector<Person> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		// 将创建的Person对象放入容器中
		v.push_back(p);
	}
}

//打分函数
void setScore(vector<Person> &v)
{
	for (auto i: v)
	{
		//将评委的分数 放入到deque容器中
		deque<int> d;
		for(int i = 0; i < 10; i++ )
		{
			int score = rand() % 41 + 60;   // 60-100
			d.push_back(score);
		}

		cout << "选手：" << i.name << "-----打分：" << endl;
		for (auto k : d)
		{
			cout << k << "  ";
		}
		cout << endl;
		//先排序
		sort(d.begin(), d.end());

		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (auto j : d)
		{
			sum += j;
		}

		int avg = sum / d.size();

		//将平均分给选手
		i.m_Score = avg;
		cout << endl;
		cout << i.m_Score;
		cout << endl;
	}
}

void printScore(vector<Person> &p)
{
	for (auto i2 : p)
	{
		cout << "姓名：" << i2.name << "平均分：" << i2.m_Score << endl;
	}

	for (vector<Person>::iterator it = p.begin(); it!= p.end(); it++)
	{
		cout << "姓名：" << it->name << "平均分：" << it->m_Score << endl;
	}

}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//1.创建5名选手
	vector<Person> v;  //存放选手的容器
	createPerson(v);

	// 测试
	for (auto i : v)
	{
		cout << "姓名：" << i.name << "------分数：" << i.m_Score << endl;
	}

	//2.给5名选手打分
	setScore(v);

	//3.显示最后得分
	printScore(v);

	system("pause");

}