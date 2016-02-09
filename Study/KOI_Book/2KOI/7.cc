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

int N, P[1<<18];

bool isOne (int a, int s) {
	for (int i=0; i<s; ++i)
		if (P[a+i] != P[a])
			return false;
	return true;
}
void Solve (int a, int s) {
	if (isOne(a, s)) {
		cout << P[a];
		return;
	}
	cout << "-" ;
	Solve (a,s/2);
	Solve (a+s/2, s/2);
}
int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%1d", P+i);

	Solve(0, N); 
	return 0;
}

