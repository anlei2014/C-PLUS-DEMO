#include <iostream>
#include <vector>

using namespace std;


void test01()
{
	vector<int> v1;   // Ĭ�Ϲ��� �޲ι���

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//ͨ�����䷽ʽ���й���
	vector<int> v2(v1.begin(), v1.end());

	// n ��elem��ʽ����
	vector<int> v3(10,5);

	//��������
	vector<int> v4(v3);


}


int main()
{
	
}