#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

//MAX=16 vì mỗi bên có 16 quân
constexpr auto MAX = 16;

//Type: 1 là Trắng, ngược lại là Đen
//Index: 1-Tốt, 2-Pháo, 3-Xe, 4-Ngựa, 5-Tượng, 6-Sĩ, 7-Tướng

class Diem
{
private:
	int x;
	int y;
public:
	Diem()
	{
		x = y = -1;
	}
	Diem(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Diem(const Diem& temp)
	{
		x = temp.x;
		y = temp.y;
	}
	Diem& operator=(const Diem& temp)
	{
		x = temp.x;
		y = temp.y;
		return *this;
	}
	~Diem() {}
	void Nhap()
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
	void Xuat()
	{
		cout << "(" << x << "," << y << ")";
	}
	void SetDiem(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int GetX()
	{
		return this->x;
	}
	int GetY()
	{
		return this->y;
	}
	bool operator==(const Diem& temp)
	{
		return ((this->x == temp.x) && (this->y == temp.y));
	}
};

class QuanCo
{
protected:
	int Index;
	Diem DiemDangDung;
public:
	QuanCo()
	{
		Index = -1;
	}
	QuanCo(const QuanCo& temp)
	{
		Index = temp.Index;
		DiemDangDung = temp.DiemDangDung;
	}
	QuanCo& operator=(const QuanCo& temp)
	{
		Index = temp.Index;
		DiemDangDung = temp.DiemDangDung;
		return *this;
	}
	~QuanCo() {}

	virtual Diem* ToaDoDiTheoLuat(int Type,int &count) = 0;
	virtual void Create(int Type, int pos) = 0;
	virtual void CachDi() = 0;

	int GetIndex()
	{
		return this->Index;
	}

	void SetIndex(int temp)
	{
		this->Index = temp;
	}

	Diem GetDiemDangDung()
	{
		return this->DiemDangDung;
	}

	void SetDiemDangDung(int x,int y)
	{
		this->DiemDangDung.SetDiem(x, y);
	}
};

class Tot :public QuanCo
{
public:
	Tot()
	{
		this->Index = 1;
	}

	void Create(int Type,int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
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
				a[0].SetDiem(DiemDangDung.GetX() -1, DiemDangDung.GetY());
				a[1].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() + 1);
				a[2].SetDiem(DiemDangDung.GetX(), DiemDangDung.GetY() - 1);
				int i = 2;
				while (i >= 0 && count >= 0)
				{
					if (a[i].GetY() < 1 || a[i].GetX() <1 || a[i].GetY() > 9)
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

	void CachDi()
	{
		cout << "Tot: -Di mot o moi nuoc." << endl;
		cout << "     -Neu tot chua vuot qua song, no chi co the di thang tien." << endl;
		cout << "     -Khi da vuot song roi, tot co the di ngang 1 nuoc hay di thang tien 1 buoc moi nuoc." << endl;
	}
};

class Phao :public QuanCo
{
public:
	Phao()
	{
		this->Index = 2;
	}

	void Create(int Type, int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
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

	void CachDi()
	{
		cout << "Phao: -Di ngang va doc giong nhu xe." << endl;
		cout << "      -Neu muon an quan, phao phai nhay qua dung 1 quan nao do." << endl;
		cout << "      -Khi khong an quan, tat ca nhung diem tu cho di den cho den phai khong co quan can." << endl;
	}
};

class Xe :public QuanCo
{
public:
	Xe()
	{
		this->Index = 3;
	}

	void Create(int Type, int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
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

	void CachDi()
	{
		cout << "Xe: -Di ngang hay doc tren ban co mien la dung bi " << endl;
		cout << "     quan khac can duong tu diem di den diem den." << endl;
	}
};

class Ngua :public QuanCo
{
public:
	Ngua()
	{
		this->Index = 4;
	}

	void Create(int Type, int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
	{
		//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
		//count truyền tham chiếu để lấy số phần tử của mảng a
		//newDiem[8] là vì quân Ngựa sẽ có 8 nước đi được nếu trên bàn cờ có 1 mình nó
		//8=2+2+2+2: gồm 2 chéo trên, 2 chéo phải, 2 chéo trái, 2 chéo dưới
		Diem* a = new Diem[8];
		count = 8;
		a[0].SetDiem(DiemDangDung.GetX()+1, DiemDangDung.GetY()+2);
		a[1].SetDiem(DiemDangDung.GetX()+1, DiemDangDung.GetY()-2);
		a[2].SetDiem(DiemDangDung.GetX()+2, DiemDangDung.GetY()+1);
		a[3].SetDiem(DiemDangDung.GetX()+2, DiemDangDung.GetY()-1);
		a[4].SetDiem(DiemDangDung.GetX()-1, DiemDangDung.GetY()+2);
		a[5].SetDiem(DiemDangDung.GetX()-1, DiemDangDung.GetY()-2);
		a[6].SetDiem(DiemDangDung.GetX()-2, DiemDangDung.GetY()+1);
		a[7].SetDiem(DiemDangDung.GetX()-2, DiemDangDung.GetY()-1);

		int i = 7;
		//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
		while (i >= 0 && count >= 0)
		{
			if (a[i].GetX() < 1 || a[i].GetY() < 1||a[i].GetX()>10||a[i].GetY()>9)
			{
				if (i != count-1)
					for (int j = i; j < count - 1; j++)
						a[j] = a[j + 1];
				count--;
			}
			i--;
		}
		return a;
	}

	void CachDi()
	{
		cout << "Ngua: -Di ngang 2 o va doc 1 o (hay doc 2 o va ngang 1 o) cho moi nuoc di." << endl;
		cout << "      -Neu co quan nam ngay ben canh ma va can duong ngang 2 (hay duong doc 2)," << endl;
		cout << "       ma bi can khong duoc di duong do." << endl;
	}
};

class Tuong :public QuanCo
{
	//Quân Tượng nha.
public:
	Tuong()
	{
		this->Index = 5;
	}

	void Create(int Type, int pos)
	{
		//Type chỉ màu quân cờ, pos chỉ thứ tự quân cờ
		//ở trường hợp quân Tượng có 2 quân cùng màu
		//Tương ứng trọng số trong mảng quân cờ 11,12
		//temp dùng để lưu trữ tọa độ của quân cờ
		Diem temp;
		if (Type == 1)
		{
			if (pos ==11)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
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
		int i = 3;
		if (Type == 1)
		{
			//Type==1->Quân Trắng
			//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
			while (i >= 0 && count >= 0)
			{
				if (a[i].GetX() < 1 || a[i].GetY() < 1 || a[i].GetX()>5||a[i].GetY()>9)
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
			//Ngược lại Type==1->Quân Đen
			//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
			while (i >= 0 && count >= 0)
			{
				if (a[i].GetX() <6||a[i].GetX()>10 || a[i].GetY() < 1 || a[i].GetY()>9)
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

	void CachDi()
	{
		cout << "Tuong: -Di cheo 2 o (ngang 2 va doc 2) cho moi nuoc di." << endl;
		cout << "      -Tuong chi duoc phep o mot ben cua ban co, khong duoc di" << endl;
		cout << "       chuyen sang nua ban co cua doi phuong." << endl;
		cout << "      -Nuoc di cua tuong se khong hop le khi co mot quan co nam chan " << endl;
		cout << "       giua duong di." << endl;
	}
};

class Si :public QuanCo
{
public:
	Si()
	{
		this->Index = 6;
	}

	void Create(int Type, int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
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

	void CachDi()
	{
		cout << "Si: -Di xeo 1 o moi nuoc." << endl;
		cout << "    -Si luon luon phai o trong cung nhu Tuong'." << endl;
	}
};

class _Tuong_ :public QuanCo
{
	//Quân Tướng nha.
public:
	_Tuong_()
	{
		this->Index = 7;
	}

	void Create(int Type, int pos)
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

	Diem* ToaDoDiTheoLuat(int Type, int& count)
	{
		//Mảng a lưu trữ những tọa độ quân cờ đi được trong trường hợp trên bàn cờ chỉ có 1 mình nó.
		//count truyền tham chiếu để lấy số phần tử của mảng a
		//newDiem[4] là vì quân Tướng sẽ có 4 nước đi được nếu trên bàn cờ có 1 mình nó
		//4=1+1+1+1: gồm 1 đi thẳng, 1 đi qua trái, 1 đi qua phải, 1 đi lui
		Diem* a = new Diem[4];
		count = 4;
		a[0].SetDiem(DiemDangDung.GetX() + 1, DiemDangDung.GetY());
		a[1].SetDiem(DiemDangDung.GetX() - 1, DiemDangDung.GetY());
		a[2].SetDiem(DiemDangDung.GetX() , DiemDangDung.GetY() + 1);
		a[3].SetDiem(DiemDangDung.GetX() , DiemDangDung.GetY() - 1);
		int i = 3;
		if (Type == 1)
		{
			//Type==1->Quân Trắng
			//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
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
			//Ngược lại Type==1->Quân Đen
			//vòng while có tác dụng loại bỏ những điểm tọa độ vượt ra khỏi bàn cờ. 
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

	void CachDi()
	{
		cout << "Tuong': -Di tung o mot, ngang hoac doc." << endl;
		cout << "		 -Luon phai o trong pham vi cung va khong duoc ra ngoai." << endl;
		cout << "        Cung tuc la hinh vuong 2x2 duoc danh dau bang duong cheo hinh chu X." << endl;
	}
};

class Player
{
private:
	QuanCo** Trang;
	QuanCo** Den;
public:
	Player()
	{
		Trang = NULL;
		Den = NULL;
	}
	Player(const Player& temp)
	{
		Trang = new QuanCo * [MAX];
		Den = new QuanCo * [MAX];
		for (int i = 0; i < MAX; i++)
		{
			if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4)
			{
				Trang[i] = new Tot;
				Den[i] = new Tot;
			}
			else if (i == 5 || i == 6)
			{
				Trang[i] = new Phao;
				Den[i] = new Phao;
			}
			else if (i == 7 || i == 8)
			{
				Trang[i] = new Xe;
				Den[i] = new Xe;
			}
			else if (i == 9 || i == 10)
			{
				Trang[i] = new Ngua;
				Den[i] = new Ngua;
			}
			else if (i == 11 || i == 12)
			{
				Trang[i] = new Tuong;
				Den[i] = new Tuong;
			}
			else if (i == 13 || i == 14)
			{
				Trang[i] = new Si;
				Den[i] = new Si;
			}
			else
			{
				Trang[i] = new _Tuong_;
				Den[i] = new _Tuong_;
			}
			*(Trang[i]) = *(temp.Trang[i]);
			*(Den[i]) = *(temp.Den[i]);
		}
	}
	Player& operator=(const Player& temp)
	{
		Trang = new QuanCo * [MAX];
		Den = new QuanCo * [MAX];
		for (int i = 0; i < MAX; i++)
		{
			if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4)
			{
				Trang[i] = new Tot;
				Den[i] = new Tot;
			}
			else if (i == 5 || i == 6)
			{
				Trang[i] = new Phao;
				Den[i] = new Phao;
			}
			else if (i == 7 || i == 8)
			{
				Trang[i] = new Xe;
				Den[i] = new Xe;
			}
			else if (i == 9 || i == 10)
			{
				Trang[i] = new Ngua;
				Den[i] = new Ngua;
			}
			else if (i == 11 || i == 12)
			{
				Trang[i] = new Tuong;
				Den[i] = new Tuong;
			}
			else if (i == 13 || i == 14)
			{
				Trang[i] = new Si;
				Den[i] = new Si;
			}
			else
			{
				Trang[i] = new _Tuong_;
				Den[i] = new _Tuong_;
			}
			*(Trang[i]) = *(temp.Trang[i]);
			*(Den[i]) = *(temp.Den[i]);
		}
		return *this;
	}
	~Player()
	{
		if (Trang != NULL)
		{
			for (int i = 0; i < MAX; i++)
				delete Trang[i];
			delete[]Trang;
		}
		if (Den != NULL)
		{
			for (int i = 0; i < MAX; i++)
				delete Den[i];
			delete[]Den;
		}
	}

	void KhoiTaoBanCo()
	{
		//Dễ hiểu!
		Trang = new QuanCo * [MAX];
		Den = new QuanCo * [MAX];
		for (int i = 0; i < MAX; i++)
		{
			if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4)
			{
				Trang[i] = new Tot;
				Den[i] = new Tot;
			}
			else if (i == 5 || i == 6)
			{
				Trang[i] = new Phao;
				Den[i] = new Phao;
			}
			else if (i == 7 || i == 8)
			{
				Trang[i] = new Xe;
				Den[i] = new Xe;
			}
			else if (i == 9 || i == 10)
			{
				Trang[i] = new Ngua;
				Den[i] = new Ngua;
			}
			else if (i == 11 || i == 12)
			{
				Trang[i] = new Tuong;
				Den[i] = new Tuong;
			}
			else if (i == 13 || i == 14)
			{
				Trang[i] = new Si;
				Den[i] = new Si;
			}
			else
			{
				Trang[i] = new _Tuong_;
				Den[i] = new _Tuong_;
			}
			Trang[i]->Create(1, i);
			Den[i]->Create(2, i);
		}
	}
	
	int TonTaiLoaiQuanCoTrenBanCo( int Type,int Index)
	{
		//Type, Index được truyền tham trị vào
		//Hàm trả về trọng số của quân cờ thuộc 1 trong 2 mảng khai báo ở private 
		//Đó là quân cờ ĐẦU TIÊN có màu là xác định thông qua Type, và Quân cờ có Index
		//Ví dụ 5 Quân tốt Trắng có các trọng số là: 0,1,2,3,4 và tất cả 5 quân đều có Index=1
		//Cho Type=1 và Index=1
		//Hàm sẽ trả về i=0;
		//Ngược lại nếu không còn tồn tại quân tốt Trắng nào thì return -1
		if (Type == 1)
		{
			for (int i = 0; i < MAX; i++)
				if (Index == Trang[i]->GetIndex())
					return i;
		}
		else
		{
			for (int i = 0; i < MAX; i++)
				if (Index == Den[i]->GetIndex())
					return i;
		}
		return -1;
	}

	int KiemTraToaDoCoTrongMang(Diem* a, int n, Diem temp)
	{
		//Hàm kiểm tra 1 tọa độ bất kì có tồn tại trong mảng được truyền vào hay không?
		//Có -> return trọng số tọa độ đó trong mảng
		//Không-> return -1
		//Mảng a lưu trữ các tọa độ, được truyền tham chiếu
		//n là số phần tử của mảng a, được truyền tham chiếu
		//Temp lưu trữ một tọa độ, được truyền tham chiếu
		for (int i = 0; i < n; i++)
		{
			if (a[i] == temp)
				return i;
		}
		return -1;
	}

	int KiemTraTrangThaiToaDo(Diem temp)
	{
		//Hàm kiểm tra trạng thái của một tọa độ bất kì
		//return 1. Nếu tọa độ đó đang được một quân cờ Trắng nắm giữ.
		//return 2. Nếu tọa độ đó đang được một quân cờ Đen nắm giữ
		//return 0. Nếu tọa độ không bị quân cờ nào nắm giữ
		for (int i = 0; i < MAX; i++)
		{
			if (temp == Trang[i]->GetDiemDangDung())
				return 1;
			else if (temp == Den[i]->GetDiemDangDung())
				return 2;
		}
		return 0;
	}

	int KiemTraToaDoQuanMuonDi(int Type,Diem MuonDi, int Index)
	{
		//Hàm kiểm tra tọa độ quân cờ muốn đi có hợp lệ hay không?
		//Hợp lệ->return trọng số của quân cờ đó thuộc 1 trong 2 mảng khai báo ở Private
		//Ngược lại-> return -1
		for (int i = 0; i < MAX; i++)
		{
			if (Type == 1)
			{
				if (Index == Trang[i]->GetIndex() && MuonDi == Trang[i]->GetDiemDangDung())
					return i;
			}
			else
			{
				if (Index == Den[i]->GetIndex() && MuonDi == Den[i]->GetDiemDangDung())
					return i;
			}
		}
		return -1;
	}

	bool XuatCacNuocCoTheDi(int Type, Diem*& a, int n)
	{
		//Hàm xuất các nước có thể đi của quân muốn đi
		//Type được xác định là màu của quân muốn đi
		//Mảng a chứa các tọa độ có thể đi được của quân muốn đi khi trên bàn cờ có 1 mình nó
		//n là số phần tử của mảng a
		bool flag = 0;
		cout << "Cac nuoc co the di:" << endl;
		//vòng for duyệt từng tọa độ trong mảng a
		for (int i = 0; i < n; i++)
		{
			if (Type == 1)
			{
				//Type==1->Quân Trắng
				//a[i] là quân trắng đang nắm giữ -> continue
				if (KiemTraTrangThaiToaDo(a[i]) == 1 && a[i].GetX() != -1 && a[i].GetY() != -1)
					continue;
				//a[i] là quân đen đang nắm giữ -> có thể ăn quân ở a[i]
				else if (KiemTraTrangThaiToaDo(a[i]) == 2 && a[i].GetX() != -1 && a[i].GetY() != -1)
				{
					flag = 1;
					cout << "-An quan o vi tri:      ";
					a[i].Xuat();
					cout << endl;
				}
				//a[i] hiện không có quân nào đang nắm giữ -> có thể di chuyển tới a[i]
				else if (KiemTraTrangThaiToaDo(a[i]) == 0 && a[i].GetX() != -1 && a[i].GetY() != -1)
				{
					flag = 1;
					cout << "-Di chuyen toi vi tri:  ";
					a[i].Xuat();
					cout << endl;
				}
			}
			else
			{
				//Ngược lại Type==1->Quân Đen
				//a[i] là quân đen đang nắm giữ -> continue
				if (KiemTraTrangThaiToaDo(a[i]) == 2 && a[i].GetX() != -1 && a[i].GetY() != -1)
					continue;
				//a[i] là quân trắng đang nắm giữ -> có thể ăn quân ở a[i]
				else if (KiemTraTrangThaiToaDo(a[i]) == 1 && a[i].GetX() != -1 && a[i].GetY() != -1)
				{
					flag = 1;
					cout << "-An quan o vi tri:      ";
					a[i].Xuat();
					cout << endl;
				}
				//a[i] hiện không có quân nào đang nắm giữ -> có thể di chuyển tới a[i]
				else if (KiemTraTrangThaiToaDo(a[i]) == 0 && a[i].GetX() != -1 && a[i].GetY() != -1)
				{
					flag = 1;
					cout << "-Di chuyen toi vi tri:  ";
					a[i].Xuat();
					cout << endl;
				}
			}
		}
		if (flag == 0)
			cout << "-Khong co." << endl;
		return flag;
	}

	void LoaiCacNuocDiRoiVaoTruongHopDacBiet(int Type, QuanCo* MuonDi, Diem*& a, int n)
	{
		//Mảng a chứa các tọa độ có thể đi được của quân Muốn đi khi trên bàn cờ có 1 mình nó
		//n là số phần tử của mảng a
		//Hàm này sẽ loại bỏ các tọa độ trong mảng a mà vi phạm luật chơi
		Diem temp = MuonDi->GetDiemDangDung();
		//temp giữ tọa độ của quân muốn đi
		
		//Quân Tốt
		if (MuonDi->GetIndex() == 1)
		{
			//Vòng for duyệt từng tọa độ trong mảng a
			for (int i = 0; i < n; i++)
			{
				if (Type == 1)
				{
					//Type==1->Quân muốn đi có màu Trắng
					//a[i] đang được quân Trắng nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 1)
						a[i].SetDiem(-1, -1);
				}
				else
				{
					//Ngược lại Type==1->Quân muốn đi có màu Đen
					//a[i] đang được quân Đen nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 2)
						a[i].SetDiem(-1, -1);
				}
			}
		}
		//Quân Pháo
		if (MuonDi->GetIndex() == 2)
		{
			//Ben Phai của quân Pháo muốn đi
			for (int j = temp.GetY() + 1; j <= 9; j++)
			{
				//Vòng for có biến j đại diện cho trục y(ngang) từ vị trí kề bên phải của quân muốn đi đến 9
				//BenPhaiDauTien giữ từng tọa độ bên phải của quân muốn đi
				Diem BenPhaiDauTien(temp.GetX(), j);
				if (KiemTraTrangThaiToaDo(BenPhaiDauTien) == 1 || KiemTraTrangThaiToaDo(BenPhaiDauTien) == 2)
				{
					//Thỏa được if này -> bên phải quân muốn đi có quân cản đường(BenPhaiDauTien)
					//Vòng for có biến z đại diện cho trục y(ngang) từ vị trí kề bên phải của quân cản đường đến 9
					for (int z = BenPhaiDauTien.GetY() + 1; z <= 9; z++)
					{
						//CoTheBiAn giữ từng tọa độ bên phải của quân cản đường
						Diem CoTheBiAn(temp.GetX(), z);
						if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						{
							//Thỏa được if này -> bên phải quân cản đường có tồn tại 1 quân cờ khác(CoTheBiAn)
							//Vòng for để set toàn bộ những tọa độ bên phải của quân cờ khác = (-1,-1)
							for (int k = CoTheBiAn.GetY() + 1; k <= 9; k++)
							{
								Diem BenPhai(temp.GetX(), k);
								a[KiemTraToaDoCoTrongMang(a, n, BenPhai)].SetDiem(-1, -1);
							}
							//Type==1-> Quân muốn đi màu Trắng
							//Quân CoTheBiAn màu trắng->set CoTheBiAn = (-1,-1)
							if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							//Type==2-> Quân muốn đi màu Đen
							//Quân CoTheBiAn màu đen->set CoTheBiAn = (-1,-1)
							if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);

							break;
						}
						else
							//Ngược lại không tồn tại 1 quân cờ khác(CoTheBiAn)->set CoTheBiAn=(-1,-1)
							a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					}
					//set quân cản đường(BenPhaiDauTien) = (-1,-1)
					a[KiemTraToaDoCoTrongMang(a, n, BenPhaiDauTien)].SetDiem(-1, -1);
					break;
				}
			}

			//Ben Trai của quân Pháo muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetY() - 1; j >= 1; j--)
			{
				Diem BenTraiDauTien(temp.GetX(), j);
				if (KiemTraTrangThaiToaDo(BenTraiDauTien) == 1 || KiemTraTrangThaiToaDo(BenTraiDauTien) == 2)
				{
					for (int z = BenTraiDauTien.GetY() - 1; z >= 1; z--)
					{
						Diem CoTheBiAn(temp.GetX(), z);
						if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						{
							for (int k = CoTheBiAn.GetY() - 1; k >= 1; k--)
							{
								Diem BenTrai(temp.GetX(), k);
								a[KiemTraToaDoCoTrongMang(a, n, BenTrai)].SetDiem(-1, -1);
							}
							if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);

							break;
						}
						else
							a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					}
					a[KiemTraToaDoCoTrongMang(a, n, BenTraiDauTien)].SetDiem(-1, -1);
					break;
				}
			}

			//Phia Tren của quân Pháo muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetX() - 1; j >= 1; j--)
			{
				Diem PhiaTrenDauTien(j, temp.GetY());
				if (KiemTraTrangThaiToaDo(PhiaTrenDauTien) == 1 || KiemTraTrangThaiToaDo(PhiaTrenDauTien) == 2)
				{
					for (int z = PhiaTrenDauTien.GetX() - 1; z >= 1; z--)
					{
						Diem CoTheBiAn(z, temp.GetY());
						if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						{
							for (int k = CoTheBiAn.GetX() - 1; k >= 1; k--)
							{
								Diem PhiaTren(k, temp.GetY());
								a[KiemTraToaDoCoTrongMang(a, n, PhiaTren)].SetDiem(-1, -1);
							}
							if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							break;
						}
						else
						{
							a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
						}
					}
					a[KiemTraToaDoCoTrongMang(a, n, PhiaTrenDauTien)].SetDiem(-1, -1);
					break;
				}
			}

			//Phia Duoi của quân Pháo muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetX() + 1; j <= 10; j++)
			{
				Diem PhiaDuoiDauTien(j, temp.GetY());
				if (KiemTraTrangThaiToaDo(PhiaDuoiDauTien) == 1 || KiemTraTrangThaiToaDo(PhiaDuoiDauTien) == 2)
				{
					for (int z = PhiaDuoiDauTien.GetX() + 1; z <= 10; z++)
					{
						Diem CoTheBiAn(z, temp.GetY());
						if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						{
							for (int k = CoTheBiAn.GetX() + 1; k <= 10; k++)
							{
								Diem PhiaDuoi(k, temp.GetY());
								a[KiemTraToaDoCoTrongMang(a, n, PhiaDuoi)].SetDiem(-1, -1);
							}
							if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
								a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
							break;
						}
						else
						{
							a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
						}
					}
					a[KiemTraToaDoCoTrongMang(a, n, PhiaDuoiDauTien)].SetDiem(-1, -1);
					break;
				}
			}

		}
		//Quân Xe
		if (MuonDi->GetIndex() == 3)
		{
			//Ben Phai của quân Xe muốn đi
			for (int j = temp.GetY() + 1; j <= 9; j++)
			{
				//Vòng for có biến j đại diện cho trục y(ngang) từ vị trí kề bên phải của quân muốn đi đến 9
				//CoTheBiAn giữ từng tọa độ bên phải của quân muốn đi
				Diem CoTheBiAn(temp.GetX(), j);
				if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
				{
					//Thỏa được if này -> bên phải quân muốn đi có quân cản đường(CoTheBiAn)
					//Vòng for để set toàn bộ những tọa độ bên phải của quân cản đường(CoTheBiAn) = (-1,-1)
					for (int k = CoTheBiAn.GetY() + 1; k <= 9; k++)
					{
						Diem BenPhai(temp.GetX(), k);
						a[KiemTraToaDoCoTrongMang(a, n, BenPhai)].SetDiem(-1, -1);
					}
					//Type==1-> Quân muốn đi màu Trắng
					//Quân CoTheBiAn màu trắng->set CoTheBiAn = (-1,-1)
					if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					//Type==2-> Quân muốn đi màu Đen
					//Quân CoTheBiAn màu đen->set CoTheBiAn = (-1,-1)
					if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					break;
				}
			}

			//Ben Trai của quân Xe muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetY() - 1; j >= 1; j--)
			{
				Diem CoTheBiAn(temp.GetX(), j);
				if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
				{
					for (int k = CoTheBiAn.GetY() - 1; k >= 1; k--)
					{
						Diem BenTrai(temp.GetX(), k);
						a[KiemTraToaDoCoTrongMang(a, n, BenTrai)].SetDiem(-1, -1);
					}
					if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					break;
				}
			}

			//Phia Tren của quân Xe muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetX() - 1; j >= 1; j--)
			{
				Diem CoTheBiAn(j, temp.GetY());
				if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
				{
					for (int k = CoTheBiAn.GetX() - 1; k >= 1; k--)
					{
						Diem PhiaTren(k, temp.GetY());
						a[KiemTraToaDoCoTrongMang(a, n, PhiaTren)].SetDiem(-1, -1);
					}
					if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					break;
				}
			}

			//Phia Duoi của quân Xe muốn đi-Hướng suy nghĩ tượng tự như Ben Phai
			for (int j = temp.GetX() + 1; j <= 10; j++)
			{
				Diem CoTheBiAn(j, temp.GetY());
				if (KiemTraTrangThaiToaDo(CoTheBiAn) == 1 || KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
				{
					for (int k = CoTheBiAn.GetX() + 1; k <= 10; k++)
					{
						Diem PhiaDuoi(k, temp.GetY());
						a[KiemTraToaDoCoTrongMang(a, n, PhiaDuoi)].SetDiem(-1, -1);
					}
					if (Type == 1 && KiemTraTrangThaiToaDo(CoTheBiAn) == 1)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					if (Type == 2 && KiemTraTrangThaiToaDo(CoTheBiAn) == 2)
						a[KiemTraToaDoCoTrongMang(a, n, CoTheBiAn)].SetDiem(-1, -1);
					break;
				}
			}
		}
		//Quân Ngựa
		if (MuonDi->GetIndex() == 4)
		{
			//Vòng for duyệt từng tọa độ trong mảng a
			for (int i = 0; i < n; i++)
			{
				if (Type == 1)
				{
					//Type==1->Quan muốn đi có màu trắng
					//a[i] đang được quân Trắng nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 1)
						a[i].SetDiem(-1, -1);
				}
				else
				{
					//Ngược lại Type==1->Quan muốn đi có màu đen
					//a[i] đang được quân đen nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 2)
						a[i].SetDiem(-1, -1);
				}
			}

			Diem QuanCanDuong;

			//Kiểm tra tọa độ bên phải quân Muốn đi có quân nào đang giữ hay không?
			QuanCanDuong.SetDiem(temp.GetX(), temp.GetY() + 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				//Thỏa được if này -> bên phải quân muốn đi có quân cản đường
				Diem BenPhai;

				//BenPhai giữ tọa độ bên phải-dưới
				BenPhai.SetDiem(temp.GetX() + 1, temp.GetY() + 2);
				if (KiemTraToaDoCoTrongMang(a, n, BenPhai) != -1)
					//Lệnh if đảm bảo tìm thấy BenPhai trong mảng a
					//set BenPhai = (-1,-1)
					a[KiemTraToaDoCoTrongMang(a, n, BenPhai)].SetDiem(-1, -1);

				//BenPhai giữ tọa độ bên phải-trên
				BenPhai.SetDiem(temp.GetX() - 1, temp.GetY() + 2);
				if (KiemTraToaDoCoTrongMang(a, n, BenPhai) != -1)
					//Lệnh if đảm bảo tìm thấy BenPhai trong mảng a
					//set BenPhai = (-1,-1)
					a[KiemTraToaDoCoTrongMang(a, n, BenPhai)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ bên trái quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với bên phải
			QuanCanDuong.SetDiem(temp.GetX(), temp.GetY() - 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem BenTrai;

				BenTrai.SetDiem(temp.GetX() + 1, temp.GetY() - 2);
				if (KiemTraToaDoCoTrongMang(a, n, BenTrai) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, BenTrai)].SetDiem(-1, -1);
			
				BenTrai.SetDiem(temp.GetX() - 1, temp.GetY() - 2);
				if (KiemTraToaDoCoTrongMang(a, n, BenTrai) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, BenTrai)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ phía trên quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với bên phải
			QuanCanDuong.SetDiem(temp.GetX() - 1, temp.GetY());
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem PhiaTren;

				PhiaTren.SetDiem(temp.GetX() - 2, temp.GetY() + 1);
				if (KiemTraToaDoCoTrongMang(a, n, PhiaTren) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, PhiaTren)].SetDiem(-1, -1);

				PhiaTren.SetDiem(temp.GetX() - 2, temp.GetY() - 1);
				if (KiemTraToaDoCoTrongMang(a, n, PhiaTren) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, PhiaTren)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ phía dưới quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với bên phải
			QuanCanDuong.SetDiem(temp.GetX() + 1, temp.GetY());
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem PhiaDuoi;

				PhiaDuoi.SetDiem(temp.GetX() + 2, temp.GetY() + 1);
				if (KiemTraToaDoCoTrongMang(a, n, PhiaDuoi) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, PhiaDuoi)].SetDiem(-1, -1);

				PhiaDuoi.SetDiem(temp.GetX() + 2, temp.GetY() - 1);
				if (KiemTraToaDoCoTrongMang(a, n, PhiaDuoi) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, PhiaDuoi)].SetDiem(-1, -1);
			}

		}
		//Quân Tượng
		if (MuonDi->GetIndex() == 5)
		{
			//Vòng for duyệt từng tọa độ trong mảng a
			for (int i = 0; i < n; i++)
			{
				if (Type == 1)
				{
					//Type==1->Quan muốn đi có màu trắng
					//a[i] đang được quân Trắng nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 1)
						a[i].SetDiem(-1, -1);
				}
				else
				{
					//Ngược lại Type==1->Quan muốn đi có màu đen
					//a[i] đang được quân đen nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 2)
						a[i].SetDiem(-1, -1);
				}
			}

			Diem QuanCanDuong;

			//Kiểm tra tọa độ chéo phải-trên 1 đơn vị quân Muốn đi có quân nào đang giữ hay không?
			QuanCanDuong.SetDiem(temp.GetX() - 1, temp.GetY() + 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				//Thỏa được if này -> bên phải-trên 1 đơn vị quân muốn đi có quân cản đường
				Diem TrenPhai;
				//TrenPhai giữ tọa độ chéo phải-trên 2 đơn vị
				TrenPhai.SetDiem(temp.GetX() - 2, temp.GetY() + 2);
				if (KiemTraToaDoCoTrongMang(a, n, TrenPhai) != -1)
					//Lệnh if đảm bảo tìm thấy TrenPhai trong mảng a
					//set TrenPhai = (-1,-1)
					a[KiemTraToaDoCoTrongMang(a, n, TrenPhai)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ chéo trái-trên quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với chéo phải-trên 1 đơn vị
			QuanCanDuong.SetDiem(temp.GetX() - 1, temp.GetY() - 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem TrenTrai;

				TrenTrai.SetDiem(temp.GetX() - 2, temp.GetY() - 2);
				if (KiemTraToaDoCoTrongMang(a, n, TrenTrai) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, TrenTrai)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ chéo trái-dưới quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với chéo phải-trên 1 đơn vị
			QuanCanDuong.SetDiem(temp.GetX() + 1, temp.GetY() - 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem DuoiTrai;
				DuoiTrai.SetDiem(temp.GetX() + 2, temp.GetY() - 2);
				if (KiemTraToaDoCoTrongMang(a, n, DuoiTrai) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, DuoiTrai)].SetDiem(-1, -1);
			}

			//Kiểm tra tọa độ chéo phải-dưới quân Muốn đi có quân nào đang giữ hay không?
			//Hướng suy nghĩ tượng tự với chéo phải-trên 1 đơn vị
			QuanCanDuong.SetDiem(temp.GetX() + 1, temp.GetY() + 1);
			if (KiemTraTrangThaiToaDo(QuanCanDuong) == 1 || KiemTraTrangThaiToaDo(QuanCanDuong) == 2)
			{
				Diem DuoiPhai;

				DuoiPhai.SetDiem(temp.GetX() + 2, temp.GetY() + 2);
				if (KiemTraToaDoCoTrongMang(a, n, DuoiPhai) != -1)
					a[KiemTraToaDoCoTrongMang(a, n, DuoiPhai)].SetDiem(-1, -1);
			}

		}
		//Quân Sĩ
		if (MuonDi->GetIndex() == 6)
		{
			//Vòng for duyệt từng tọa độ trong mảng a
			for (int i = 0; i < n; i++)
			{
				if (Type == 1)
				{
					//Type==1->Quan muốn đi có màu trắng
					//a[i] đang được quân Trắng nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 1)
						a[i].SetDiem(-1, -1);
				}
				else
				{
					//Ngược lại Type==1->Quan muốn đi có màu đen
					//a[i] đang được quân đen nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 2)
						a[i].SetDiem(-1, -1);
				}
			}
		}
		//Quân Tướng
		if (MuonDi->GetIndex() == 7)
		{
			//Vòng for duyệt từng tọa độ trong mảng a
			for (int i = 0; i < n; i++)
			{
				if (Type == 1)
				{
					//Type==1->Quan muốn đi có màu trắng
					//a[i] đang được quân Trắng nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 1)
						a[i].SetDiem(-1, -1);
				}
				else
				{
					//Ngược lại Type==1->Quan muốn đi có màu đen
					//a[i] đang được quân đen nắm giữ -> set lại a[i] = (-1,-1)
					if (KiemTraTrangThaiToaDo(a[i]) == 2)
						a[i].SetDiem(-1, -1);
				}
			}
		}
	}

	bool KiemChieuTuong(int Type)
	{
		//Type là màu của quân đang đi
		//return 1-nếu bên đó bị chiếu tướng
		//ngược lại->return 0

		//King giữ tọa độ của Tướng thuộc bên đang đi
		Diem King;
		if (Type == 1)
			King = Trang[15]->GetDiemDangDung();
		else
			King = Den[15]->GetDiemDangDung();

		//Vòng for duyệt từng quân của mảng quân cờ của đối thủ đã khai báo ở private 
		//duyệt từ 0 đến 10: do tượng, sĩ, tướng ở phe đối thủ không thể chiếu tướng được
		for (int i = 0; i < MAX - 5; i++)
		{
			//SoPhanTuCuaMangToaDoTheoLuat là số phần tử của mảng MangToaDoTheoLuatCuaQuanDoiThu
			//MangToaDoTheoLuatCuaQuanDoiThu là mảng chứa các tọa độ có thể đi được của quân cờ[i] khi trên bàn cờ chỉ có 1 mình nó
			int SoPhanTuCuaMangToaDoTheoLuat;
			Diem* MangToaDoTheoLuatCuaQuanDoiThu;
			if (Type == 1)
			{
				//Type==1->Bên đang đi là màu trắng
				//MangToaDoTheoLuatCuaQuanDoiThu được khởi tạo
				//Gọi hàm LoaiCacNuocDiRoiVaoTruongHopDacBiet để loại những tọa độ phạm luật trong MangToaDoTheoLuatCuaQuanDoiThu
				MangToaDoTheoLuatCuaQuanDoiThu = Den[i]->ToaDoDiTheoLuat(Type, SoPhanTuCuaMangToaDoTheoLuat);
				LoaiCacNuocDiRoiVaoTruongHopDacBiet(2, Den[i], MangToaDoTheoLuatCuaQuanDoiThu, SoPhanTuCuaMangToaDoTheoLuat);
			}
			else
			{
				//Ngược lại Type==1->Bên đang đi là màu đen
				//MangToaDoTheoLuatCuaQuanDoiThu được khởi tạo
				//Gọi hàm LoaiCacNuocDiRoiVaoTruongHopDacBiet để loại những tọa độ phạm luật trong MangToaDoTheoLuatCuaQuanDoiThu
				MangToaDoTheoLuatCuaQuanDoiThu = Trang[i]->ToaDoDiTheoLuat(Type, SoPhanTuCuaMangToaDoTheoLuat);
				LoaiCacNuocDiRoiVaoTruongHopDacBiet(1, Trang[i], MangToaDoTheoLuatCuaQuanDoiThu, SoPhanTuCuaMangToaDoTheoLuat);
			}
			//vòng for duyệt tất cả các tọa độ trong MangToaDoTheoLuatCuaQuanDoiThu
			//nếu tìm thấy 1 phần tử bằng tọa độ của King -> return 1;
			for (int j = 0; j < SoPhanTuCuaMangToaDoTheoLuat; j++)
				if (MangToaDoTheoLuatCuaQuanDoiThu[j] == King)
					return 1;
		}
		return 0;
	}

	void VeBanCo()
	{
		//Khởi tạo mảng 2 chiều cấp phát động là mảng nền để vẽ bàn cờ
		char** draw = new char* [19];
		for (int i = 0; i < 19; i++)
			draw[i] = new char[41];

		//vòng for này để khởi tạo nên bàn cờ chưa có quân cờ nào.
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 41; j++)
			{
				if (i % 2 == 0)
				{
					if (j % 5 == 0)
						draw[i][j] = '+';
					else
						draw[i][j] = '-';
				}
				else if (i == 9)
				{
					if (j == 0 || j == 40)
						draw[i][j] = '|';
					else
						draw[i][j] = ' ';
				}
				else if (i == 1 || i == 15)
				{
					if (j == 17)
						draw[i][j] = '\\';
					else if (j == 23)
						draw[i][j] = '/';
					else if (j % 5 == 0)
						draw[i][j] = '|';
					else
						draw[i][j] = ' ';
				}
				else if (i == 3 || i == 17)
				{
					if (j == 17)
						draw[i][j] = '/';
					else if (j == 23)
						draw[i][j] = '\\';
					else if (j % 5 == 0)
						draw[i][j] = '|';
					else
						draw[i][j] = ' ';
				}
				else if (j % 5 == 0)
					draw[i][j] = '|';
				else
					draw[i][j] = ' ';
			}
		}

		//Mảng chứa hệ số chuyển đổi từ tọa độ quân cờ sang tọa độ nền của trục dọc
		//Mang chi su dung i chay tu 1-10, bo i==0
		int trucdoc[11];
		for (int i = 0; i < 11; i++)
			trucdoc[i] = i - 2;

		//Mảng chứa hệ số chuyển đổi từ tọa độ quân cờ sang tọa độ nền của trục ngang
		//Mang chi su dung i chay tu 1-9, bo i==0
		int trucngang[10];
		trucngang[0] = -5;
		for (int i = 1; i < 10; i++)
			trucngang[i] = trucngang[i - 1] + 4;

		//vòng for duyệt mảng quân cờ trắng
		//gán chữ cái tương ứng của từng quân cờ lên tọa độ nền
		for (int i = 0; i < MAX; i++)
		{
			if (Trang[i]->GetIndex() == -1)
				continue;
			Diem tempTrang = Trang[i]->GetDiemDangDung();
			char Char;
			if (Trang[i]->GetIndex() == 1)
				Char = 'S'; //Soldier-Tot'
			else if (Trang[i]->GetIndex() == 2)
				Char = 'C'; //Cannon-Phao'
			else if (Trang[i]->GetIndex() == 3)
				Char = 'R'; //Rook-Xe
			else if (Trang[i]->GetIndex() == 4)
				Char = 'H'; //Horse-Ma~
			else if (Trang[i]->GetIndex() == 5)
				Char = 'E'; //Elephant-Tuong.
			else if (Trang[i]->GetIndex() == 6)
				Char = 'A'; //Advisor-Si~
			else
				Char = 'K'; //King-Tuong'
			draw[tempTrang.GetX() + trucdoc[tempTrang.GetX()]][tempTrang.GetY() + trucngang[tempTrang.GetY()]] = Char;
		}

		//vòng for duyệt mảng quân cờ đen
		//gán chữ cái tương ứng của từng quân cờ lên tọa độ nền
		for (int i = 0; i < MAX; i++)
		{
			if (Den[i]->GetIndex() == -1)
				continue;
			Diem tempDen = Den[i]->GetDiemDangDung();
			char Char;
			if (Den[i]->GetIndex() == 1)
				Char = 'S'; //Soldier-Tot'
			else if (Den[i]->GetIndex() == 2)
				Char = 'C'; //Cannon-Phao'
			else if (Den[i]->GetIndex() == 3)
				Char = 'R'; //Rook-Xe
			else if (Den[i]->GetIndex() == 4)
				Char = 'H'; //Horse-Ma~
			else if (Den[i]->GetIndex() == 5)
				Char = 'E'; //Elephant-Tuong.
			else if (Den[i]->GetIndex() == 6)
				Char = 'A'; //Advisor-Si~
			else
				Char = 'K'; //King-Tuong'
			draw[tempDen.GetX() + trucdoc[tempDen.GetX()]][tempDen.GetY() + trucngang[tempDen.GetY()]] = Char;
		}

		//Mảng chứa hệ số chuyển đổi từ tọa độ nền sang tọa độ của quân cờ của trục dọc
		//Mảng chỉ sử dụng các i%2==0
		int trucdocxuat[19];
		trucdocxuat[0] = -1;
		for (int i = 1; i < 19; i++)
		{
			if (i % 2 == 0)
				trucdocxuat[i] = trucdocxuat[i - 2] + 1;
			else trucdocxuat[i] = 0;
		}

		//Mảng chứa hệ số chuyển đổi từ tọa độ nền sang tọa độ của quân cờ của trục ngang
		//Mảng chỉ sử dụng các i%5==0
		int trucngangxuat[41];
		trucngangxuat[0] = -1;
		for (int i = 1; i < 41; i++)
		{
			if (i % 5 == 0)
				trucngangxuat[i] = trucngangxuat[i - 5] + 4;
			else trucngangxuat[i] = 0;
		}

		//Phần code còn lại để xuất ra bàn cờ - mang tính đếm tay rất cao
		int temp;
		cout << "\t\t#-----------------------------------------------------------#";
		cout << "\n\t\t|                                                           |";
		cout << "\n\t\t|         ";
		temp = 1;
		for (int i = 0; i < 41; i++)
			if (i % 5 == 0)
				cout << temp++ << "    ";
		cout << "     |";
		cout << "\n\t\t|                                                           |\n";


		temp = 1;
		for (int i = 0; i < 19; i++)
		{
			if (i % 2 == 0)
			{

				if (temp < 10)
					cout << "\t\t|    " << temp << "    ";
				else
					cout << "\t\t|    " << temp << "   ";
			}
			else
				cout << "\t\t|    " << "     ";

			for (int j = 0; j < 41; j++)
			{
				if (draw[i][j] != '|' && draw[i][j] != '-' && draw[i][j] != '+' && draw[i][j] != ' ' && draw[i][j] != '\\' && draw[i][j] != '/')
				{
					Diem temp(i - trucdocxuat[i], j - trucngangxuat[j]);
					for (int z = 0; z < MAX; z++)
					{
						if (temp == Trang[z]->GetDiemDangDung())
						{
							if (Trang[z]->GetIndex() == 7 && KiemChieuTuong(1) == 1)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
								cout << draw[i][j];
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
								cout << draw[i][j];
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							}
							break;
						}
						else if (temp == Den[z]->GetDiemDangDung())
						{
							if (Den[z]->GetIndex() == 7 && KiemChieuTuong(2) == 1)
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
								cout << draw[i][j];
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							}
							else
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
								cout << draw[i][j];
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							}
							break;
						}
					}
				}
				else if (i == 9)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 56);
					cout << draw[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 104);
					cout << draw[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}

			}
			if (i % 2 == 0)
			{
				if (temp < 10)
					cout << "    " << temp++ << "    |";
				else
					cout << "   " << temp << "    |";
			}
			else
				cout << "     " << "    |";
			cout << "\n";
		}

		
		cout << "\t\t|                                                           |";
		cout << "\n\t\t|         ";
		temp = 1;
		for (int i = 0; i < 41; i++)
			if (i % 5 == 0)
				cout << temp++ << "    ";
		cout << "     |";
		cout << "\n\t\t|                                                           |";
		cout << "\n\t\t#-----------------------------------------------------------#";

	}

	bool Go(int Type,int Index) 
	{
		//Hàm return 1 nếu Go thành công
		//Hàm return 0 nếu Go không thành công

		//TrongSoDauTienCuaQuanCo là trọng số đầu tiên của loại quân cờ muốn đi trong mảng quân cờ có màu theo Type
		//Ví dụ: Cho Type=1 và Index=1
		//5 Quân tốt Trắng còn nguyên(chưa bị ăn) có các trọng số là: 0,1,2,3,4 và tất cả 5 quân đều có Index=1
		// -> TrongSoDauTienCuaQuanCo = 0
		int TrongSoDauTienCuaQuanCo = TonTaiLoaiQuanCoTrenBanCo(Type, Index); 
		if ( TrongSoDauTienCuaQuanCo != -1)
		{
			//Thỏa if này tức là tồn tại loại quân muốn đi
			//TrongSoKetThucCuaQuanCo là trọng số kết thúc của loại quân cờ muốn đi trong mảng quân cờ có màu theo Type
			int TrongSoKetThucCuaQuanCo;
			if (TrongSoDauTienCuaQuanCo == 0 || TrongSoDauTienCuaQuanCo == 1 || TrongSoDauTienCuaQuanCo == 2 || TrongSoDauTienCuaQuanCo == 3 || TrongSoDauTienCuaQuanCo == 4)
				TrongSoKetThucCuaQuanCo = 4;
			else if (TrongSoDauTienCuaQuanCo == 5 || TrongSoDauTienCuaQuanCo == 6)
				TrongSoKetThucCuaQuanCo = 6;
			else if (TrongSoDauTienCuaQuanCo == 7 || TrongSoDauTienCuaQuanCo == 8)
				TrongSoKetThucCuaQuanCo = 8;
			else if (TrongSoDauTienCuaQuanCo == 9 || TrongSoDauTienCuaQuanCo == 10)
				TrongSoKetThucCuaQuanCo = 10;
			else if (TrongSoDauTienCuaQuanCo == 11 || TrongSoDauTienCuaQuanCo == 12)
				TrongSoKetThucCuaQuanCo = 12;
			else if (TrongSoDauTienCuaQuanCo == 13 || TrongSoDauTienCuaQuanCo == 14)
				TrongSoKetThucCuaQuanCo = 14;
			else
				TrongSoKetThucCuaQuanCo = 15;

			//Xuất cách đi "bằng chữ" (đề bài) cho loại quân cờ đó
			if (Type == 1)
				Trang[TrongSoDauTienCuaQuanCo]->CachDi();
			else
				Den[TrongSoDauTienCuaQuanCo]->CachDi();

			//vòng for duyệt và xuất ra các quân cờ thuộc loại vừa chọn 
			for (int i = TrongSoDauTienCuaQuanCo; i <= TrongSoKetThucCuaQuanCo; i++)
			{
				Diem temp;
				if (Type == 1)
				{
					if (Trang[i]->GetIndex() == -1)
						continue;
					temp = Trang[i]->GetDiemDangDung();
				}
				else
				{
					if (Den[i]->GetIndex() == -1)
						continue;
					temp = Den[i]->GetDiemDangDung();
				}
				if (Index == 1)
					cout << "-Tot";
				if (Index == 2)
					cout << "-Phao";
				if (Index == 3)
					cout << "-Xe";
				if (Index == 4)
					cout << "-Ngua";
				if (Index == 5)
					cout << "-Tuong";
				if (Index == 6)
					cout << "-Si";
				if (Index == 7)
					cout << "-Tuong'";
				temp.Xuat();
				cout << endl;
			}


			//Nhập tọa độ quân muốn đi
			Diem MuonDi;
			cout << "Nhap toa do quan muon di: " << endl;
			MuonDi.Nhap();
			while (KiemTraToaDoQuanMuonDi(Type, MuonDi, Index) == -1)
			{
				cout << "Toa do khong hop le. Nhap lai." << endl;
				MuonDi.Nhap();
			}

			//TrongSoQuanMuonDiTrongMang là trọng số của quân muốn đi trong mảng đã khai báo ở private
			int TrongSoQuanMuonDiTrongMang = KiemTraToaDoQuanMuonDi(Type, MuonDi, Index);
			
			int SoPhanTuCuaMangToaDoTheoLuat;
			Diem* MangToaDoTheoLuatCuaQuanMuonDi;
			if (Type == 1)
			{
				//Khởi tạo mảng chứa các nước đi có thể của quân muốn đi khi trên bàn cờ có 1 mình nó
				MangToaDoTheoLuatCuaQuanMuonDi = Trang[TrongSoQuanMuonDiTrongMang]->ToaDoDiTheoLuat(Type, SoPhanTuCuaMangToaDoTheoLuat);
				//Hàm loại bỏ các nước đi vi phạm luật chơi
				LoaiCacNuocDiRoiVaoTruongHopDacBiet(Type, Trang[TrongSoQuanMuonDiTrongMang], MangToaDoTheoLuatCuaQuanMuonDi, SoPhanTuCuaMangToaDoTheoLuat);
			}
			else
			{
				//Khởi tạo mảng chứa các nước đi có thể của quân muốn đi khi trên bàn cờ có 1 mình nó
				MangToaDoTheoLuatCuaQuanMuonDi = Den[TrongSoQuanMuonDiTrongMang]->ToaDoDiTheoLuat(Type, SoPhanTuCuaMangToaDoTheoLuat);
				//Hàm loại bỏ các nước đi vi phạm luật chơi
				LoaiCacNuocDiRoiVaoTruongHopDacBiet(Type, Den[TrongSoQuanMuonDiTrongMang], MangToaDoTheoLuatCuaQuanMuonDi, SoPhanTuCuaMangToaDoTheoLuat);
			}
			
			//Xuất các nước có thể đi theo đúng luật chơi
			if (XuatCacNuocCoTheDi(Type, MangToaDoTheoLuatCuaQuanMuonDi, SoPhanTuCuaMangToaDoTheoLuat) != 1)
				return 0;

			//Nhập tọa độ muốn đi tới
			Diem DiToi;
			cout << "Nhap toa do muon di toi: " << endl;
			DiToi.Nhap();
			while (KiemTraToaDoCoTrongMang(MangToaDoTheoLuatCuaQuanMuonDi, SoPhanTuCuaMangToaDoTheoLuat, DiToi) == -1)
			{
				cout << "Toa do khong hop le. Nhap lai." << endl;
				DiToi.Nhap();
			}
			
			//TrongSoQuanDiToiTrongMang là trọng số của DiToi trong mảng MangToaDoTheoLuatCuaQuanMuonDi
			int TrongSoQuanDiToiTrongMang = KiemTraToaDoCoTrongMang(MangToaDoTheoLuatCuaQuanMuonDi, SoPhanTuCuaMangToaDoTheoLuat, DiToi);
		
			//Go
			if (Type == 1)
			{
				//Type==1->Quân Trắng đang đi
				if (KiemTraTrangThaiToaDo(DiToi) != 1)
				{
					//(KiemTraTrangThaiToaDo(DiToi) != 1) 
					//điều kiện trên đảm bảo rằng tọa độ của DiToi không phải một quân trắng đang nắm giữ
					if (KiemTraTrangThaiToaDo(DiToi) == 2)
					{
						//(KiemTraTrangThaiToaDo(DiToi) == 2)
						//điều kiện trên thỏa tọa độ của DiToi đang được quân đen nắm giữ
						//vòng for duyệt mảng các quân cờ đen khai báo ở Private
						for (int i = 0; i < MAX; i++)
						{
							if (Den[i]->GetDiemDangDung() == DiToi)
							{
								//(Den[i]->GetDiemDangDung() == DiToi)
								//Tìm thấy 1 quân cờ màu đen có tọa độ trùng tọa độ DiToi
								//Quân màu đen bị ăn-> set(-1,-1) và index=-1
								Den[i]->SetDiemDangDung(-1, -1);
								Den[i]->SetIndex(-1);
								break;
							}
						}
					}
					//Cập nhật lại tọa độ của quân Muốn Đi trong mảng quân cờ Trắng- set theo tọa độ của DiToi
					Trang[TrongSoQuanMuonDiTrongMang]->SetDiemDangDung(DiToi.GetX(), DiToi.GetY());
				}
			}
			else
			{
				//Ngược lại Type==1->Quân Đen đang đi
				if (KiemTraTrangThaiToaDo(DiToi) != 2)
				{
					//(KiemTraTrangThaiToaDo(DiToi) != 2)
					//điều kiện trên đảm bảo rằng tọa độ của DiToi không phải một quân đen đang nắm giữ
					if (KiemTraTrangThaiToaDo(DiToi) == 1)
					{
						//(KiemTraTrangThaiToaDo(DiToi) == 1)
						//điều kiện trên thỏa tọa độ của DiToi đang được quân trắng nắm giữ
						//vòng for duyệt mảng các quân cờ trắng khai báo ở Private
						for (int i = 0; i < MAX; i++)
						{
							if (Trang[i]->GetDiemDangDung() == DiToi)
							{
								//(Trang[i]->GetDiemDangDung() == DiToi)
								//Tìm thấy 1 quân cờ màu trắng có tọa độ trùng tọa độ DiToi
								//Quân màu trắng bị ăn-> set(-1,-1) và index=-1
								Trang[i]->SetDiemDangDung(-1, -1);
								Trang[i]->SetIndex(-1);
								break;
							}
						}
					}
					//Cập nhật lại tọa độ của quân Muốn Đi trong mảng quân cờ Đen- set theo tọa độ của DiToi
					Den[TrongSoQuanMuonDiTrongMang]->SetDiemDangDung(DiToi.GetX(), DiToi.GetY());
				}
			}
			return 1;
		}
		else
			return 0;
	}

	void Game()
	{
		//1 là màu trắng, ngược lại là màu đen
		bool Type = 1;    
		while (true)
		{
			system("cls");
			VeBanCo();
			cout << "\n---------------------------\n";
			cout << "-----DanhSachCacQuanCo-----";
			cout << "\n-1.Tot   -  S(Soldier)";
			cout << "\n-2.Phao  -  C(Cannon)";
			cout << "\n-3.Xe    -  R(Rook)";
			cout << "\n-4.Ngua  -  H(Horse)";
			cout << "\n-5.tuong -  E(Elephant)";
			cout << "\n-6.Si    -  A(Advisor)";
			cout << "\n-7.Tuong -  K(King)";
			cout << "\n-0.Ket thuc game";
			cout << "\n---------------------------\n";

			if (Type == 1)
				cout << "--BenTrang(Tren)--" << endl;
			else
				cout << "--BenDen(Duoi)--" << endl;

			if (KiemChieuTuong(Type) == 1)
				cout << "Luu y: Ban dang bi chieu tuong!" << endl;

			int luachon;
			cout << "Chon mot quan co: ";
			cin >> luachon;
			while (luachon < 0 || luachon>7)
			{
				cout << "Khong hop le.Nhap lai." << endl;
				cout << "Chon mot quan co: ";
				cin >> luachon;
			}

			//luachon=0 -> kết thúc
			if (luachon == 0)
				break;

			//Đi quân cờ
			while(true)
			{
				if (Go(Type, luachon) == 0)
				{
					cout << "Quan co da bi an hoac khong di duoc." << endl;
					cout << "Hay di lai." << endl;
					cout << "Chon mot quan co: ";
					cin >> luachon;
				}
				else
				{
					cout << "Di thanh cong." << endl;
					break;
				}
			}

			//Kiểm tra xem con Tướng còn sống hay đã chết
			if (Trang[15]->GetIndex() == -1)
			{
				cout << "---BEN DEN THANG, BEN TRANG THUA---" << endl;
				break;
			}
			if (Den[15]->GetIndex() == -1)
			{
				cout << "---BEN TRANG THANG, BEN DEN THUA---" << endl;
				break;
			}

			//If dưới có chức năng thay phiên lược đi giữa 2 bên
			if (Type == 1)
				Type = 0;
			else
				Type = 1;
			system("pause");
		}
	}

};

int main()
{
	Player a;
	a.KhoiTaoBanCo();
	a.Game();
	return 0;
}
