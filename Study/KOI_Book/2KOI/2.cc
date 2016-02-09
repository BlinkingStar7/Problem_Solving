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

int Solve(int a, int b) {
	if (a==b) return 0;
	else if (a>b) return 1+Solve(a/2, b);
	else return 1+Solve(a,b/2);
}

int main () {
	int a, b;
	cin >> a >> b;
	cout << Solve(a, b) << endl;
	return 0;
}

