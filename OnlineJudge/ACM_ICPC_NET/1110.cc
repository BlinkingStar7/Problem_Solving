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


int main () {
	int n=0, a;
	scanf("%d", &a);
	int num = a;
	while(1) {
		++n;
		num = 10*(num%10) + (num/10 + num%10)%10;
		if (num == a) break;
	}
	cout << n << endl;

	return 0;
}

