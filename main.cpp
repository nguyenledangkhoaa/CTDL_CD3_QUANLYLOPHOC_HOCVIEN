#include "dshocvien.h"

void listMenu() {
		color(11);
		printf("\n*-----------------------------------------------------------------*");
		printf("\n|                       CHU DE 3 - NHOM 10                        |");
		printf("\n*-----------------------------------------------------------------*");
		color(15);
		printf("\n*-----------------------------------------------------------------*");
		printf("\n|                            MENU                                 |");
		printf("\n*-----------------------------------------------------------------*");
		printf("\n| 0. Dong                                                         |");
		printf("\n| 1. Xuat danh sach hoc vien moi lop                              |");
		printf("\n| 2. In danh sach hoc vien                                        |");
		printf("\n| 3. Them hoc vien vao danh sach                                  |");
		printf("\n| 4. Tim kiem hoc vien theo (Lop,Ma hoc vien, nam sinh)           |");
		printf("\n| 5. Tim hoc vien co diem cao nhat                                |");
		printf("\n| 6. Hoc vien hoc o lop co hoc phi cao nhat                       |");
		printf("\n| 7. Sap xep hoc vien cung lop va diem giam dan                   |");
		printf("\n| 8. Danh sach hoc vien duoi trung binh                           |");
		printf("\n| 9. Danh sach hoc vien co hoc bong va luu file .txt              |");
		printf("\n*-----------------------------------------------------------------*");
;
}


void menu() {
	int n;
	ListLop lophoc;
	hv x;
	FILE* f;
	char lop[] = "lophoc.txt";
	char hocvien[] = "hocvien.txt";
	char dshb[] = "hocbong.txt";
	uploadFile_ALL_Lop(lophoc, lop, hocvien);
	do {
		system("cls");
		listMenu();
		color(11);
		printf("\nNhap chuc nang: ");
		color(10);
		scanf("%d", &n);
		color(15);
		getchar();
		switch (n)
		{
		case 1:
			xuat_ALL_Lop(lophoc);
			system("pause");
			break;
		case 2:
			InDsHv(lophoc);
			system("pause");
			break;
		case 3:
			Nhap_n_hocVien(lophoc);
			system("pause");
			break;
		case 4:
			TimTheoTieuChi(lophoc);
			system("pause");
			break;
		case 5:
			HV_Diem_CaoNhat(lophoc);
			system("pause");
			break;
		case 6:
			HV_lop_HP_CaoNhat(lophoc);
			system("pause");
			break;
		case 7:
			sapxephv(lophoc);
			system("pause");
			break;
		case 8:
			xuathv_duoi5(lophoc);
			system("pause");
			break;
		case 9:
			save_HV(lophoc, dshb);
			system("pause");
			break;
		
		}
	} while (n != 0);
}

int main() {
	menu();
}