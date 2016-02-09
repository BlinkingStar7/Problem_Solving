#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int n;
	cin >> n;
	srand(time(NULL));

	cout << n <<' '<< rand() % 10000000 + 1 << endl;
	for (int i=0; i<n; ++i)
		cout << rand() % 10000000 + 1 << endl;
	for (int i=0; i<n; ++i)
		cout << rand() % 100 + 1 << endl;
	return 0;
}

