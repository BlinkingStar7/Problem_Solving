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

const int MAX = 200201;
int num, len, cnt, size[1001], str[MAX], sa[MAX], ssa[MAX], g[MAX], gg[MAX], c[MAX], owner[MAX], st[MAX][20], r[MAX];

void cs(int k) {
	int m = max(1000, cnt);
	memset(c, 0, sizeof(c));
	for (int i=0; i<cnt; ++i) c[sa[i]+k<cnt ? g[sa[i]+k] : 0]++;
	for (int i=1; i<m; ++i) c[i] += c[i-1];
	for (int i=cnt-1; i>=0; --i)
		ssa[--c[sa[i]+k<cnt ? g[sa[i]+k] : 0]] = sa[i];
	memcpy(sa, ssa, cnt*sizeof(int));
}

int main () {
	scanf("%d%d", &num, &len);
	for (int i=0; i<num; ++i) {
		scanf("%d", size+i);
		for (int j=0; j<size[i]; ++j) {
			int t;
			scanf("%d", &t);
			str[cnt+size[i]*2-j] = str[cnt+j] = t+200;
		}
		str[cnt+=size[i]] = 2*i;
		str[cnt+=size[i]+1] = 2*i+1;
		++cnt;
		if (i != 0) {
			size[i] = size[i]*2 + 2;
			size[i] += size[i-1];
		}
		else
			size[i] = size[i]*2 + 1;

	}

	for (int i=0; i<cnt; ++i) {
		sa[i] = i;
		g[i] = str[i];
	}

	for (int k=1; k<cnt; k<<=1) {
		cs(k); cs(0);
		gg[sa[0]] = 1;
		for (int i=1; i<cnt; ++i)
			gg[sa[i]] = gg[sa[i-1]] + 1 - (g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]);
		memcpy(g, gg, cnt*sizeof(int));
		if (g[sa[cnt-1]] == cnt) break;
	}

	for (int i=0; i<cnt; ++i) {
		r[sa[i]] = i;
		owner[i] = lower_bound(size, size+num, sa[i]) - size;
	}
	for (int i=0, k=0; i<cnt; ++i, k?--k:0) if (r[i]) {
		while (str[i+k] == str[sa[r[i]-1]+k]) ++k;
		st[r[i]][0] = k;
	}

	for (int j=1; (1<<j)<=cnt; ++j) 
		for (int i=0; i+(1<<j)-1<cnt; ++i) 
			st[i][j] = min(st[i][j-1], st[i+(1<<j-1)][j-1]);


	int kind[MAX] = {0}, k=0, left=0, right=-1;
	while (right < cnt) {
		if (k<num) {
			if (kind[owner[++right]]++ == 0) ++k;
		}
		else {
			while (k == num) {
				int size = 31 - __builtin_clz(right - left);
				if (min(st[left+1][size], st[right-(1<<size)+1][size]) >= len) {
					printf("YES\n");
					return 0;
				}
				if (--kind[owner[left++]] == 0) --k;
			}
		}
	}

	printf("NO\n");
	return 0;
}


