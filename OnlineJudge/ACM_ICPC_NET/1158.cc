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

	for (int cur=1; cur<N; ++cur) {
		int i, num = A[cur];
		for (i=0; i<cur; ++i)
			if (A[i] > A[cur])
				break;
		for (int j=cur-1; j>=i; --j)
			A[j+1] = A[j];
		A[i] = num;
		for (int i=0; i<N; ++i)
			printf("%d ", A[i]);
		cout << endl;
	}


			

	return 0;
}


