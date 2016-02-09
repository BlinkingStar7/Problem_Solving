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
	long long n, sum=0, i;
	cin >> n;
	for (i=1; i*i<n; ++i)
		if (n % i == 0) sum += i + (n/i);
	if (i*i == n)
		sum += i;
	cout << sum << endl;
	return 0;
}

