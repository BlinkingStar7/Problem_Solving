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

int ans ;
int findClockNum (vector<int>& num) {
	int ret = 9999;
	for (int i=0; i<4; ++i) {
		int cand = 0;
		for (int j=0; j<4; ++j) {
			cand*=10;
			cand+=num[(i+j)%4];
		}
		ret = min (ret, cand);
	}
	return ret;
}

bool isClockNum(int num) {
	vector<int> digit(4);
	int div=1;
	for (int i=0; i<4; ++i) {
		digit[3-i] = (num/div)%10;
		div*=10;
		if (digit[3-i]==0) return false;
	}

	for (int i=1; i<4; ++i) {
		int cand = 0;
		for (int j=0; j<4; ++j) {
			cand*=10;
			cand+=digit[(i+j)%4];
		}
		if (cand < num) return false;
	}
	return true;
}

int main () {
	vector<int> num(4);
	for (int i=0; i<4; ++i)
		scanf("%d", &num[i]);

	int clockNum = findClockNum (num);
	for (int i=1111; i<=clockNum; ++i) {
		if (isClockNum(i)) ++ans;
	}
	cout << ans << endl;
	return 0;
}

