#include "dshocvien.h"

NodeHV* createHocVien(hv x) {
	NodeHV* newnode = new NodeHV;
	newnode->info = x;
	newnode->Next = NULL;
	return newnode;
}
NodeLop* createLop(lop x) {
	NodeLop* newnode = new NodeLop;
	newnode->info = x;
	newnode->Next = NULL;
	return newnode;
}
void inserTailHocVien(ListHV& s, NodeHV* x) {
	if (s.head == NULL) {
		s.head = s.tail = x;
		return;
	}
	s.tail->Next = x;
	s.tail = x;
}
void inserTailLop(ListLop& lop, NodeLop* x) {
	if (lop.head == NULL) {
		lop.head = lop.tail = x;
		return;
	}
	lop.tail->Next = x;
	lop.tail = x;
}
void swap_HV(hv &a, hv &b) {
	hv z = a;
	a = b;
	b = z;
}

void swap_Lop(lop &a, lop &b) {
	lop z = a;
	a = b;
	b = z;
}
void chuanhoa(char text[]) {
	if (text[0] >= 'a' && text[0] <= 'z') {
		text[0] -= 32;
	}
	for (int i = 1; i < strlen(text); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			if (text[i + 1] != ' ' && text[i - 1] == ' ') {
				text[i] -= 32;
			}
		}
		if (text[i] >= 'A' && text[i] <= 'Z') {
			if (text[i - 1] != ' ') {
				text[i] += 32;
			}
		}
	}
	
}
void color(int color)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}
void InHoa(char text[]) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			text[i] -= 32;
		}
	}
}