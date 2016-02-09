#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;

int N, P[301][301];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d", &P[i][j]);

	map<int, int> myPref;
	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		myPref[t] = i;
	}

	for (int f=0; f<N; ++f) {
		for (int i=0; i<N; ++i) {
			if (P[f][i] == f+1) continue;
			bool flag = true;
			for (int j=1; j<P[f][i]; ++j)
				if (j != f+1 && myPref[j] < myPref[P[f][i]]) {
					flag = false;
					break;
				}
			if (flag) {
				printf("%d ", P[f][i]);
				break;
			}
		}
	}
	cout << endl;
	return 0;
}

