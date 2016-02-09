#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string Key, M[2];
int memo[21][101][2];
int Solve (int keyIndex, int curIndex, int bridge) {
	if (keyIndex == Key.size())
		return 1;

	int &ret = memo[keyIndex][curIndex+1][bridge];
	if (ret != -1) return ret;

	ret = 0;

	for (int next = curIndex + 1; next < M[bridge].size(); ++next) {
		if (M[bridge][next] == Key[keyIndex])
			ret += Solve (keyIndex + 1, next, bridge == 1 ? 0 : 1);
	}
	return ret;
}

int main () {
	cin >> Key >> M[0] >> M[1];

	memset(memo, -1, sizeof(memo));
	cout << Solve (0, -1, 0)+ Solve (0, -1, 1) << endl;
	return 0;
}
