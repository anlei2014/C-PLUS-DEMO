#include<iostream>

using namespace std;


// const 修饰修饰指针有三种情况：
// 1.const修饰指针  --------常量指针
// 2.const修饰常量  --------指针常量
// 3.const既修饰指针，又修饰常量

int main()
{
	
	//1.const修饰指针  --------常量指针
	int a = 10;
	int b = 10;

	const int* p = &a;
	int const* p3 = &a;  // 同上
	// 特点指向的值不可以改，指针的指向可以改
	//*p = 20;   错误
	//*p3 = 100;  
	p = &b;

	// 2.const修饰常量  --------指针常量
	int* const p2 = &a;


	*p2 = 100;

	//p2 = &b;   错误

	// 3.const既修饰指针，又修饰常量


	//  总结：在谁前面谁就不可以改
}