#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int N, next[MAX], last[MAX], kind;
string A, B;
bool V[MAX];

int main() {
	scanf("%d", &N);
	
	cin >> A;
	B = A;
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	int total = B.size();

	memset(next, -1, sizeof(next));
	memset(last, -1, sizeof(last));
	
	for (int i=0; i<N; ++i) {
		char c = A[i];
		if (last[c] != -1) next[last[c]] = i;
		last[c] = i;
	}


	int ans = 987654321;
	queue<pair<char, int> > q;
	for (int i=0; i<N; ++i) {
		char c = A[i];
		q.push(make_pair(c, i));

		if (!V[c]) { ++kind; V[c] = true; }
		
		while (next[q.front().second] != -1 && next[q.front().second] <= i)
			q.pop();

		if (kind == total) ans = min(ans, (int)q.size());
	}

	printf("%d\n", ans);
	return 0;
}


