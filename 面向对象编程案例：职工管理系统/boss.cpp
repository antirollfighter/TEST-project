#include "boss.h"

boss::boss(int id, string name,int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void boss::show_info()
{
	cout << "\tְ��������" << this->m_name << endl;
	cout << "\tְ�����: " << this->m_id << endl;
	cout << "\t��λ���: " << this->m_department_id << endl;
	cout << "\t��λְ��: �������������" << endl;
}

string boss::get_department_name()
{
	return string("�ϰ�");
}