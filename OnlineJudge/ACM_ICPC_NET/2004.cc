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

int MultipleNum (int a, int b, int num) {
	if (a > b) return 0;
	if (a%num != 0 || b%num != 0) return MultipleNum ((a+num-1)/num*num, b/num*num, num);
	return (b-a)/num +1 + MultipleNum(a/num, b/num, num);
}

int main () {
	int n, m;
	cin >> n >> m;

	int five = MultipleNum(n-m+1, n, 5) - MultipleNum(1, m, 5);
	int two = MultipleNum(n-m+1, n, 2) - MultipleNum(1, m, 2);

	int zero = min (five, two);
	cout << (zero<0 ? 0 : zero) << endl;
	return 0;
}

