#include <iostream>
using namespace std;

#define MAXN  100

struct CongViec
{
	int chiSo; // chi so cua cong viec
	int thoiGian; // thoi gian cua cong viec
};

struct May
{
	int tongThoiGian = 0; // tong thoi gian may da lam
	int soCongViec = 0; // so cong viec may da lam
	CongViec CV[MAXN]; //mang cong viec luu danh sach cac cong viec may da lam
};

void nhapCongViec(CongViec cv[], int soCongViec);
void xuatCongViec(CongViec cv[], int soCongViec);
void sapXepCongViec(CongViec cv[], int soCongViec);
void hoanViCongViec(CongViec &a, CongViec &b);
void phanCongCongViec(CongViec cv[], May may[], int soCongViec, int soMay);
int timMayRanhRoi(May may[], int soMay);
void xuatKetQua(May may[], int soMay);

int main()
{
	int soCongViec, soMay;
	CongViec cv[MAXN];
	May may[MAXN];

	cout << "Nhap so cong viec can thuc hien: ";
	cin >> soCongViec;
	nhapCongViec(cv, soCongViec);
	/*xuatCongViec(cv, soCongViec);*/

	sapXepCongViec(cv, soCongViec);
	xuatCongViec(cv, soCongViec);

	cout << "Nhap vao so may: ";
	cin >> soMay;

	phanCongCongViec(cv, may, soCongViec, soMay);
	xuatKetQua(may, soMay);

	system("Pause");
	return 0;
}

void nhapCongViec(CongViec cv[], int soCongViec)
{
	for (int i = 0; i < soCongViec; i++)
	{
		cout << "Nhap thoi gian cho cong viec thu " << i << " : ";
		cin >> cv[i].thoiGian;
		cv[i].chiSo = i;
	}
}

void xuatCongViec(CongViec cv[], int soCongViec)
{
	for (int i = 0; i < soCongViec; i++)
	{
		cout << "Cong viec: " << i << " thoi gian: " << cv[i].thoiGian << " chi so: " << cv[i].chiSo << endl;
	}
}

void sapXepCongViec(CongViec cv[], int soCongViec)
{
	for (int i = 0; i < soCongViec - 1; i++)
	{
		for (int j = i + 1; j < soCongViec; j++)
		{
			if (cv[i].thoiGian < cv[j].thoiGian)
			{
				hoanViCongViec(cv[i], cv[j]);
			}
		}
	}
}
void hoanViCongViec(CongViec &a, CongViec &b) {
	CongViec temp;
	temp.chiSo = a.chiSo;
	temp.thoiGian = a.thoiGian;

	a.chiSo = b.chiSo;
	a.thoiGian = b.thoiGian;

	b.chiSo = temp.chiSo;
	b.thoiGian = temp.thoiGian;
}
void phanCongCongViec(CongViec cv[], May may[], int soCongViec, int soMay)
{
	for (int i = 0; i < soCongViec; i++)
	{
		int mayTiepTheo = timMayRanhRoi(may, soMay);
		int congViecTiepTheo = may[mayTiepTheo].soCongViec;
		may[mayTiepTheo].CV[congViecTiepTheo].chiSo = cv[i].chiSo;
		may[mayTiepTheo].CV[congViecTiepTheo].thoiGian = cv[i].thoiGian;
		may[mayTiepTheo].soCongViec++;
		may[mayTiepTheo].tongThoiGian += cv[i].thoiGian;
	}
}
int timMayRanhRoi(May may[], int soMay)
{
	int thoiGian = may[0].tongThoiGian;
	int mayRanhRoi = 0;
	for (int i = 1; i < soMay; i++)
	{
		if (may[i].tongThoiGian < thoiGian)
		{
			thoiGian = may[i].tongThoiGian;
			mayRanhRoi = i;
		}
	}
	return mayRanhRoi;
}
void xuatKetQua(May may[], int soMay)
{
	for (int i = 0; i < soMay; i++)
	{
		cout << "May: " << i << endl;
		cout << "Tong thoi gian: " << may[i].tongThoiGian;
		cout << "\nCac cong viec: ";
		for (int j = 0; j < may[i].soCongViec; j++)
		{
			cout << "\t" << may[i].CV[j].chiSo;
		}
		cout << endl;
	}
}