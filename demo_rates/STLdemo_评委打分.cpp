#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/*
��5�����֣�����ABCDE,10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ͷ֣�ȡƽ����
*/

class Person
{
public:
	Person(string name, int score);

	string name;   // ����
	int m_Score;   // ����
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
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		// ��������Person�������������
		v.push_back(p);
	}
}

//��ֺ���
void setScore(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		//����ί�ķ��� ���뵽deque������
		deque<int> d;
		for(int i = 0; i < 10; i++ )
		{
			int score = rand() % 41 + 60;   // 60-100
			d.push_back(score);
		}

		cout << "ѡ�֣�" << it->name << "-----��֣�" << endl;
		for (auto k : d)
		{
			cout << k << "  ";
		}
		cout << endl;
		//������
		sort(d.begin(), d.end());

		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (auto j : d)
		{
			sum += j;
		}

		int avg = sum / d.size();

		//��ƽ���ָ�ѡ��
		it->m_Score = avg;

		cout << endl;
		cout << it->m_Score;
		cout << endl;
	}
}

//��ֺ���2
void setScore2(vector<Person>& v)
{
	/*   �������ص㣬�����Ҫ�޸�ֵ������Ҫ�������õķ�ʽ  auto& i   */
	for (auto& i:v)
	{
		//����ί�ķ��� ���뵽deque������
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;   // 60-100
			d.push_back(score);
		}

		cout << "ѡ�֣�" << i.name << "-----��֣�" << endl;
		for (auto k : d)
		{
			cout << k << "  ";
		}
		cout << endl;
		//������
		sort(d.begin(), d.end());

		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (auto j : d)
		{
			sum += j;
		}

		int avg = sum / d.size();

		//��ƽ���ָ�ѡ��
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
		cout << "������" << i2.name << "ƽ���֣�" << i2.m_Score << endl;
	}

	for (vector<Person>::iterator it = p.begin(); it!= p.end(); it++)
	{
		cout << "������" << it->name << "ƽ���֣�" << it->m_Score << endl;
	}

}



//test
void test()
{
	vector<int> arr;
	for (int i = 0; i < 4; i++)
	{
		arr.push_back(i);
	}
	for (auto& it : arr) {
		cout << "00000000000000000000000000000000000" << endl;
		cout << it* 2 << endl;
		cout << "00000000000000000000000000000000000" << endl;
	}

}


int main()
{
	//test();

	//���������
	srand((unsigned int)time(NULL));

	//1.����5��ѡ��
	vector<Person> v;  //���ѡ�ֵ�����
	createPerson(v);

	// ����
	for (auto i : v)
	{
		cout << "������" << i.name << "------������" << i.m_Score << endl;
	}

	//2.��5��ѡ�ִ��
	//setScore(v);
	setScore2(v);

	//3.��ʾ���÷�
	printScore(v);

	system("pause");

}