#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define N 10

using namespace std;

template <class type>
void smooth(type (&a)[N][N], type (&b)[N][N]){
	type sum = 0;
	int s = 0;
	for (int j = 0; j < N; j++){
        for (int i = 0; i < N; i++){

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
            sum = 0;
			s = 0;
		}
	}
}

template <class type>
void arrinput(type (&a)[N][N], ifstream &fin){
	 for (int j = 0; j < N; j++)
            for(int i = 0; i < N; i++)
                fin >> a[i][j];
}

template <class type>
void arroutput(type (&a)[N][N]){
	cout << fixed;
	for (int j = 0; j < N; j++){
		for (int i = 0; i < N; i++)
			cout << a[i][j] << " ";
	cout << endl;
	}
	cout << defaultfloat;
}

int main(){
	char ans;
    string s;
	while(1){
		cout << "Write file name (to quit write \".\") ";
		cin >> s;
		if (s == ".")
			return 0;
		ifstream fin(s);
		if (!fin.is_open()){
			cout << "can't open file" << endl;
			continue;
		}   

		link:
		cout << "choose type: (0 - double, 1 - float, 2 - int) (to quit write \".\") ";
		cin >> ans;

		if (ans == '.')
			continue;

		if (ans == '0'){
			double a[N][N], b[N][N];
			arrinput(a, fin);
			smooth(a, b);
			arroutput(b);
		}
		else
			if (ans == '1'){
				float a[N][N], b[N][N];
				arrinput(a, fin);
				smooth(a, b);
				arroutput(b);
			}
			else
				if (ans == '2'){
					int a[N][N], b[N][N];
					arrinput(a, fin);
					smooth(a, b);
					arroutput(b);
				}
				else{
					cout << "wrong type" << endl;
					goto link;
				}

		fin.close();
	}
	return 0;
}
