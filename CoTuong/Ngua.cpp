#include "Ngua.h"

Ngua::Ngua()
{
	this->Index = 4;
}

void Ngua::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Ngựa có 2 quân cùng màu
	//Tương ứng trọng số trong mảng quân cờ 9,10
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		if (pos == 9)
			temp.SetDiem(1, 2);
		else
			temp.SetDiem(1, 8);
	}
	else
	{
		if (pos == 9)
			temp.SetDiem(10, 2);
		else
			temp.SetDiem(10, 8);
	}
	this->DiemDangDung = temp;
}

Diem* Ngua::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[8] là vì quân Ngựa sẽ có 8 nước đi được nếu trên bàn cờ có 1 mình nó
	//8=2+2+2+2: gồm 2 chéo trên, 2 chéo phải, 2 chéo trái, 2 chéo dưới
	Diem* a = new Diem[8];
	count = 8;
	a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY() + 2);
	a[1].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY() - 2);
	a[2].SetDiem(DiemDangDung.GetX() + 2, DiemDangDung.GetY() + 1);
	a[3].SetDiem(DiemDangDung.GetX() + 2, DiemDangDung.GetY() - 1);
	a[4].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY() + 2);
	a[5].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY() - 2);
	a[6].SetDiem(DiemDangDung.GetX() - 2, DiemDangDung.GetY() + 1);
	a[7].SetDiem(DiemDangDung.GetX() - 2, DiemDangDung.GetY() - 1);

	int i = 7;
	//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
	while (i >= 0 && count >= 0)
	{
		if (a[i].GetX() < 1 || a[i].GetY() < 1 || a[i].GetX() > 10 || a[i].GetY() > 9)
		{
			if (i != count - 1)
				for (int j = i; j < count - 1; j++)
					a[j] = a[j + 1];
			count--;
		}
		i--;
	}
	return a;
}

void Ngua::CachDi()
{
	cout << "Ngua: -Di ngang 2 o va doc 1 o (hay doc 2 o va ngang 1 o) cho moi nuoc di." << endl;
	cout << "      -Neu co quan nam ngay ben canh ma va can duong ngang 2 (hay duong doc 2)," << endl;
	cout << "       ma bi can khong duoc di duong do." << endl;
}