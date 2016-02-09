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

const int MAX =987654321;
int Memo[1<<21], testNum, N, M, canEat[51][51];
string Friends[51];

int Dp (long long state) {
	int &ret = Memo[state & (1<<20)-1];
	if (ret != -1) return ret;

	if ((state & (1LL<<N)-1) == (1LL<<N)-1 || (state & (1LL<<20)-1) == (1LL<<20)-1) return ret = 0;

	int first = -1;
	ret = MAX;

	for (int i=0; i<N; ++i)
		if ((state & 1LL<<i) == 0) {
			first = i;
			break;
		}

	for (int meal=0; meal<M; ++meal) {
		if (canEat[first][meal]) {
			long long newEat = 0;
			for (int i=0; i<N; ++i)
				if (canEat[i][meal])
					newEat += 1LL<<i;
			ret = min (ret, 1+Dp(state | newEat));
		}
	}
	return ret;
}

int Solve(long long state) {
	if (state == (1LL<<N)-1) return 0;
	if (N <= 20 || (state>>20) == (1LL<<N-20)-1) return Dp (state & (1LL<<20)-1);

	int ret=MAX, first=-1;
	for (int i=N-1; i>=0; --i)
		if ((state & 1LL<<i) == 0) {
			first = i;
			break;
		}

	for (int meal=0; meal<M; ++meal) {
		if (canEat[first][meal]) {
			long long newEat = 0;
			for (int i=0; i<N; ++i)
				if (canEat[i][meal])
					newEat += 1LL<<i;
			ret = min (ret, 1+Solve(state | newEat));
		}
	}

	return ret;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		memset(canEat, 0, sizeof(canEat));
		memset(Memo, -1, sizeof(Memo));
		cin >> N >> M;
		for(int i=0; i<N; ++i)
			cin >> Friends[i];

		for(int meal=0; meal<M; ++meal) {
			int K;
			cin >> K;
			for (int i=0; i<K; ++i) {
				string name;
				cin >> name;
				for (int j=0; j<N; ++j)
					if (Friends[j] == name) {
						canEat[j][meal] = 1;
						break;
					}
			}
		}

		cout << Solve(0) << endl;



	}


	return 0;
}

