#include "dshocvien.h"

void save_HV(ListLop& s, char filehv[]) {
	int n = 0;
	FILE* f = fopen(filehv, "wt");
	NodeLop* x = s.head;
	color(11);
	printf("-------------------------------------------DANH SACH HOC BONG------------------------------------\n");
	printf("%s%15s%10s%15s%12s%9s%8s%10s%10s", "STT", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	color(15);
	fprintf(f,"Danh sach hoc bong\n");
	fprintf(f,"%s%8s%15s%12s%9s%8s%10s%10s", "MA HOC VIEN", "HO LOT", "TEN", "SINH NGAY", "THANG", "NAM", "MA LOP", "DIEM\n");
	while (x != NULL){
		NodeHV* z = x->info.hocvien.head;
		while (z != NULL) {
			if (z->info.diem >= 8) {
				n++;
				save_HVHB(f, z->info);
				Xuat_HV(z->info, n);
			}
			z = z->Next;
		}
		x = x->Next;
	}
	color(11);
	printf("Da xuat file txt\n");
	color(15);
	fclose(f);
}
