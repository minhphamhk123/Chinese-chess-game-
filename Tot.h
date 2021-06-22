#pragma once
#include "QuanCo.h"
class Tot :public QuanCo
{
public:
	Tot();
	void Create(int Type, int pos);
	Diem* ToaDoDiTheoLuat(int Type, int& count);
	void CachDi();
};

