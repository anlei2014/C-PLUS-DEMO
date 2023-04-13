#include<iostream>

using namespace std;


class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}

	int m_num1;
	int m_num2;
};


class AddCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}

};

void Test2()
{
	AbstractCalculator* abc = new AddCalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;

	cout << abc->getResult() << endl;

	delete abc;
}





int main()
{
	Test2();

	return 0;
}