#include <iostream>
#include <string>
#define N 8

using namespace std;

struct train{
	string dest;
	unsigned int number;
	string time;
};

void inputTrain(train *a){
	for (int i = 0; i < N; i++){
		cout << "destanation: ";
		getline(cin, a[i].dest);
		cout << "number: ";
		cin >> a[i].number;
		cout << "departure time: ";
		cin >> a[i].time;
		cin.ignore();
	}
}

void sortTrain(train *a){
	bool swaped;
	for (int i = 0; i < N - 1; i++){
		swaped = false;
		for (int j = 0; j < N -i -1; j++)
			if (a[j].number > a[j + 1].number){
                swap(a[j], a[j + 1]);
				swaped = true;
			}
		if (!swaped)
			break;
	}
}

void searchTrain(train *a, int num){
	for (int i = 0; i < N; i++){
		if (num == a[i].number){
			cout << "destanation: "<< a[i].dest << endl;
			cout << "train number: "<< a[i].number << endl;
			cout << "departure time: "<< a[i].time << endl;
			break;
		}
		if (i == N -1)
			cout << "no such train" << endl;
	}
}

void infinite(train *a){
	int num;
	cout << "write the train number (to quit write -1)" << endl;
	while(1){
		cin >> num;
		if (num == -1)
			break;
		searchTrain(a, num);
	}
}

int main(){
	train a[N];
	inputTrain(a);
	sortTrain(a);
	cout << endl;
	infinite(a);
	return 0;
}
