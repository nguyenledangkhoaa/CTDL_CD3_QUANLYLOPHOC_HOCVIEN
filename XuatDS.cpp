#include "dshocvien.h"

void Xuat_HV(hv s, int stt) {
	printf("%-10d%-12s%-12s%10s%8d%11d%10d%9s%10.2f\n",
		stt, s.MaHocVien, s.HoLot, s.Ten, s.sinh.ngay, s.sinh.thang, s.sinh.nam, s.MaLop, s.diem);

}

void xuat_All_HV(ListHV h) {
	int stt = 0;
	printf("%s%15s%10s%15s%12s%9s%8s%10s%10s", "STT", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	color(15);
	NodeHV* tmp = h.head;
	if (tmp == NULL) {
		printf("Danh sach trong\n");
		return;
	}

	while (tmp != NULL) {
		stt++,
		Xuat_HV(tmp->info, stt);
		tmp = tmp->Next;
	}
}
void xuat_Lop(lop x) {
	color(11);
	printf("\n------------------------------------------------------------------------------------------------\n");
	printf("Ma Lop: %-30s\tNgay bat dau: %d/%d/%d\nTen Lop: %-30s\tNgay Ket thuc du kien: %d/%d/%d\nLich hoc: %-25s\tNgay ket thuc thuc te: %d/%d/%d\nHoc phi: %d\n", 
		x.MaLop, x.ngayBatDau.ngay, x.ngayBatDau.thang, x.ngayBatDau.nam, 
		x.TenLop, x.ngayKetThucDuKien.ngay, x.ngayKetThucDuKien.thang, x.ngayKetThucDuKien.nam,
		x.LichHoc, x.ngayKetThucThucTe.ngay, x.ngayKetThucThucTe.thang, x.ngayKetThucThucTe.nam,
		x.HocPhi);
	printf("--------------------------------------------------------------------------------------------------\n");
	xuat_All_HV(x.hocvien);
	printf("--------------------------------------------------------------------------------------------------\n");
}
void xuat_ALL_Lop(ListLop x) {
	NodeLop* tmp = x.head;
	if (tmp == NULL) {
		printf("Danh sach trong");
		return;
	}
	while (tmp != NULL) {
		xuat_Lop(tmp->info);
		tmp = tmp->Next;
	}
}

void InDsHv(ListLop s) {
	ListHV hv;
	NodeLop* x = s.head;
	while (x != NULL) {
		NodeHV* y = x->info.hocvien.head;
		while (y != NULL) {
			inserTailHocVien(hv, createHocVien(y->info));
			y = y->Next;
		}
		x = x->Next;
	}
	color(11);
	printf("--------------------------------------DANH SACH HOC VIEN-----------------------------------------\n");
	xuat_All_HV(hv);
	color(15);
}