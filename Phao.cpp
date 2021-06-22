#include "Phao.h"
Phao::Phao()
{
	this->Index = 2;
}
void Phao::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân Pháo có 2 quân cùng màu
	//Tương ứng trọng số trong mảng quân cờ 5,6
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		if (pos == 5)
			temp.SetDiem(3, 2);
		else
			temp.SetDiem(3, 8);
	}
	else
	{
		if (pos == 5)
			temp.SetDiem(8, 2);
		else
			temp.SetDiem(8, 8);
	}
	this->DiemDangDung = temp;
}
Diem* Phao::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	//newDiem[17] là vì quân Pháo sẽ có 17 nước đi được nếu trên bàn cờ có 1 mình nó
	//17=8+9, 8 là các nước đi trên hàng ngang quân pháo đang đứng (x giữ nguyên, y thay đổi)
	//9 là các nước đi trên hàng dọc quân pháo đang đứng (x thay đổi, y giữ nguyên)
	Diem* a = new Diem[17];
	count = 0;
	//For số 1: lấy tọa độ các nước đi trên hàng ngang
	for (int i = 1; i <= 9; i++)
	{
		//!=i để loại bỏ tọa độ quân pháo đang đứng
		if (DiemDangDung.GetY() != i)
		{
			//count++ để tăng count lên
			a[count++].SetDiem(DiemDangDung.GetX(), i);
		}
	}
	//For số 2: lấy tọa độ các nước đi trên hàng dọc
	for (int i = 1; i <= 10; i++)
	{
		//!=i để loại bỏ tọa độ quân pháo đang đứng
		if (DiemDangDung.GetX() != i)
		{
			a[count++].SetDiem(i, DiemDangDung.GetY());
		}
	}
	//Trả về mảng a
	return a;
}
void Phao::CachDi()
{
	GoTo(22, 17);
	cout << "-Di ngang va doc giong nhu xe." << endl;
	cout << "|          |         |-Neu muon an quan, phao phai nhay qua dung 1   |" << endl;
	cout << "|          |         | quan nao do.                                  |" << endl;
	cout << "|          |         |-Khi khong an quan, tat ca nhung diem tu cho di|" << endl;
	cout << "|          |         | den cho den phai khong co quan can.           |" << endl;
	cout << "+----------+---------+-----------------------------------------------+" << endl;
}