#include "dshocvien.h"

void xuathv_duoi5(ListLop hv) {
	ListHV hv_duoitb;
	NodeLop* x = hv.head;
	while (x != NULL) {
		NodeHV* z = x->info.hocvien.head;
		while (z != NULL) {
			if (z->info.diem < 5) {
				inserTailHocVien(hv_duoitb, createHocVien(z->info));
			}
			z = z->Next;
		}

		x = x->Next;
	}
		for (NodeHV* i = hv_duoitb.head; i->Next != NULL; i = i->Next) {
			for (NodeHV* j = i->Next; j != NULL; j = j->Next) {
				if (strcmpi(i->info.Ten, j->info.Ten) < 0) {
					swap_HV(i->info, j->info);
				}
			}
		}
		color(12);
		printf("--------------------------DANH SACH HOC VIEN DUOI 5 (Sap xep theo ten)----------------------------\n");
		xuat_All_HV(hv_duoitb);
		color(14);
}