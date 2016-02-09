#include <iostream>
using namespace std;

int N, ori[7], Left[7],mass[7] = {1, 3, 9, 27, 81, 243, 729};

int main() {
	cin >> N;
	cout << N << ' ';
	for (int i=0; i<7; ++i) {
		ori[i] = N % 3;
		N /= 3;
	}
	for (int i=0; i<7; ++i) {
		if (ori[i] == 2) {
			Left[i] = 1;
			ori[i] = 0;
			ori[i+1] += 1;
		}
		if (ori[i] == 3) {
			ori[i] = 0;
			ori[i+1] += 1;
		}
	}

	for (int i=0; i<7; ++i)
		if (Left[i])
			cout << mass[i] << ' ';
	cout << "0 ";
	for (int i=0; i<7; ++i)
		if (ori[i])
			cout << mass[i] << ' ';
	return 0;
}


