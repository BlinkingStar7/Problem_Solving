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
	int n;
	cin >> n;

	int sum =0;
	while (n != 0) {
		sum += n %2;
		n /= 2;
	}
	cout << sum << endl;

	return 0;
}

