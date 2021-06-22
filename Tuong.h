#pragma once
#include"QuanCo.h"
class Tuong :public QuanCo
{
	//Quân Tượng nha.
public:
	Tuong();
	void Create(int Type, int pos);
	Diem* ToaDoDiTheoLuat(int Type, int& count);
	void CachDi();
};
