#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int K, X[7], Y[7];

int main () {
	cin >> K;
	for (int i=0; i<6; ++i) {
		int a, l;
		scanf("%d %d", &a, &l);
		if (a==1) X[i]=X[i-1]+l, Y[i]=Y[i-1];
		if (a==2) X[i]=X[i-1]-l, Y[i]=Y[i-1];
		if (a==3) X[i]=X[i-1], Y[i]=Y[i-1]+l;
		if (a==4) X[i]=X[i-1], Y[i]=Y[i-1]-l;
	}
	int A=0;
	for (int i=0; i<6; ++i)
		A+=X[i]*Y[(i+1)%6] - Y[i]*X[(i+1)%6];
	cout << abs(A/2*K) << endl;
}

