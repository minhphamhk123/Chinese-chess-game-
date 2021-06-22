#pragma once
#include "Diem.h"

class QuanCo
{
protected:
	int Index;
	Diem DiemDangDung;
public:
	QuanCo();
	QuanCo(const QuanCo& temp);
	QuanCo& operator=(const QuanCo& temp);
	~QuanCo();
	virtual Diem* ToaDoDiTheoLuat(int Type, int& count) = 0;
	virtual void Create(int Type, int pos) = 0;
	virtual void CachDi() = 0;
	int GetIndex();
	void SetIndex(int temp);
	Diem GetDiemDangDung();
	void SetDiemDangDung(int x, int y);
};
