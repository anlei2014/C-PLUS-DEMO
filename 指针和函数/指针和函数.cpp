#include<iostream>

using namespace std;

//int main()
//{
//	//数组的遍历
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int* p;
//
//	p = arr;
//	cout << arr << endl;
//	cout << *p << endl;
//
//
//	for (int i = 0; i < 10; i++)
//	{
//		//cout << arr[i] << endl;
//		cout << *p << endl;
//		p++;
//	}
//}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main()
{
	
	int a = 10;
	int b = 20;

	swap(&a, &b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}