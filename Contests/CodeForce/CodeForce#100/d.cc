#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	int N, A[101];
	cin >> N;
	for (int i=0; i<N; ++i) 
		scanf("%d", A+i);
	sort(A, A+N);
	int num=0, pen=0, cur=10;
	for (int i=0; i<N; ++i) {
		if (cur + A[i] <= 360) {
			++num;
			cur += A[i];
		}
		else if (cur + A[i] <= 720) {
			++num;
			cur += A[i];
			pen += cur - 360;
		}
		else break;
	}
	cout << num << " " << pen << endl;

	return 0;
}

