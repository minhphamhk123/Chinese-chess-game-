#include "Si.h"

Si::Si()
{
	this->Index = 6;
}

void Si::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Sĩ có 2 quân cùng màu
	//Tương ứng trọng số trong mảng quân cờ 13,14
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		if (pos == 13)
			temp.SetDiem(1, 4);
		else
			temp.SetDiem(1, 6);
	}
	else
	{
		if (pos == 13)
			temp.SetDiem(10, 4);
		else
			temp.SetDiem(10, 6);
	}
	this->DiemDangDung = temp;
}

Diem* Si::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[4] là vì quân Sĩ sẽ có 4 nước đi được nếu trên bàn cờ có 1 mình nó
	//4=1+1+1+1: gồm 1 chéo phải-trên, 1 chéo phải-dưới, 1 chéo trái-trên, 1 chéo trái-dưới
	//Phần code dưới đây cũng tương tự như quân Tượng
	Diem* a = new Diem[4];
	count = 4;
	a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY() + 1);
	a[1].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY() - 1);
	a[2].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY() + 1);
	a[3].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY() - 1);
	int i = 3;
	if (Type == 1)
	{
		while (i >= 0 && count >= 0)
		{
			if (a[i].GetX() < 1 || a[i].GetY() < 4 || a[i].GetX() > 3 || a[i].GetY() > 6)
			{
				if (i != count - 1)
					for (int j = i; j < count - 1; j++)
						a[j] = a[j + 1];
				count--;
			}
			i--;
		}
	}
	else
	{
		while (i >= 0 && count >= 0)
		{
			if (a[i].GetX() < 8 || a[i].GetX() > 10 || a[i].GetY() < 4 || a[i].GetY() > 6)
			{
				if (i != count - 1)
					for (int j = i; j < count - 1; j++)
						a[j] = a[j + 1];
				count--;
			}
			i--;
		}
	}
	return a;
}

void Si::CachDi()
{
	cout << "Si: -Di xeo 1 o moi nuoc." << endl;
	cout << "    -Si luon luon phai o trong cung nhu Tuong'." << endl;
}