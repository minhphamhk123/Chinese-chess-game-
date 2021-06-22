#pragma once
#include"Tot.h"
#include"Phao.h"
#include"Xe.h"
#include"Ngua.h"
#include"Tuong.h"
#include"Si.h"
#include"_Tuong_.h"
constexpr auto MAX = 16;
class Player
{
private:
	QuanCo** Trang;
	QuanCo** Den;
public:
	Player();
	Player(const Player& temp);
	Player& operator=(const Player& temp);
	~Player();

	void KhoiTaoDuLieuQuanCo();

	int TonTaiLoaiQuanCoTrenBanCo(int Type, int Index);

	int KiemTraToaDoCoTrongMang(Diem* a, int n, Diem temp);

	int KiemTraTrangThaiToaDo(Diem temp);

	int KiemTraToaDoQuanMuonDi(int Type, Diem MuonDi, int Index);

	bool XuatCacNuocCoTheDi(int Type, Diem*& a, int n);

	void LoaiCacNuocDiRoiVaoTruongHopDacBiet(int Type, QuanCo* MuonDi, Diem*& a, int n);

	bool KiemChieuTuong(int Type);

	int KiemKetQuaVanCo();

	void VeBanCo();

	bool Go(int Type, int Index);

	void StartGame();
};

