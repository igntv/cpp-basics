#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#define N 10

using namespace std;

int main(){
	double a[N][N], b[N][N];
	int q;
	cout << "Choose input: (1 - file, 2 - long one) ";
	cin >> q;
	if (q == 1){
		string s;
		cout << "Write file name ";
		cin >> s;
		ifstream fin(s);
		if (!fin.is_open()){
			cout << "can't open file" << endl;
			return 1;
		}

		for (int j = 0; j < N; j++)
	        for(int i = 0; i < N; i++)
		        fin >> a[i][j];

		fin.close();
	}
	else
		if (q == 2){
			cout << "Write a matrix 10 x 10" << endl;

			for (int j = 0; j < N; j++)
				for(int i = 0; i < N; i++)
					cin >> a[i][j];
		}
		else{
			cout << "wrong q!" << endl;
			return 2;
		}

	double sum = 0, sumabs = 0;
	int s = 0;

	for (int j = 0; j < N; j++){
		for (int i = 0; i < N; i++){	//out-of-border check

			for (int k = -1; k <= 1; k++){
				for (int l = -1; l <= 1; l++){
					if ((i + k) >= 0 && (i + k) < N &&
						(j + l) >= 0 && (j + l) < N &&
						(k != 0 || l != 0))
					{
						sum += a[i + k][j + l];
						s++;
					}				
				}
			}



			b[i][j] = sum / s;
			sum = s = 0;
			cout << setw(5) << fixed << b[i][j] << "|";

			if (j > i)
				sumabs += fabs(b[i][j]);
		}
		cout << endl;
	}

	cout << "sum of abs = " << sumabs << endl;
	return 0;
}
