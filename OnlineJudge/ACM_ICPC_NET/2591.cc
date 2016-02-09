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


char num[41];
int D[42];

int main () {
	scanf("%s", num);
	int len = strlen(num);

	D[len] = 1;
	for (int i=len-1; i>=0; --i) {
		if (num[i] == '0') continue;
		D[i] = D[i+1];
		if (num[i] <= '2' || (num[i] == '3' && num[i+1] <= '4'))
			D[i] += D[i+2];
	}
	cout << D[0] << endl;


	return 0;
}

