#include <bits/stdc++.h>
using namespace std;

string wildcard, temp;
int memo[101][101];

bool solve(int wPos, int tPos) {
	if (wPos == wildcard.size()) return tPos == temp.size();
	if (tPos == temp.size()) {
		while (wPos < wildcard.size())
			if (wildcard[wPos++] != '*')
				return false;
		return true;
	}

	int &ret = memo[wPos][tPos];
	if (ret != -1) return ret;
	
	ret = 0;
	
	if (wildcard[wPos] == '?' || wildcard[wPos] == temp[tPos]) return ret = solve(wPos+1, tPos+1);
	else if (wildcard[wPos] == '*') {
		for (int next = tPos; next <= temp.size() && !ret; ++next)
			ret = ret || solve(wPos+1, next);
		return ret;
	}
	return ret = false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> wildcard;
		int n;
		scanf("%d", &n);

		vector<string> ans;
		for (int i=0; i<n; ++i) {
			cin >> temp;
			memset(memo, -1, sizeof(memo));
			if (solve(0, 0))
				ans.push_back(temp);
		}

		sort(ans.begin(), ans.end());
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << endl;
	}
	return 0;
}

