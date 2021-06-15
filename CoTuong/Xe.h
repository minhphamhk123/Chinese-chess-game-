#pragma once
#include"QuanCo.h"
class Xe :public QuanCo
{
public:
	Xe();
	void Create(int Type, int pos);
	Diem* ToaDoDiTheoLuat(int Type, int& count);
	void CachDi();
};
