#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
using namespace std;


int main () {

	int N, Arr[101];
	cin >> N;


	for (int i=0; i<N; ++i) {
		cin >> Arr[i];
	}
	
	int ans = 0, home = 1;

	for (int i=0; i<N; ++i) {
		if (Arr[i] == 1) {
			++ ans;
			home = 0;
		}
		else if (!home && Arr[i] == 0) {
			if (i == N-1 || Arr[i+1] == 0) {
				home = 1;
			}
			else
				++ ans;
		}
	}
	cout << ans << endl;
	return 0;
}

