#include<iostream>
#include<cstdlib>
using namespace std;
//p70
//rand()���ɵ���α���������������randֻ������ͬһ��������Ҫ��srand(unsigned int seed)ʹ֮�������

int rolldice()
{
	int r1 = 1 + rand() % 6;
	int r2 = 1 + rand() % 6;
	int sum = r1 + r2;
	cout << "���ε���֮�� " << r1 << "+" << r2 << "=" << sum << endl;
	return sum;
}


string judge2(int &sum,int &mypoint)
{
	string status;
	switch (sum)
	{
	case 7:
	case 11:
		status = "win";
		break;

	case 2:
	case 3:
	case 12:
		status = "lose";
		break;

	default:
		status = "playing";
		 sum = mypoint;
		 cout << "�ҵĵ����� " << mypoint << endl;
	}

	return status;
	
}


void test05()
{
	string status;
	unsigned int seed;
	int sum, mypoint;//sum���յ�һ�ε�����mypoint����sum;
	cout << "�������������:" << endl;
	cin >> seed;
	srand(seed);
	sum = rolldice();
	status=judge2(sum,mypoint);
	while (status == "playing")
	{
		sum = rolldice();
		if (sum == mypoint)
		{
			status = "win";
		}
		else if (sum == 7)
		{
			status = "lose";
		}

	}
	if (status == "win")
		cout << "��Ӯ��" << endl;
	else
		cout << "������" << endl;
}