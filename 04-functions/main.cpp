#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

long double mcalc(double x, long double a2, long long n){
	return pow((-1), n) * pow(x, (2 * n + 1)) / (2 * n + 1) + a2;
}

long double my_arctg(double x, long double eps){
	const long long NMAX = 1000000000000;
	long double a2 = x, a1;
	for(long long n = 1; n < NMAX; n++){
		a1 = mcalc(x, a2, n);
		if (abs(abs(a1) - abs(a2)) < eps)
			return a1;
		a2 = a1;
	}
	return a1; //вывод при недостаточной точности
}

int main(){
	const long double EPS = 0.0000000001;
	double x1, x2, dx;
	long double a1, eps;
	const long long NMAX = 1000000000000;
	cout << fixed;
	cout << "in arctg(x), -1 <= x <= 1" << endl <<"Write x1, x2, dx, eps ";   
	cin >> x1 >> x2 >> dx >> eps;
	if ((abs(dx) < EPS) || (abs(x1) > 1) || (abs(x2) > 1)){
        cout << "wrong input" << endl;
        return 2;
    }
	cout << endl << string(40, '-') << endl << "|";
	cout << setw(13) << "X|" << setw(13) << "arctg(x)|" << setw(13) << "P-d arctg(x)|";
	cout << endl << string(40, '-') << endl;

	for(double x = x1; x < x2; x += dx){ 
		a1 = my_arctg(x, eps);

		cout << "|" <<setw(12) << x << "|";
		cout << setw(12) << a1 << "|" << setw(12) << atan(x) << "|" << endl;
	} 
	cout << string(40, '-') << endl;
	return 0;
}
