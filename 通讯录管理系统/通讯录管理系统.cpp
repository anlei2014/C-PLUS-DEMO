// 封装函数显示该界面 如void showMenu()
// 在main函数中调用封装好的函数

#include <iostream>
using namespace std;

#define MAX 1000
// 设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别  1 男    2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

// 设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	// 通讯录中人员个数
	int m_Size;
};

//菜单界面
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1、添加联系人	*****" << endl;
	cout << "*****	2、显示联系人	*****" << endl;
	cout << "*****	3、删除联系人	*****" << endl;
	cout << "*****	4、查找联系人	*****" << endl;
	cout << "*****	5、修改联系人	*****" << endl;
	cout << "*****	6、清空联系人	*****" << endl;
	cout << "*****	0、退出通讯录	*****" << endl;
	cout << "*****************************" << endl;
}

int main()
{

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;




	int select = 0;

	while (true)
	{
		//菜单的调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:  // 1.添加联系人
			addPerson(&abs);
			break;
		case 2:	 // 2.显示联系人
			break;
		case 3:  // 3.删除联系人
			break;
		case 4:  // 4.查找联系人
			break;
		case 5:  // 5.修改联系人
			break;
		case 6:  // 6.清空联系人
			break;
		case 0:  // 0.退出

			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}