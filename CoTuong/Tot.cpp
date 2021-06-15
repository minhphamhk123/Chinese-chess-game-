#include "Tot.h"
Tot::Tot()
{
	this->Index = 1;
}
void Tot::Create(int Type, int pos)
{
	//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
	//ở trường hợp quân tốt có 5 quân tốt cùng màu
	//Tương ứng trọng số trong mảng quân cờ 0,1,2,3,4
	//temp dùng để lưu trữ tọa độ của quân cờ
	Diem temp;
	if (Type == 1)
	{
		if (pos == 0)
			temp.SetDiem(4, 1);
		else if (pos == 1)
			temp.SetDiem(4, 3);
		else if (pos == 2)
			temp.SetDiem(4, 5);
		else if (pos == 3)
			temp.SetDiem(4, 7);
		else
			temp.SetDiem(4, 9);
	}
	else
	{
		if (pos == 0)
			temp.SetDiem(7, 1);
		else if (pos == 1)
			temp.SetDiem(7, 3);
		else if (pos == 2)
			temp.SetDiem(7, 5);
		else if (pos == 3)
			temp.SetDiem(7, 7);
		else
			temp.SetDiem(7, 9);
	}
	//gán temp cho điểm đang đứng
	this->DiemDangDung = temp;
}

Diem* Tot::ToaDoDiTheoLuat(int Type, int& count)
{
	//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
	//count truyền tham chiếu để lấy số phần tử của mảng a
	Diem* a;
	if (Type == 1)
	{
		//Type==1->Quan Trang
		if (DiemDangDung.GetX() < 6)
		{
			//x<6-> quân tốt chỉ có thể đi thẳng
			a = new Diem[1];
			a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY());
			count = 1;
		}
		else
		{
			//x>=6 quân tốt có thể đi thẳng hoặc trái hoặc phải
			a = new Diem[3];
			count = 3;
			a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY());
			a[1].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() + 1);
			a[2].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() - 1);
			int i = 2;
			//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
			//Ví dụ (0,1)->x=0 vượt ra khỏi bàn cờ
			while (i >= 0 && count >= 0)
			{
				if (a[i].GetY() < 1 || a[i].GetX() > 10 || a[i].GetY() > 9)
				{
					if (i != count - 1)
						for (int j = i; j < count - 1; j++)
							a[j] = a[j + 1];
					count--;
				}
				i--;
			}
		}
	}
	else
	{
		//Ngược với Type==1 ->Quan Đen
		//Phần code dưới đây tương tự như Quân Trắng ở Type==1
		if (DiemDangDung.GetX() > 5)
		{
			a = new Diem[1];
			a[0].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY());
			count = 1;
		}
		else
		{
			a = new Diem[3];
			count = 3;
			a[0].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY());
			a[1].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() + 1);
			a[2].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() - 1);
			int i = 2;
			while (i >= 0 && count >= 0)
			{
				if (a[i].GetY() < 1 || a[i].GetX() < 1 || a[i].GetY() > 9)
				{
					if (i != count - 1)
						for (int j = i; j < count - 1; j++)
							a[j] = a[j + 1];
					count--;
				}
				i--;
			}
		}
	}
	//trả về mảng a 
	return a;
}

void Tot::CachDi()
{
	cout << "Tot: -Di mot o moi nuoc." << endl;
	cout << "     -Neu tot chua vuot qua song, no chi co the di thang tien." << endl;
	cout << "     -Khi da vuot song roi, tot co the di ngang 1 nuoc hay di thang tien 1 buoc moi nuoc." << endl;
}