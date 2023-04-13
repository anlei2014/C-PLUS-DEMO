#include<iostream>

using namespace std;

// 多态

//动态多态满足条件
// 1.有继承关系
// 2.子类重写父类的虚函数
// 
// 动态多态的使用
// 父类的指针或者引用 执行子类对象   Animal &animal = cat
// 首先定义一个基类：动物
class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在叫" << endl;
	};

};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "cat在叫" << endl;

	};
};

//定义一个说话的函数
// 地址早绑定，在编译阶段确定函数地址    Animal &animal = cat
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定，加virtual
void doSpeak(Animal &animal)
{
	animal.speak();
};

// 测试类
void Test01()
{
	Cat cat;
	doSpeak(cat);

};

/*
int main()
{
	// 调用测试类

	Test01();

	return 0;
}
*/