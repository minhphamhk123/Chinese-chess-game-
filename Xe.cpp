#include "Xe.h"
Xe::Xe()
{
	this->Index = 3;
}
void Xe::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Xe có 2 quân cùng màu
	//Tương ứng trọng số trong mảng quân cờ 7,8
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		//Type==1->Quân Trắng
		if (pos == 7)
			temp.SetDiem(1, 1);
		else
			temp.SetDiem(1, 9);
	}
	else
	{
		//Ngược lại Type==1 ->Quân Đen
		if (pos == 7)
			temp.SetDiem(10, 1);
		else
			temp.SetDiem(10, 9);
	}
	this->DiemDangDung = temp;
}
Diem* Xe::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[17] là vì quân Xe sẽ có 17 nước đi được nếu trên bàn cờ có 1 mình nó
	//17=8+9, 8 là các nước đi trên hàng ngang quân pháo đang đứng (x giữ nguyên, y thay đổi)
	//9 là các nước đi trên hàng dọc quân pháo đang đứng (x thay đổi, y giữ nguyên)
	//Phần code dưới đây ý nghĩa tương tự như quân Pháo
	Diem* a = new Diem[17];
	count = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (DiemDangDung.GetY() != i)
		{
			a[count++].SetDiem(DiemDangDung.GetX(), i);
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		if (DiemDangDung.GetX() != i)
		{
			a[count++].SetDiem(i, DiemDangDung.GetY());
		}
	}
	return a;
}
void Xe::CachDi()
{
	GoTo(22, 17);
	cout << "-Di ngang hay doc tren ban co mien la dung bi" << endl;
	cout << "|          |         | quan khac can duong tu diem di den diem den.  |" << endl;
	cout << "+----------+---------+-----------------------------------------------+" << endl;
}