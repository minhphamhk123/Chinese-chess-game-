#include "Tuong.h"
Tuong::Tuong()
{
	this->Index = 5;
}
void Tuong::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Tượng có 2 quân cùng màu
	//Tương ứng trọng số trong mảng quân cờ 11,12
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		if (pos == 11)
			temp.SetDiem(1, 3);
		else
			temp.SetDiem(1, 7);
	}
	else
	{
		if (pos == 11)
			temp.SetDiem(10, 3);
		else
			temp.SetDiem(10, 7);
	}
	this->DiemDangDung = temp;
}
Diem* Tuong::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[4] là vì quân Tượng sẽ có 4 nước đi được nếu trên bàn cờ có 1 mình nó
	//4=1+1+1+1: gồm 1 chéo phải-trên, 1 chéo phải-dưới, 1 chéo trái-trên, 1 chéo trái-dưới
	Diem* a = new Diem[4];
	count = 4;
	a[0].SetDiem(DiemDangDung.GetX() + 2, DiemDangDung.GetY() + 2);
	a[1].SetDiem(DiemDangDung.GetX() + 2, DiemDangDung.GetY() - 2);
	a[2].SetDiem(DiemDangDung.GetX() - 2, DiemDangDung.GetY() + 2);
	a[3].SetDiem(DiemDangDung.GetX() - 2, DiemDangDung.GetY() - 2);
	if (Type == 1)
	{
		//Type==1->Quân Trắng
		//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
		for (int i = 0; i < 4; i++)
		{
			if (a[i].GetX() < 1 || a[i].GetY() < 1 || a[i].GetX() > 5 || a[i].GetY() > 9)
			{
				a[i].SetDiem(-1, -1);
			}
		}
	}
	else
	{
		//Ngược lại Type==1->Quân Đen
		//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
		for (int i = 0; i < 4; i++)
		{
			if (a[i].GetX() < 6 || a[i].GetX() > 10 || a[i].GetY() < 1 || a[i].GetY() > 9)
			{
				a[i].SetDiem(-1, -1);
			}
		}
	}
	return a;
}
void Tuong::CachDi()
{
	GoTo(22, 17);
	cout << "-Di cheo 2 o (ngang 2 & doc 2) cho moi nuoc di." << endl;
	cout << "|          |         |-Tuong chi duoc phep o mot ben cua ban co,     |" << endl;
	cout << "|          |         | khong duoc di chuyen sang nua ban co cua doi  |" << endl;
	cout << "|          |         | phuong.                                       |" << endl;
	cout << "|          |         |-Nuoc di cua tuong se khong hop le khi co mot  |" << endl;
	cout << "|          |         | quan co nam chan giua duong di.               |" << endl;
	cout << "+----------+---------+-----------------------------------------------+" << endl;
}