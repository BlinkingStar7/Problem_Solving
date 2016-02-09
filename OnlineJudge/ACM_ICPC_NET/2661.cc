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

int N, Arr[1000000];
bool MakeGoodSequence(int p) {
	if (p == N) return true;

	bool ret = false;
	vector<bool> cand(4, true);
	for (int len=1; len<=(p+1)/2; ++len) {
		int s=p-len*2+1, ss=p-len+1;
		bool flag = true;
		for (int i=0; i<len-1; ++i) {
			if (Arr[s+i] != Arr[ss+i]) {
				flag = false;
				break;
			}
		}	
		if (flag) 
			cand[Arr[s+len-1]] = false;
	}

	for (int i=1; i<=3; ++i) {
		if (cand[i]) {
			Arr[p] = i;
			ret = ret || MakeGoodSequence(p+1);
			if (ret) return true;
		}
	}
	return false;
}


int main () {
	cin >> N;
	MakeGoodSequence(0);
	for (int i=0; i<N; ++i)
		printf("%d",Arr[i]);
	puts("");
	return 0;
}

