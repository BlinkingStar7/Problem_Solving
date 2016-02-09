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
#include <numeric>
using namespace std;

const int MOD = 20090711;
int testNum;

int main () {
	cin >> testNum;

	while (testNum--) {
		int N, A, B, r = 1983, sum = 0;
		cin >> N >> A >> B;
		priority_queue<int, vector<int>, less<int> > maxHeap;
		priority_queue<int, vector<int>, greater<int> > minHeap;
		
		for (int i=0; i<N; ++i) {
			if (maxHeap.size() == minHeap.size()) 
				maxHeap.push(r);
			else
				minHeap.push(r);
			if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
				int a = minHeap.top(), b = maxHeap.top();
				minHeap.pop(), maxHeap.pop();
				minHeap.push(b), maxHeap.push(a);
			}

			sum = (sum + maxHeap.top()) % MOD;
			r = ((long long)r*A + B) % MOD;
		}
		cout << sum << endl;
	}


	return 0;
}

