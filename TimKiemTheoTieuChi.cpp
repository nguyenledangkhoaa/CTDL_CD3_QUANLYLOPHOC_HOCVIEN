#include "dshocvien.h"



void menuTimkiem() {
	printf("\n1. Tim kiem theo ma lop");
	printf("\n2. Tim kiem theo ma hoc vien");
	printf("\n3. Tim kiem theo nam sinh");
}

void tieudecot() {
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("%s%15s%10s%15s%12s%9s%8s%10s%10s", "STT", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	printf("--------------------------------------------------------------------------------------------------\n");
}

void TimTheoTieuChi(ListLop l) {
	char timkiem[30], name[11];
	int namsinhtimkiem, n, stt = 0;;
	NodeLop* tmp = l.head;

	printf("Nhap ten can tim: ");
	color(9); gets_s(name); color(6);

	menuTimkiem();	color(15);
	printf("\nChon cach tim kiem: ");
	scanf("%d", &n);

	getchar();
	switch (n) {
	case 1:
		printf("\nNhap ma lop: ");
		gets_s(timkiem);
		tieudecot();
		while (tmp != NULL) {
			if (strcmpi(tmp->info.MaLop, timkiem) == 0) {
				NodeHV* hv = tmp->info.hocvien.head;
				while (hv != NULL) {
					if (strcmpi(hv->info.Ten, name) == 0) {
						color(10);
						color(15);
						Xuat_HV(hv->info, ++stt);
						printf("---------------------------\n");
						return;
					}
					hv = hv->Next;
				}
			}
			tmp = tmp->Next;
		}
		color(12);	 printf("Khong tim thay\n");	 color(15);
		break;
	case 2:
		printf("\nNhap ma hoc vien: ");
		gets_s(timkiem);
		tieudecot();
		while (tmp != NULL) {
			NodeHV* hv = tmp->info.hocvien.head;
			while (hv != NULL) {
				if (strcmpi(hv->info.Ten, name) == 0 && strcmpi(hv->info.MaHocVien, timkiem) == 0) {
					color(10);
					color(15);
					Xuat_HV(hv->info, ++stt);
							printf("---------------------------\n");
							return;
				}
				hv = hv->Next;
			}
			tmp = tmp->Next;
		}
		color(12);	 printf("Khong tim thay\n");	 color(15);
		break;
	case 3:
		int kt = 0;
		printf("\nNhap nam sinh hoc vien: ");
		scanf("%d", &namsinhtimkiem);
		color(10);
		tieudecot();
		while (tmp != NULL) {
			NodeHV* hv = tmp->info.hocvien.head;
			while (hv != NULL) {
				if (hv->info.sinh.nam == namsinhtimkiem && strcmpi(hv->info.Ten, name) == 0) {
					color(15);
					Xuat_HV(hv->info, ++stt);
					kt = 1;
				}
				hv = hv->Next;
			}
			tmp = tmp->Next;
		}
		color(12);
		if (kt == 0) printf("Khong tim thay\n");
		color(15);
		break;
	}
}

