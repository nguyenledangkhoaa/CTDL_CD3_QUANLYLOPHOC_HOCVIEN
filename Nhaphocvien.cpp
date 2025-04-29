#include "dshocvien.h"

void Nhaphocvien(hv& x) {
	printf("Ma hoc vien: ");
	color(15);	 gets_s(x.MaHocVien);	color(11);
	printf("Ho lot: ");
	color(15);	gets_s(x.HoLot);	color(11);
	printf("Ten: ");
	color(15);	gets_s(x.Ten);	color(11);
	printf("Ma lop: ");
	color(15);	gets_s(x.MaLop);	color(11);
	printf("Ngay sinh: ");
	color(15);	scanf("%d", &x.sinh.ngay);	color(11);
	printf("Thang sinh: ");
	color(15);	scanf("%d", &x.sinh.thang);	color(11);
	printf("Nam sinh: ");
	color(15);	scanf("%d", &x.sinh.nam);	color(11);
	printf("Diem so: ");
	color(15);	scanf("%f", &x.diem);	color(11);
	getchar();
	chuanhoa(x.HoLot);
	chuanhoa(x.Ten);
	InHoa(x.MaLop);
}
void Nhap_n_hocVien(ListLop& s) {
	int n;
	do {
		printf("Nhap so luong hoc vien can them: ");
		scanf("%d", &n);
		getchar();
	} while (n <= 0);
	for (int i = 0; i < n; i++) {
		int kt = 0;
		color(11);
		printf("-----------Nhap hoc vien thu %d----------------\n", i+1);
		hv x;
		Nhaphocvien(x);
		NodeLop* z = s.head;
		while (z != NULL) {
			if (strcmpi(z->info.MaLop, x.MaLop) == 0) {
				inserTailHocVien(z->info.hocvien, createHocVien(x));
				color(2);
				printf("Them thanh cong vao lop %s\n", x.MaLop);
				kt++;
				color(14);
			}
			z = z->Next;
		}
		if (kt == 0) {
			color(4);
			printf("Khong ton tai ma lop %s\n", x.MaLop);
			color(15);
		}
	}
}
