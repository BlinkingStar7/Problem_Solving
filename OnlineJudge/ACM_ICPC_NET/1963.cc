#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int n;
bool isComp[10001];

int main () {
	int n;
	scanf("%d", &n);
	int sqrtn = sqrt(10000);
	for (int i=2; i<sqrtn; ++i) if (!isComp[i]) {
		for (int j=i*i; j<=10000; j+=i)
			isComp[j] = true;
	}
	
	for (int i=0; i<n; ++i) {
		int a, b, d[10001];
		memset(d, -1, sizeof(d));
		scanf("%d%d",&a,&b);
		queue<int> q;
		q.push(a); d[a] = 0;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (cur == b) {
				printf("%d\n", d[b]);
				break;
			}

			for (int mul=1; mul<=1000; mul*=10) {
				for (int jj=0; jj<10; ++jj) {
					if ((cur/mul)%10 == jj) continue;
					if (mul == 1000 && jj == 0) continue;
					int next = ((cur/mul)/10*10 + jj)*mul + cur%mul;
					if (!isComp[next] && d[next] == -1) {
						d[next] = d[cur] + 1;
						q.push(next);
					}
				}
			}
		}
	}
	return 0;
}



