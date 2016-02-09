#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int A[5];
int main() {
	int s = 0;
	for (int i=0; i<5; ++i) {
		scanf("%d", &A[i]);
		s += A[i];
	}
	sort(A, A+5);
	cout << s/5 << endl <<  A[2] << endl;

	return 0;
}


