#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include"abstract_worker.h"
class management
{
public:
	static void display_menu();
	void addperson();//�˴���ʾ�÷�����ķ�ʽ��̬��������
	management();
	~management();
	void save();//���浽�ļ�
    int emp_num;//��¼ְ������
	worker** emp_array;
	bool is_empty;//�ж��ļ��Ƿ����/�Ƿ�Ϊ��
	int get_num();
	void emp_init();
	void show_info();
	int search_by_id(int id);//ͨ��id�ж��Ƿ���ڸ�ְ����ɾ��ְ����ʱ����Ҫ�õ���
	int search_by_name(string name);//ͨ������
	void delete_emp();
	void modifi_emp();
	void find_emp();
	void sort_emp();//ͨ�������������
	void clearfile();
}; 