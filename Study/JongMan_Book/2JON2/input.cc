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

int testNum;

int main () {
	cin >> testNum;
	cout << testNum << endl;
	while (testNum--) {
		int N = 1+rand()%10, K = 1+rand()%10;
		cout << N << " " << K << endl;
		for (int i=0; i<N; ++i)
			printf("%d ", 1+rand()%10);
		puts("");
			


	}


	return 0;
}

