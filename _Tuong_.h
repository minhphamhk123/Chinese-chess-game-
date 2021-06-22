#pragma once
#include"QuanCo.h"
class _Tuong_ :public QuanCo
{
	//Quân Tướng nha.
public:
	_Tuong_();
	void Create(int Type, int pos);
	Diem* ToaDoDiTheoLuat(int Type, int& count);
	void CachDi();
};
