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

int main () {
	long long n;
	cin >> n;


	long long sqrtn = (long long)sqrt(n);
	for (long long i=2; n != 1 && i<=sqrtn; ++i)
		while (n % i == 0) {
			cout << i << endl;
			n/=i;
		}
	if (n != 1) cout << n << endl;
	return 0;
}

