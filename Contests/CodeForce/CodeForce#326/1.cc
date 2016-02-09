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
#include <numeric>
using namespace std;

int N;

int main () {
	cin >> N;
	int money = 0, price = 987654321;
	for (int i=0; i<N; ++i) {
		int a, p;
		scanf("%d %d", &a, &p);
		if (p < price) price = p;
		money += price*a;
	}
	cout << money << endl;
		



	return 0;
}

