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

string S;
int M;
int main () {
	cin >> S >> M;

	for (int i=0; i<M; ++i) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		k %= (r-l+1);
		int start=l-1, end=r-1, cut=end-k+1;
		string mid = S.substr(cut, end-cut+1) + S.substr(start, (cut-1)-start+1);
		S = S.substr(0, l-1) + mid + S.substr(end+1);
		cout << S << endl;
	}




	return 0;
}

