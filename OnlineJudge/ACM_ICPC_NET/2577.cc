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

int Num[10];

int main () {
	int x, num=1;
	for (int i=0; i<3; ++i) {
		scanf("%d", &x);
		num *= x;
	}
	while (num) {
		Num[num%10]++;
		num/=10;
	}
	for (int i=0; i<10; ++i)
		cout << Num[i] << endl;

	

	return 0;
}

