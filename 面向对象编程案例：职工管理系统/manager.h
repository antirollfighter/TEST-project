#pragma once
#include "abstract_worker.h"//����
class manager :public worker
{public:
	void show_info();
	string get_department_name();
	manager(int id, string name, int did);
};

