#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, H[3001];
pair<int, string> A[3001];


int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a;
		string s;
		cin >> s >> a;
		A[i] = make_pair(a, s);
	}

	sort (A, A+N);

	for (int i=0; i<N; ++i)
		if (A[i].first > i) {
			cout << -1 << endl;
			return 0;
		}

	int h = 1, pos=0;
	while (1) {
		int first = -1;
		for (int i=0; i<N; ++i)
			if (H[i] == 0) {
				first = i;
				break;
			}
		if (first == -1) break;
		
		int num = 0, next = -1;

		for (int i=first; i<N; ++i) {
			if (H[i] == 0) {
				if (A[i].first == num)
					next = i;
				++num;
			}
		}
		H[next] = h++;
	}

	for (int i=0; i<N; ++i) 
		cout << A[i].second << " " << H[i] << endl;
			


	return 0;
}

