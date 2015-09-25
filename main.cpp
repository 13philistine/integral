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
	cout << endl << "Введите диапозон [a,b]" << endl;
	cin >> a;
	cin >> b;
	while ((b - a) < sh) {
		cout << "Введите шаг интегрирования" << endl;
		cin >> sh;
	}
}

void lp(){
	cout << endl << "Метод левых прямоугольников" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += f(x)*sh;
		x += sh;
	}
}

void rp(){
	cout << endl << "Метод равных прямоугольников" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += f(x - (sh / 2)) * sh;
		x += sh;
	}
}

void tr(){
	cout << endl << "Метод трапеций" << endl;
	vvod();
	x = a;
	while (x < b) {
		s += ((f(x) + f(x + sh))*sh)/2;
		x += sh;
	}
}

void main() {
	setlocale(0, "Russian");
	cout << "Вычисление интеграла" << endl;
	
	while (true){
		ch = 0;
		while ((ch < 1) || (ch > 3)) {
			cout << "Выберите метод. 1 - левых прямоугольников. 2 - равных прямоугольников, 3 - трапеций: ";
			cin >> ch;
		}
		switch (ch)
		{
		case 1:
			lp();
			cout << "Ответ: " << s;
			break;
		case 2:
			rp();
			cout << "Ответ: " << s;
			break;
		case 3:
			tr();
			cout << "Ответ: " << s;
			break;
		default:
			break;
		}
		cout << endl << endl << endl << endl;
	}
	system("pause");
}