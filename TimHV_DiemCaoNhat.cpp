#include "dshocvien.h"

void HV_Diem_CaoNhat(ListLop s) {
	int n = 0;
	NodeHV* x = s.head->info.hocvien.head;
	float Max = x->info.diem;


	NodeLop* tmp = s.head;
	NodeLop* g = tmp;
	while (tmp != NULL) {
		NodeHV* z = tmp->info.hocvien.head;
		while (z != NULL) {
			if (z->info.diem > Max) Max = z->info.diem;
			z = z->Next;
		}
		tmp = tmp->Next;
	}
	color(10);
	printf("---------------------------DANH SACH HOC VIEN CO DIEM CAO NHAT-----------------------------------\n");
	printf("%s%15s%10s%15s%12s%9s%8s%10s%10s", "STT", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	color(15);
	while (g != NULL) {
		NodeHV* e = g->info.hocvien.head;
		while (e != NULL) {
			if (e->info.diem == Max) Xuat_HV(e->info, ++n);
			e = e->Next;
		}
		g = g->Next;
	}
}