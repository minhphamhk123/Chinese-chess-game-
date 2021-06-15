#pragma once
#include"QuanCo.h"
class Si :public QuanCo
{
public:
	Si();

	void Create(int Type, int pos);
	Diem* ToaDoDiTheoLuat(int Type, int& count);

	void CachDi();
};
