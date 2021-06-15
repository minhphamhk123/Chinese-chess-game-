#include "Player.h"
Player::Player()
{
	Trang = NULL;
	Den = NULL;
}
Player::Player(const Player& temp)
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
Player& Player::operator=(const Player& temp)
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
Player::~Player()
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

void Player::KhoiTaoDuLieuQuanCo()
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

int Player::TonTaiLoaiQuanCoTrenBanCo(int Type, int Index)
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

int Player::KiemTraToaDoCoTrongMang(Diem* a, int n, Diem temp)
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

int Player::KiemTraTrangThaiToaDo(Diem temp)
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

int Player::KiemTraToaDoQuanMuonDi(int Type, Diem MuonDi, int Index)
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

bool Player::XuatCacNuocCoTheDi(int Type, Diem*& a, int n)
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

void Player::LoaiCacNuocDiRoiVaoTruongHopDacBiet(int Type, QuanCo* MuonDi, Diem*& a, int n)
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

bool Player::KiemChieuTuong(int Type)
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

int Player::KiemKetQuaVanCo()
{
	//0: Chưa có kết quả, 1: Trắng thắng, 2: Đen thắng, 3 Hòa

	//Den[15]->GetIndex() == -1 -> Tướng quân đen đã bị ăn
	if (Den[15]->GetIndex() == -1)
		return 1;
	//Trang[15]->GetIndex() == -1 -> Tướng quân trắng đã bị ăn
	if (Trang[15]->GetIndex() == -1)
		return 2;

	bool TonTaiTrang = 0;
	bool TonTaiDen = 0;
	for (int i = 0; i < MAX; i++)
	{
		int index;

		index = Trang[i]->GetIndex();
		if (0 < index && index < 5)
			TonTaiTrang = 1;

		index = Den[i]->GetIndex();
		if (0 < index && index < 5)
			TonTaiDen = 1;

		if (TonTaiDen == 1 && TonTaiTrang == 1)
			break;
	}

	if (TonTaiTrang == 1 && TonTaiDen == 1)
		return 0;
	if (TonTaiTrang == 1 && TonTaiDen == 0)
		return 1;
	if (TonTaiTrang == 0 && TonTaiDen == 1)
		return 2;
	if (TonTaiTrang == 0 && TonTaiDen == 0)
		return 3;
	return -1;
}

void Player::VeBanCo()
{
	//Cấp phát động mảng 2 chiều kiểu char là mảng nền để vẽ bàn cờ
	char** draw = new char* [19];
	for (int i = 0; i < 19; i++)
		draw[i] = new char[41];

	//vòng for gán các kí tự cần thiết vào mảng nền
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
	//gán chữ cái tương ứng của từng quân cờ trắng cho các tọa độ trong mảng nền,
	//ứng với tọa độ của quân cờ đó đang nắm giữ
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
	//gán chữ cái tương ứng của từng quân cờ đen cho các tọa độ trong mảng nền,
	//ứng với tọa độ của quân cờ đó đang nắm giữ
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

	//Mảng chứa hệ số chuyển đổi từ tọa độ nền sang tọa độ của quân cờ trên trục dọc
	//Mảng chỉ sử dụng các trọng số i%2==0, còn lại gán = 0
	int trucdocxuat[19];
	trucdocxuat[0] = -1;
	for (int i = 1; i < 19; i++)
	{
		if (i % 2 == 0)
			trucdocxuat[i] = trucdocxuat[i - 2] + 1;
		else trucdocxuat[i] = 0;
	}

	//Mảng chứa hệ số chuyển đổi từ tọa độ nền sang tọa độ của quân cờ trên trục ngang
	//Mảng chỉ sử dụng các trọng số i%5==0, còn lại gán = 0
	int trucngangxuat[41];
	trucngangxuat[0] = -1;
	for (int i = 1; i < 41; i++)
	{
		if (i % 5 == 0)
			trucngangxuat[i] = trucngangxuat[i - 5] + 4;
		else trucngangxuat[i] = 0;
	}

	//PHẦN CODE ĐỂ IN RA BÀN CỜ

	//In phần viền và trục số ngang phía trên
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
	//Vòng for duyệt mảng 2 chiều đã cấp phát động và khởi tạo
	for (int i = 0; i < 19; i++)
	{
		//In trục số dọc bên trái
		if (i % 2 == 0)
		{
			if (temp < 10)
				cout << "\t\t|    " << temp << "    ";
			else
				cout << "\t\t|    " << temp << "   ";
		}
		else
			cout << "\t\t|    " << "     ";

		//In bàn cờ
		for (int j = 0; j < 41; j++)
		{
			if (draw[i][j] != '|' && draw[i][j] != '-' && draw[i][j] != '+' && draw[i][j] != ' ' && draw[i][j] != '\\' && draw[i][j] != '/')
			{
				//temp giữ tọa độ đã được chuyển từ tọa độ nền sang tọa độ của quân cờ
				Diem temp(i - trucdocxuat[i], j - trucngangxuat[j]);
				//Vòng for duyệt mảng các quân cờ tìm xem tại temp đang có quân cờ nào nắm giữ hay không
				//nếu có thì in đổi màu chữ cái đại diện cho quân cờ đã gán trên mảng tọa độ nền
				for (int z = 0; z < MAX; z++)
				{
					if (temp == Trang[z]->GetDiemDangDung())
					{
						if (Trang[z]->GetIndex() == 7 && KiemChieuTuong(1) == 1)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
							cout << draw[i][j];
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
							cout << draw[i][j];
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						break;
					}
					else if (temp == Den[z]->GetDiemDangDung())
					{
						if (Den[z]->GetIndex() == 7 && KiemChieuTuong(2) == 1)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 132);
							cout << draw[i][j];
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						else
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
							cout << draw[i][j];
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						}
						break;
					}
				}
			}
			else if (i == 9)
			{
				//Lệnh if này nhằm in ra dòng sông có màu xanh
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
		//In trục số dọc bên phải
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

	//In phần viền và trục số ngang phía dưới
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

bool Player::Go(int Type, int Index)
{
	//Hàm return 1 nếu Go thành công
	//Hàm return 0 nếu Go không thành công

	//TrongSoDauTienCuaQuanCo là trọng số đầu tiên của loại quân cờ muốn đi trong mảng quân cờ có màu theo Type
	//Ví dụ: Cho Type=1 và Index=1
	//5 Quân tốt Trắng còn nguyên(chưa bị ăn) có các trọng số là: 0,1,2,3,4 và tất cả 5 quân đều có Index=1
	// -> TrongSoDauTienCuaQuanCo = 0
	int TrongSoDauTienCuaQuanCo = TonTaiLoaiQuanCoTrenBanCo(Type, Index);
	if (TrongSoDauTienCuaQuanCo != -1)
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

void Player::StartGame()
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
		while (true)
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

		//Kiểm tra xem ván cờ đã đi đến hồi kết chưa?
		if (KiemKetQuaVanCo() != 0)
		{
			if (KiemKetQuaVanCo() == 1)
				cout << "---BEN TRANG THANG, BEN DEN THUA---" << endl;
			else if (KiemKetQuaVanCo() == 2)
				cout << "---BEN DEN THANG, BEN TRANG THUA---" << endl;
			else
				cout << "---HAI BEN HOA NHAU---" << endl;
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