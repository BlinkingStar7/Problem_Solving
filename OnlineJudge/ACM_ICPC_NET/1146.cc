#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {

	int N, A[101];
	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> A[i];

	for (int i=0; i<N-1; ++i) {
		int min = i;
		for (int j=i+1; j<N; ++j)
			if (A[j] < A[min])
				min = j;

		int temp = A[min];
		A[min] = A[i];
		A[i] = temp;

		for (int j=0; j<N; j++)
			printf("%d ", A[j]);
		cout << endl;
	}

	return 0;
}


