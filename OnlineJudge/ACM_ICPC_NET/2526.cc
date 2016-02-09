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


int N, P, A[100];
int main () {
	cin >> N >> P;

	int num = N, cur = 1;
	while (1) {
		if (A[num%P] != 0) {
			cout << cur - A[num%P] << endl;
			break;
		}

		A[num%P] = cur++;
		num = (num*N)%P;
	}
	
	return 0;
}

