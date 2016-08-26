#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 300005;
int N, Q, num;
bool V[MAX];
queue<int> q[MAX], global;

int main() {
	scanf("%d%d", &N, &Q);

	int cnt = 0;
	for (int i=0; i<Q; ++i) {
		int cmd, x;
		scanf("%d%d", &cmd, &x);
		
		if (cmd == 1) { 
			global.push(cnt); 
			q[x].push(cnt); 
			V[cnt] = true;
			++cnt;
			++num; 
		}
		if (cmd == 2) { 
			while (!q[x].empty()) {
				int cur = q[x].front(); q[x].pop();
				if (!V[cur]) continue;
				V[cur] = false;
				--num;
			}
		}
		if (cmd == 3) {
			while (!global.empty() && global.front() < x) {
				int cur = global.front(); global.pop();
				if (!V[cur]) continue;
				V[cur] = false;
				--num;
			}
		}
		printf("%d\n", num);
	}

	return 0;
}				
