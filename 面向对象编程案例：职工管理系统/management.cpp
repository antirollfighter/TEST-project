#include"management.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#include"abstract_worker.h"
#define FILENAME "emp.txt "
using namespace std;
void management::display_menu()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "              ѡ������Ҫ�õĹ��ܲ������Ӧ����:" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "              0.�˳�                                          "<<endl;
	cout << "              1.����ְ����Ϣ                                          " << endl;
	cout << "              2.��ʾְ����Ϣ                                          " << endl;
	cout << "              3.ɾ����ְְ��                                          " << endl;
	cout << "              4.�޸�ְ����Ϣ                                          " << endl;
	cout << "              5.����ְ����Ϣ                                   " << endl;
	cout << "              6.����ְ����Ž�������                                          " << endl;
	cout << "              7.����ļ��м�¼��ְ����Ϣ                                          " << endl;
	cout << "------------------------------------------------------------------" << endl;
}


int management::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int did;
	string name;

	int num = 0;//��¼����
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

void management::emp_init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* w = NULL;
		if (did == 1)
		{
			w = new employee(id, name, did);
		}
		else if (did == 2)
		{
			w = new manager(id, name, did);
		}
		else
		{
			w = new boss(id, name, did);
		}
		this->emp_array[index] = w;
		index ++;
	}
	ifs.close();
}

management::management()
{   //�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->emp_array = NULL;
		this->emp_num = 0;
		is_empty = true;
		ifs.close();
		return;
	}
	//�ļ�����������Ϊ��
	char ch;
	ifs >>ch;//���ƶ�һ���ַ�
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->emp_array = NULL;
		this->emp_num = 0;
		is_empty = true;
		ifs.close();
		return;
	}
	//�ļ�������������
	int num = this->get_num();
	cout << "�ļ�����" << num << "��" << endl;
	this->emp_num = num;
	this->emp_array = new worker * [this->emp_num];//���������ļ���ʼ���ռ�
	this->emp_init();//���ļ����ݴ��浽������
}


void management::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i <this-> emp_num; i++)
	{
		ofs << this->emp_array[i]->m_id << " " <<
			this->emp_array[i]->m_name << " " <<			
			this->emp_array[i]->m_department_id << endl;
	}
	ofs.close();
}


void management::addperson()
{
	int add_num = 0;
	cout << "�������ְ��������" << endl; out:
	cin >> add_num;
	if (add_num > 0)
	{
		int new_num = this->emp_num + add_num;//��¼������������;

		//��¼��ӵ��¿ռ�
		worker** new_size = new worker * [new_num];//new_size��ָ��workerָ���ָ��
		//��ԭ���ռ���˷Ž��¿ռ�
		if (this->emp_array != NULL)
		{
			for (int i = 0; i < this->emp_num; i++)
			{
				new_size[i] = this->emp_array[i];
			}
		}
		//�������
		for (int i = 0; i < add_num; i++)
		{
			string name;
			int id;
			int did;

			cout << "�����" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "�����" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;

			cout << "�����" << i + 1 << "��ְ���ĸ�λ���" << endl;
			cout << "1.��ְͨԱ" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl; out2:
			cin >> did;
			worker* w = NULL;//�����������ָ����ָ���������ʵ�ֶ�̬
			switch (did)
			{
			case 1:
				w = new employee(id, name, did);
				break;
			case 2:
				w = new manager(id, name, did);
				break;
			case 3:
				w = new boss(id, name, did);
				break;
			default:
				cout << "���������������!" << endl;
				goto out2;
			}
			new_size[this->emp_num+i] = w;//���Ѿ�ָ����ְ�����󲢳�ʼ����ɵ�ָ��w�����¿ռ��Ӧ��λ��
		}
		//ɾȥԭ���Ŀռ�
		delete[]emp_array;
		//����ְ������
		emp_num = new_num;
		this->emp_array = new_size;
		cout << "�ɹ����" << add_num << "��ְ��" << endl;
		this->save();
	}

	else
	{
		cout << "�������,��������" << endl;
		goto out;
	}
	system("pause");
	system("cls");

}

management::~management()
{
	if (this->emp_array != NULL)
	{
		delete[]this->emp_array;
		this->emp_array = NULL;
	}
}
