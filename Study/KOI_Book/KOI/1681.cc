#include <iostream>
using namespace std;
#define MAX 987654321
#include <cstring>
int N, G[13][13], memo[13][(1<<12)-1];

int Solve (int cur, int set) {
	if (cur == 0) return set == ((1 << N) - 1) ? 0 : MAX;
	int &ret = memo[cur][set];
	if (ret != -1) return ret;
	ret = MAX;
	for (int i=0; i<N; ++i) 
		if (G[cur][i] && (set & (1 << i)) == 0)
			ret = min (ret, G[cur][i] + Solve(i, set | (1 << i)));

	return ret;
}

int main() {
	cin >> N;
	memset(memo, -1, sizeof(memo));
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			cin >> G[i][j];
	int ret = MAX;
	for (int i=0; i<N; ++i) 
		if (G[0][i]) ret = min (ret, G[0][i] + Solve(i, 1 << i));
	cout << ret << endl;
	return 0;
}

