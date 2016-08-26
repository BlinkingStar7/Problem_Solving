#include <bits/stdc++.h>
using namespace std;

int Q;
multiset<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin >> Q;
	
	S.insert(0);
	for (int i=0; i<Q; ++i) {
		char c; int x;
		cin >> c >> x;

		if (c == '+') S.insert(x);
		else if (c == '-') S.erase(S.find(x));
		else {
			int cur = 0;
			for (int p=30; p>=0; --p) {
				multiset<int>::iterator it;

				if (x & (1<<p)) {
					it = S.lower_bound(cur);
					if (it == S.end() || *it>>p != cur>>p) cur |= (1<<p);
				}
				else {
					cur |= (1<<p);
					it = S.lower_bound(cur);
					if (it == S.end() || *it>>p != cur>>p) cur ^= (1<<p);
				}
			}

			printf("%d\n", cur^x);
		}
	}
	return 0;
}

