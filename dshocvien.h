#pragma once
#ifndef dshocvien
#define dshocvien
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <cctype>
#pragma warning(disable:4996)

typedef struct LopHoc lop;
typedef struct HocVien hv;

//DSLK HỌC VIÊN
struct date
{
	int ngay, thang, nam;
};
struct HocVien
{
	char MaHocVien[11];
	char HoLot[21];
	char Ten[11];
	date sinh;
	char MaLop[11];
	float diem;
};
struct NodeHV {
	hv info;
	NodeHV* Next;
};
struct ListHV {
	NodeHV* head = NULL;
	NodeHV* tail = NULL;
};
//DSLK LỚP HỌC
struct LopHoc
{
	char MaLop[11];
	char TenLop[11];
	char LichHoc[11];
	int HocPhi;
	date ngayBatDau;
	date ngayKetThucDuKien;
	date ngayKetThucThucTe;
	ListHV hocvien;
};
struct NodeLop {
	lop info;
	NodeLop* Next;
};
struct ListLop {
	NodeLop* head = NULL;
	NodeLop* tail = NULL;
};

NodeHV* createHocVien(hv x);
NodeLop* createLop(lop x);
void inserTailHocVien(ListHV& s, NodeHV* x);
void inserTailLop(ListLop& lop, NodeLop* x);
void Nhaphocvien(hv& x);					//Nhập thông tin 1 học viên
void Nhap_n_hocVien(ListLop &s );	// Nhập thông tin n học viên
//void NhaphocVien_TheoLop(ListLop& l, hv x);		// Nhập học viên theo lớp
void menuTimkiem();							//Hiển thị menu chọn chức năng tìm kiếm theo mã lớp, mã học viên,năm sinh
void TimTheoTieuChi(ListLop l);				//Nhập tên và tìm kiếm theo mã lớp, mã học viên,năm sinh
void loadFile_HocVien(FILE* f, hv& s);		//Nhập 1 thông tin học viên từ file
void uploadFile_ALL_HocVien(ListHV& s, char filehv[], char malop[]); //Nhập thông tin toàn bộ học viên từ file
void loadFile_Lop(FILE* f, lop& x, char filehv[]);		//Nhập 1 thông tin lớp từ file và toàn bộ học viên lớp đó
void uploadFile_ALL_Lop(ListLop& l, char filelop[], char filehocvien[]);//Nhập full danh sách lớp và học viên của lớp đó
void Xuat_HV(hv s, int stt);				// Xuất 1 học viên
void xuat_Lop(lop x);						// Xuất 1 lớp và toàn bộ học viên lớp đó
void xuat_ALL_Lop(ListLop x);				//Xuất toàn bộ lớp và học viên
void xuat_All_HV(ListHV h);

void save_HVHB(FILE* f, hv& s);
void save_HV(ListLop& s, char filehv[]);
void HV_Diem_CaoNhat(ListLop s);
void swap_HV(hv& a, hv& b);
void swap_Lop(lop& a, lop& b);
void sapxephv(ListLop s);
void HV_lop_HP_CaoNhat(ListLop l);
void xuathv_duoi5(ListLop hv);
void chuanhoa(char text[]);
void InHoa(char text[]);
void InDsHv(ListLop s);
void listMenu();
void menu();

void color(int color);
#endif dshocvien