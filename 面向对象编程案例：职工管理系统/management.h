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

};