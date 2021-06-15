#pragma once
#include"QuanCo.h"
class Ngua :public QuanCo
{
public:
	Ngua();

	void Create(int Type, int pos);

	Diem* ToaDoDiTheoLuat(int Type, int& count);

	void CachDi();
};
