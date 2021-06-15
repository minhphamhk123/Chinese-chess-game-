#pragma once
#include"QuanCo.h"
class Phao :public QuanCo
{
public:
	Phao();
	void Create(int Type, int pos);

	Diem* ToaDoDiTheoLuat(int Type, int& count);

	void CachDi();
};

