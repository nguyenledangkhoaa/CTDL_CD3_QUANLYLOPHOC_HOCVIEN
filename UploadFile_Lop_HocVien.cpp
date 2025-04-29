#include "dshocvien.h"

void loadFile_HocVien(FILE* f, hv& s) {
	fscanf(f, "%[^,],%[^,],%[^,],%d,%d,%d,%[^,], %f\n",
		&s.MaHocVien, &s.HoLot, &s.Ten, &s.sinh.ngay, &s.sinh.thang, &s.sinh.nam, &s.MaLop, &s.diem);
}
void uploadFile_ALL_HocVien(ListHV& s, char filehv[], char malop[]) {
	FILE* f = fopen(filehv, "rt");
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		hv x;
		loadFile_HocVien(f, x);
		if (strcmpi(x.MaLop, malop) == 0) {
			NodeHV* p = createHocVien(x);
			inserTailHocVien(s, p);
		}
	}
	fclose(f);
}
void loadFile_Lop(FILE* f, lop& x, char filehv[]) {
	fscanf(f, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
		&x.MaLop, &x.TenLop, &x.LichHoc, &x.HocPhi,
		&x.ngayBatDau.ngay, &x.ngayBatDau.thang, &x.ngayBatDau.nam,
		&x.ngayKetThucDuKien.ngay, &x.ngayKetThucDuKien.thang, &x.ngayKetThucDuKien.nam,
		&x.ngayKetThucThucTe.ngay, &x.ngayKetThucThucTe.thang, &x.ngayKetThucThucTe.nam);
	uploadFile_ALL_HocVien(x.hocvien, filehv, x.MaLop);
}
void uploadFile_ALL_Lop(ListLop& l, char filelop[], char filehocvien[]) {
	FILE* f = fopen(filelop, "rt");
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		lop x;
		loadFile_Lop(f, x, filehocvien);
		NodeLop* p = createLop(x);
		inserTailLop(l, p);
	}
	fclose(f);
}

void save_HVHB(FILE* f, hv& s) {
	fprintf(f,"%-12s%-12s%10s%8d%11d%10d%9s%10.2f\n",
		s.MaHocVien, s.HoLot, s.Ten, s.sinh.ngay, s.sinh.thang, s.sinh.nam, s.MaLop, s.diem);
}
