#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, z1, z2;
	cout << "Write a ";
	cin >> a;
	cout << "Write b ";
	cin >> b;

	z1 = pow((cos(a) - cos(b)), 2) - pow((sin(a) - sin(b)), 2);

	z2 = -4 * pow(sin((a - b) / 2), 2) * cos(a + b);
	
	cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl;
	return 0;
}
