#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
using namespace std;

int testNum;
int GCD (int a, int b) {
	return a==0? b : GCD(b%a, a);
}


int main () {
	cin >> testNum;

	while (testNum--) {
		int a, b;
		cin >> a >> b;
		cout << a*b/GCD(a,b) << endl;


	}


	return 0;
}

