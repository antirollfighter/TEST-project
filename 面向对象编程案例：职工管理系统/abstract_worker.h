#pragma once
#include<string>
#include<iostream>
using namespace std;
//ְ�����ԣ�ְ����ţ�ְ��������ְ�����ڲ��ű�ţ����ű��ĿǰĬ�ϴ�������Ϊ1��2��3��
//ְ����Ϊ����λְ����Ϣ��������Ա�����ϰ壬����3���˵�ְ�𣩣���ȡ��λ����

class worker
{
public:
	virtual void show_info() = 0;//��ʾ������Ϣ
	virtual string get_department_name() = 0;//��ȡ��λ����

	int m_id;//������
	string m_name;//����
	int m_department_id;//���ű��
};