#include "manager.h"

manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void manager::show_info()
{
	cout << "\tְ��������" << this->m_name << endl;
	cout << "\tְ�����: " << this->m_id << endl;
	cout << "\t��λ���: " << this->m_department_id << endl;
	cout << "\t��λְ��: ����ϰ岼�õ������·���Ա��" << endl;
}

string manager::get_department_name()
{
	return string("����");
}
