#include "Diem.h"
Diem::Diem()
{
	x = y = -1;
}
Diem::Diem(int x, int y)
{
	this->x = x;
	this->y = y;
}
Diem::Diem(const Diem& temp)
{
	x = temp.x;
	y = temp.y;
}
Diem& Diem::operator=(const Diem& temp)
{
	x = temp.x;
	y = temp.y;
	return *this;
}
Diem::~Diem() {}
void Diem::Nhap()
{
	cout << "\tDoc: ";
	cin >> x;
	cout << "\tNgang: ";
	cin >> y;
	while (x < 1 || y < 1)
	{
		cout << "Khong hop le. Nhap lai.\n";
		cout << "\tDoc: ";
		cin >> x;
		cout << "\tNgang: ";
		cin >> y;
	}
}
void Diem::Xuat()
{
	cout << "(" << x << "," << y << ")";
}
void Diem::SetDiem(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Diem::GetX()
{
	return this->x;
}
int Diem::GetY()
{
	return this->y;
}
bool Diem::operator==(const Diem& temp)
{
	return ((this->x == temp.x) && (this->y == temp.y));
}