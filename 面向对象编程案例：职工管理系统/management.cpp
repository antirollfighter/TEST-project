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


int management::search_by_id(int id)
{
	int index = -1;//��������ڣ�����-1,���򷵻ض�Ӧemp_array�����±�
	for (int i = 0; i < emp_num; i++)
	{
		if (id == this->emp_array[i]->m_id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int management::search_by_name(string name)
{
	int index = -1;//��������ڣ�����-1,���򷵻ض�Ӧemp_array�����±�
	for (int i = 0; i < emp_num; i++)
	{
		if (name == this->emp_array[i]->m_name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void management::delete_emp()
{
	if (this->is_empty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
		system("pause");
		system("cls");
    }
	else {
		int status = 0;
		int index;
		cout << "ͨ��������������1��ͨ��id��������2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "������Ҫɾ��ְԱ������: ";
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "������Ҫɾ��ְԱ��id: ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "���������������!" << endl;
			goto out;
		}
		if (index == -1)
		{
			cout << "��ְԱ������!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			delete this->emp_array[index];
			this->emp_array[index] = NULL;
			for (int i = index; i < this->emp_num - 1; i++)
			{
				this->emp_array[i] = this->emp_array[i + 1];
			}
			this->emp_num--;
			this->save();//���޸ı��浽�ļ�
			cout << "�ɹ�ɾ��һ��ְԱ" << endl;
			system("pause");
			system("cls");
		}
	}
}

void management::modifi_emp()
{
	if (this->is_empty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int status = 0;
		int index;
		cout << "ͨ��������������1��ͨ��id��������2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "������Ҫ�޸�ְԱ������: ";
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "������Ҫ�޸�ְԱ��id: ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "���������������!" << endl;
			goto out;
		}
		if (index == -1)
		{
			cout << "��ְԱ������!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			int n_id;
			string n_name;
			int n_did;
			cout << "�����޸ĺ��id" << endl;
			cin >> n_id;
			cout << "�����޸ĺ������" << endl;
			cin >> n_name; 
			cout << "�����޸ĺ�Ĳ��ű��" << endl;
			cout << "1.��ְͨԱ" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;out2:
			cin >> n_did;
			worker* w = NULL;
			switch (n_did)
			{
			case 1:
				w = new employee(n_id, n_name, n_did);
				break;
			case 2:
				w = new manager(n_id, n_name, n_did);
				break;
			case 3:
				w = new boss(n_id, n_name, n_did);
				break;
			default:
				cout << "���������������!" << endl;
				goto out2;
			}
			delete this->emp_array[index];
			this->emp_array[index] = w;
			this->save();
			cout << "�ɹ��޸ĸ�ְԱ��Ϣ" << endl;
			system("pause");
			system("cls");
		}
	}

}

void management::find_emp()
{
	if (this->is_empty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int status = 0;
		int index;
		cout << "ͨ��������������1��ͨ��id��������2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "��Ҫ����ְ��������" << endl;
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "��Ҫ����ְ����id ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "���������������" << endl;
				goto out;
		}
		if (index == -1)
		{
			cout << "���޴���" << endl;
		}
		else
		{
			cout << "��ѯ�ɹ������˵���Ϣ����:" << endl;
			this->emp_array[index]->show_info();
			system("pause");
			system("cls");
		}
	}
}
void management::show_info()
{
	if (this->is_empty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->emp_num; i++)
	{
		this->emp_array[i]->show_info();
	}
	system("pause");
	system("cls");
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
	if (ifs.eof())//�������ַ�Ϊeof
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
			cout << "3.�ϰ�" << endl;out2: 
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
		this->is_empty = false;
	}

	else
	{
		cout << "�������,��������" << endl;
		goto out;
	}
	system("pause");
	system("cls");

}

void management::sort_emp()
{
	if (this->is_empty)
	{
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������ѡ1������ѡ2" << endl;
		int choice;
		cin >> choice;
		for (int i = 0; i < this->emp_num; i++)
		{
			int maxormin = i;
			for (int j = i + 1; j < this->emp_num; j++)
			{
				if (choice == 1)
				{
					if (this->emp_array[i]->m_id > this->emp_array[j]->m_id)
						maxormin = j;
				}
				else if (choice == 2)
				{
					if (this->emp_array[i]->m_id < this->emp_array[j]->m_id)
						maxormin = j;
				}
				
			}
			if (maxormin!=i)
			{
				worker* temp;
				temp = this->emp_array[i];
				this->emp_array[i] = this->emp_array[maxormin];
				this->emp_array[maxormin] =temp;
			}
		}
		this->save();
		cout << "����ɹ�" << endl;
		//this->show_info();
		system("pause");
		system("cls");
	}
}

void management::clearfile()
{
	cout << "ȷ����գ�y/n" << endl;
	string choice;out:
	cin >> choice;
	if (choice == "n")
	{
		return;
	}
	else if (choice == "y")
	{
		ofstream ofs(FILENAME, ios::trunc);//�������ɾ�����ؽ��ļ�
		ofs.close();
		if (this->emp_array != NULL)
		{
			for (int i = 0; i < this->emp_num; i++)
			{  
				if(this->emp_array[i]!=NULL)
				delete this->emp_array[i];
			}

		}
		this->emp_num = 0;
		delete[]this->emp_array;
		this->emp_array = NULL;
		this->is_empty = true;
		cout << "����ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������,��������" << endl;
		goto out;
	}
}
management::~management()
{
	if (this->emp_array != NULL)
	{
		delete[]this->emp_array;
		this->emp_array = NULL;
	}
}
