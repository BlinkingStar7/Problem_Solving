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
	int N, K;
	cin >> N >> K;
	vector<int> div;
	int sqrtN = sqrt(N);
	for (int i=1; i<= sqrtN; ++i) 
		if (N%i==0)
			div.push_back(i);

	if (K <= div.size()) {
		cout << div[K-1] << endl;
		return 0;
	}

	K -= div.size();

	if (sqrtN*sqrtN == N)
		div.pop_back();

	if (K > div.size()) {
		cout << 0 << endl;
		return 0;
	}

	cout << N/div[div.size()-K] << endl;

	return 0;
}

