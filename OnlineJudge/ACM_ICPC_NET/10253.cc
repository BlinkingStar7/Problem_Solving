#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int A, B;

int GCD (int a, int b) {
	if (a > b) return GCD (b, a);
	if (a == 1) return 1;
	if (b%a == 0) return a;
	return GCD (b%a, a);
}

int Solve (int a, int b) {
	if (b%a==0) return b/a;

	int q = b/a + 1;
	int na = a*q - b, nb = b*q, gcd = GCD (na, nb);

	return Solve (na/gcd, nb/gcd);
}

int main() {
	int tN;
	cin >> tN;

	while (--tN >= 0) {
		cin >> A >> B;
		
		cout << Solve (A, B) << endl;
	}

	return 0;
}


