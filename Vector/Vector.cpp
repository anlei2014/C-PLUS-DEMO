#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(int val)
{
	cout << val << endl;
}
void Test01() 
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//1
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	//while (itBegin != itEnd)
	//{
	//	cout << "**************" << endl;
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//2

	//for (itBegin; itBegin != itEnd; itBegin++)
	//{
	//	cout << "**************" << endl;
	//	cout << *itBegin << endl;
	//}

	//3
	for_each(itBegin, itEnd, Print);

}


int main()
{
	Test01();
	
	return 0;
}