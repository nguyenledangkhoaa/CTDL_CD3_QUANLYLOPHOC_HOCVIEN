#include "dshocvien.h"

void HV_lop_HP_CaoNhat(ListLop l) {
	int n = 0, hp = 0;
	NodeLop* x = l.head;
	while (x != NULL) {
		if (hp < x->info.HocPhi) hp = x->info.HocPhi;
		x = x->Next;
	}
	color(10);
	printf("----------------THONG TIN HOC VIEN HOC O LOP CO HOC PHI CAO NHAT - HOC PHI: %d --------------\n", hp);
	printf("%s%15s%10s%15s%12s%9s%8s%10s%10s", "STT", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	color(15);

	NodeLop* y = l.head;
	while (y != NULL) {
		if (y->info.HocPhi == hp) {
			NodeHV* z = y->info.hocvien.head;
			while (z != NULL) {
				Xuat_HV(z->info, ++n);
				z = z->Next;
			}
		}
		y = y->Next;
	}



	/*while (y != NULL) {
		if (y->info.HocPhi >= hp) 
			xuat_All_HV(y->info.hocvien);
		y = y->Next;
	}*/

}