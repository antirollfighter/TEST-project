#include<iostream>
using namespace std;
//p75�ݹ�����������
int comm(int n, int k)
{
	if (k > n)
	{
		return 0;
	}
	else if (k == 0 || n == 0)
	{
		return 1;
	}

	else
	{
		return  comm(n - 1, k - 1) + comm(n - 1, k);
	}
}

void test06()
{
	int n, k;
	cout << "����n,k" << endl;
	cin >> n >> k;
	int cnk = comm(n, k);
	cout << "cnk= " << cnk << endl;
}