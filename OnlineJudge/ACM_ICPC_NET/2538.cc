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

<<<<<<< HEAD
int x[500001], y[500001], p[500001], n, w, h;

inline pos(int ii) {
=======
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

#define START 1
#define END 2
int w, h, n, x[500001], y[500001], p[500001], num, start;
long long best = -1;

inline bool isEdge(int ii) {
	int cur = ii, next = (ii+1)%n;
	if (x[cur] == x[next]) return x[cur] == 0 || x[cur] == w;
	else return y[cur] == 0 || y[cur] == h;
}

inline int len(int ii, int jj) {
	return abs(x[ii] - x[jj]) + abs(y[ii] - y[jj]);
}

inline int pos(int ii) {
>>>>>>> 8f67d05177279c2d36ed0bd4eabed7ba5c6808ed
	if (x[ii] == 0) return 0;
	else if (y[ii] == 0) return 1;
	else if (x[ii] == w) return 2;
	else return 3;
}

<<<<<<< HEAD
inline bool isEdge (int ii) {
	if (x[ii] == x[(ii+1)%n]
int main () {

=======
int main () {
	scanf("%d%d%d",&w,&h,&n);
	for (int i=0; i<n; ++i) 
		scanf("%d%d", x+i, y+i);

	long long sum=0;
	for (int i=0; i<n; ++i) {
		int bef=(i+n-1)%n, cur=i;
		if (isEdge(bef) && !isEdge(cur)) {
			start = cur;
			p[cur] = START;
		}
		if (!isEdge(bef) && isEdge(cur)) {
			p[cur] = END;
			++num;
		}
	}


	int from, to;
	for (int i=0; i<n; ++i) {
		int bef=(start+i+n-1)%n, cur=(i+start)%n, next=(start+i+1)%n;
		if (p[cur] == START) {
			from = cur;
			sum = len(cur, next);
		}
		else if (p[cur] == END) {
			to = cur;
			if (pos(from) == pos(to)) sum += len(to, from);
			else if ((pos(from)+1)%4 == pos(to)) sum += len(to, from);
			else if ((pos(from)+3)%4 == pos(to)) sum += 2*w+2*h-len(to,from);
			else {
				if (pos(from) == 0) sum += y[from] + y[to] + w;
				else if (pos(from) == 2) sum += 2*h - y[from] - y[to] + w;
				else if (pos(from) == 1) sum += 2*w - x[from] - x[to] + h;
				else sum += x[from] + x[to] + h;
			}
			DPRINTF(("%lld\n", sum));
			best = max(best, sum);
		}
		else sum += len(cur, next);
	}

	if (num == 0) 
		return printf("1 %lld\n", sum + 2*w + 2*h), 0;
	else printf("%d %lld\n", num, best);
>>>>>>> 8f67d05177279c2d36ed0bd4eabed7ba5c6808ed
	return 0;
}


