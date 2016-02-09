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

int N, A[100001];

int Solve (int a, int b) {
	if (a == b) return 1;
	
	int mid = (a+b)/2;
	int cand = max(Solve(a,mid), Solve(mid+1,b));

	int l, h;

	for (l=mid; l>=a && A[l] <= A[l+1]; --l);
	for (h=mid+1; h<=b && A[h] >= A[h-1]; ++h);

	return max (cand, h-l-1);
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d", &A[i]);

	cout << Solve(0, N-1) << endl; 
	return 0;
}

