#include "employee.h"
using namespace std;
//���캯����ʼ����Ϣ
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void employee::show_info()
{
	cout << "\tְ��������" << this->m_name << endl;
	cout << "\tְ�����: " << this->m_id << endl;
	cout << "\t��λ���: " << this->m_department_id << endl;
	cout << "\t��λְ��: ��ɾ����õ�����" << endl;
}

string employee::get_department_name()
{
	return string("��ְͨ��");
}

