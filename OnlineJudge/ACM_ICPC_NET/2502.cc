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

int Fib[33];
int main () {
	int D, K;
	cin >> D >> K;

	Fib[1] = 1;
	for (int i=2; i<=D; ++i)
		Fib[i] = Fib[i-1] + Fib[i-2];

	int a=1;
	while(1) {
		if ((K-Fib[D]*a)%Fib[D-1] == 0) {
			cout << a << endl << a + (K-Fib[D]*a)/Fib[D-1] << endl;
			return 0;
		}
		++a;
	}
	
	return 0;
}

