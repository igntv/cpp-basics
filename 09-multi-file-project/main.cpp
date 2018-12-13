#include "myheader.hpp"

int main(){
	int n;
	cout << "Write n, n > 0 ";
	cin >> n;
	if (n <= 0){
		cout << "error, n <= 0" << endl;
		return 1;
	}
	double *a = new double[n], errche;
	cout << "input the array ";

	readarr(a, n);
	printarr(a, n);

	cout << "Abs max = " << absmax(a, n) << endl;
	errche = sumbpos(a, n);
	if (errche == 1)
		cout << "there are no 2 positive elements";
	else
		cout << "sum = " << errche << endl;

    badsort(a, n);

	printarr(a, n);
	delete [] a;
	cout << endl;
	return 0;
}
