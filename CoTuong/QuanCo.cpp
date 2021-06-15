#include "QuanCo.h"
QuanCo::QuanCo()
{
	Index = -1;
}
QuanCo::QuanCo(const QuanCo& temp)
{
	Index = temp.Index;
	DiemDangDung = temp.DiemDangDung;
}
QuanCo& QuanCo::operator=(const QuanCo& temp)
{
	Index = temp.Index;
	DiemDangDung = temp.DiemDangDung;
	return *this;
}
int QuanCo::GetIndex()
{
	return this->Index;
}
void QuanCo::SetIndex(int temp)
{
	this->Index = temp;
}
Diem QuanCo::GetDiemDangDung()
{
	return this->DiemDangDung;
}
void QuanCo::SetDiemDangDung(int x, int y)
{
	this->DiemDangDung.SetDiem(x, y);
}
QuanCo::~QuanCo() {}