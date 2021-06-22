#include "_Tuong_.h"


_Tuong_::_Tuong_()
{
	this->Index = 7;
}

void _Tuong_::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Tướng có 1 quân 
	//Tương ứng trọng số trong mảng quân cờ 15
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
		temp.SetDiem(1, 5);
	else
		temp.SetDiem(10, 5);
	this->DiemDangDung = temp;
}

Diem* _Tuong_::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[4] là vì quân Tướng sẽ có 4 nước đi được nếu trên bàn cờ có 1 mình nó
	//4=1+1+1+1: gồm 1 đi thẳng, 1 đi qua trái, 1 đi qua phải, 1 đi lui
	Diem* a = new Diem[4];
	count = 4;
	a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY());
	a[1].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY());
	a[2].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() + 1);
	a[3].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() - 1);
	if (Type == 1)
	{
		//Type==1->Quân Trắng
		//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
		for (int i = 0; i < 4; i++)
		{
			if (a[i].GetX() < 1 || a[i].GetY() < 4 || a[i].GetX() > 3 || a[i].GetY() > 6)
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
			if (a[i].GetX() < 8 || a[i].GetX() > 10 || a[i].GetY() < 4 || a[i].GetY() > 6)
			{
				a[i].SetDiem(-1, -1);
			}
		}
	}
	return a;
}

void _Tuong_::CachDi()
{
	GoTo(22, 17);
	cout << "-Di tung o mot, ngang hoac doc." << endl;
	cout << "|          |         |-Luon phai o trong pham vi cung va khong duoc  |" << endl;
	cout << "|          |         | ra ngoai. Cung tuc la hinh vuong 2x2 duoc danh|" << endl;
	cout << "|          |         | dau bang duong cheo hinh chu X.               |" << endl;
	cout << "+----------+---------+-----------------------------------------------+" << endl;
}