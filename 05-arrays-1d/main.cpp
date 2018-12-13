#Include <iostream>
#include <cmath>
#define EPS 0.00000001

using namespace std;

void badsort(double * a, int n){
	for (int j = 0; j < n; j++)
		for (int i = 1; i < n - j; i++)
			if ((fabs(a[i - 1]) < EPS) && (fabs(a[i]) > EPS))
				swap(a[i - 1], a[i]);
}

int main(){
	int n, iabsmax = 0;
	bool pos1 = false, pos2 = false;
	cout << "Write n, n > 0 ";
	cin >> n;
	if (n <= 0){
		cout << "error, n <= 0" << endl;
		return 1;
	}
	double *a = new double[n], absmax, sum = 0;
	cout << "input the array ";
	cin >> a[0];
	absmax = fabs(a[0]);

	for (int c = 1; c < n; c++){
		cin >> a[c];
		if (fabs(a[c]) > absmax){
			absmax = fabs(a[c]);
			iabsmax = c;
		}

		if (!pos1){
			if (a[c] > EPS)
				pos1 = true;
		}
		else 
			if (!pos2){
				if (a[c] > EPS)
					pos2 = true;
				else
					sum += a[c];
			}

	}
	
	for (int j = 0; j < n; j++)
		cout << a[j] << " | ";

	cout << endl << "Abs max = a[" << iabsmax << "] = " << absmax << endl;

	if (pos1 && pos2)
		cout << "sum = " << sum << endl;
	else
		cout << "there are no 2 positive elements" << endl; 

	
    badsort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

	delete [] a;
	cout << endl;
	return 0;
}
