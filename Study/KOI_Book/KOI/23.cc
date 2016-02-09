#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Position {int y, x;} P;
vector<P> L;
int N, W;

int Dis (P p1, P p2) { return abs (p1.x - p2.x) + abs (p1.y - p2.y); }
int Solve (P p1, P p2, int n) {
	if (n == W) return 0;
	return min (Dis (p1, L[n]) + Solve (L[n], p2, n+1),
				Dis (p2, L[n]) + Solve (p1, L[n], n+1));
}

int main() {
	cin >> N >> W;
	for (int i=0; i<W; ++i) {
		int y, x;
		cin >> y >> x;
		L.push_back((P) {y, x});
	}

	cout << Solve ((P) {1, 1}, (P) {N, N}, 0) << endl;
	return 0;
}

