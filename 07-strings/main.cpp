#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	cout << "write file name ";
	string filename, s = "";
	cin >> filename;
	ifstream fin(filename);
	if (!fin.is_open()){
		cout << "can't open file!" << endl;
		return 1;
	}
	char a;
	int n, k = 0;
	cout << "write the number of words ";
	cin >> n;
	while(fin.get(a)){	
		if (a == '\n')
			s += ' ';
		else
			s += a;
		if ((a == ' ') || (a == '\n')){
			k++;
		}

		if ((a == '.')||(a == '?')||(a == '!')){
			if (k == (n - 1))
				cout << s << endl;
				fin.get(a); //avoiding first space in sentence
			k = 0;
			s = "";
		}
	}

	if (!fin.eof()){
		cout << "error: EoF unreached" << endl;
		return 2;
	}
	fin.close();
	return 0;
}
