#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	double x1, x2, dx;
	long double a1, a2, eps;
	const long long NMAX = 100000000000;
	const long double EPS = 0.000000001;
	cout << fixed;
	cout << "in arctg(x), -1 <= x <= 1" << endl << "Write x1, x2, dx, eps ";
	cin >> x1 >> x2 >> dx >> eps;
	if ((abs(dx) < EPS) || (abs(x1) > 1) || (abs(x2) > 1)){
		cout << "wrong input" << endl;
		return 2;
	}
	cout << endl << string(51, '-') << endl << "|";
	cout << setw(13) << "X|" << setw(13) << "arctg(x)|" << setw(11) << "n|";
	cout << setw(13) << "P-d arctg(x)|" << endl << string(51, '-') << endl;
	int k;

	for(double x = x1; x < x2; x += dx){ 
		a2 = x; 
		for(long long n = 1; n < NMAX; n++){
			k = n;
			a1 = pow((-1), n) * pow(x, (2 * n + 1)) / (2 * n + 1) + a2;
			if(abs(abs(a1) - abs(a2)) < eps)
				break;
			a2 = a1;
			if ((NMAX - n) < 2){
				cout << "too small exp";
				return 1;
			}
		}
		cout << "|" << setw(12) << x << "|" << setw(12) << a1;
		cout << "|" << setw(10) << k << "|" << setw(12) << atan(x) << "|" << endl;
	} 
	cout << string(51, '-') << endl;
	return 0;
}
