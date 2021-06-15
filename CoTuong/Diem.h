#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

class Diem
{
private:
	int x;
	int y;
public:
	Diem();
	Diem(int x, int y);
	Diem(const Diem& temp);
	Diem& operator=(const Diem& temp);
	~Diem();
	void Nhap();
	void Xuat();
	void SetDiem(int x, int y);
	int GetX();
	int GetY();
	bool operator==(const Diem& temp);
};