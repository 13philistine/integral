#include <iostream>
#include <math.h>
#define PI

using namespace std;
int ch = 0;
double  a = 0, b = 0, sh = 1000, ff = 0, x = 0, s = 0;

double f(double x){
	ff = (13 * (x*x));
	return ff;
}

void vvod(){
	cout << endl << "������� �������� [a,b]" << endl;
	cin >> a;
	cin >> b;
	while ((b - a) < sh) {
		cout << "������� ��� ��������������" << endl;
		cin >> sh;
	}
}

void lp(){
	cout << endl << "����� ����� ���������������" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += f(x)*sh;
		x += sh;
	}
}

void rp(){
	cout << endl << "����� ������ ���������������" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += f(x - (sh / 2)) * sh;
		x += sh;
	}
}

void tr(){
	cout << endl << "����� ��������" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += ((f(x) + f(x + sh))*sh)/2;
		x += sh;
	}
}

void main() {
	setlocale(0, "Russian");
	cout << "���������� ���������" << endl;
	
	while (true){
		ch = 0;
		while ((ch < 1) || (ch > 3)) {
			cout << "�������� �����. 1 - ����� ���������������. 2 - ������ ���������������, 3 - ��������: ";
			cin >> ch;
		}
		switch (ch)
		{
		case 1:
			lp();
			cout << "�����: " << s;
			break;
		case 2:
			rp();
			cout << "�����: " << s;
			break;
		case 3:
			tr();
			cout << "�����: " << s;
			break;
		default:
			break;
		}
		cout << endl << endl << endl << endl;
	}
	system("pause");
}