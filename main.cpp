#include <iostream>
#include <math.h>

using namespace std;
int ch = 0;
double  a = 0, b = 0, sh = 1000, ff = 0, ffa = 0, ffb = 0, x = 0, s = 0;

double f(double x){
	ff = (13 * (x*x));
	return ff;
}

double fa(double a){
	ffa = (13 * (a*a));
	return ffa;
}

double fb(double b){
	ffb = (13 * (b*b));
	return ffb;
}

void vvod(){
	cout << endl << "Введите диапозон [a,b]" << endl;
	cin >> a;
	cin >> b;
	sh = 1000;
	if (ch != 4){
		while ((b - a) < sh) {
			cout << "Введите шаг интегрирования" << endl;
			cin >> sh;
		}
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
		s += ((f(x) + f(x + sh))*sh) / 2;
		x += sh;
	}
}

void sim(){
	// ((b-a) / 6) * (fa(a) + 4*f(x)((a+b)/2)) + fb(b));
	cout << endl << "Формула Симпсона" << endl;
	vvod();
	//s = ((b - a) / 6) * (fa(a) + 4 * f((a + b) / 2) + fb(b));
	double n = 1000;
	sh = (b - a) / n;
	for (int i = 0; i < n / 2; i++)
	{
		s = s + fa(a) + (4 * fa(a + sh)) + (fa(a + 2 * sh));
		a = a + 2 * sh;
	}
	s = (s*sh) / 3;
}

void main() {
	setlocale(0, "Russian");
	cout << "Вычисление интеграла" << endl;

	while (true){
		ch = 0;
		s = 0;
		while ((ch < 1) || (ch > 4)) {
			cout << "Выберите метод. 1 - левых прямоугольников. 2 - равных прямоугольников, 3 - трапеций, 4 - метод Симпсона: ";
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
		case 4:
			sim();
			cout << "Ответ: " << s;
			break;
		default:
			break;
		}
		cout << endl << endl << endl << endl;
	}
	system("pause");
}