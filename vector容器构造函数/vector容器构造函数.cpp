#include <iostream>
#include <vector>

using namespace std;


void test01()
{
	vector<int> v1;   // 默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	//通过区间方式进行构造
	vector<int> v2(v1.begin(), v1.end());

	// n 个elem方式构造
	vector<int> v3(10,5);

	//拷贝构造
	vector<int> v4(v3);


}


int main()
{
	
}