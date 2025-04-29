#include "dshocvien.h"

void sapxephv(ListLop s) {
	NodeLop* x = s.head;
	ListHV hv;
	NodeHV* d;

	while (x != NULL) {
		NodeHV* z = x->info.hocvien.head;
		while (z != NULL) {
			inserTailHocVien(hv, createHocVien(z->info));
			z = z->Next;
		}
		x = x->Next;
	}

	for (NodeHV* i = hv.head; i->Next != NULL; i = i->Next) {
		for (NodeHV* j = i->Next; j != NULL; j = j->Next) {
			if (strcmpi(i->info.MaLop, j->info.MaLop) > 0) {
				swap_HV(i->info, j->info);
			}
		}
	}	
	

	d = hv.head;
	while (d->Next != NULL) {
		NodeHV* y = d->Next;
		while (y!=NULL) {
			if (strcmpi(d->info.MaLop, y->info.MaLop) == 0) {
				if (d->info.diem < y->info.diem) swap_HV(d->info, y->info);
			}
			y = y->Next;
		}
		d = d->Next;
	}
	color(9);
	printf("--------------------------DANH SACH HOC VIEN DA SAP XEP (Lop tang/Diem giam)----------------------\n");
	xuat_All_HV(hv);
	color(14);
}