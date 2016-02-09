#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M, S[101];

int Find (int a) {
	return S[a] == a ? a : Find(S[a]);
}

void Union (int a, int b) {
	S[b] = Find(a);
}

int main() {
	cin >> N >> M;
	for (int i=0; i<N; ++i)
		S[i] = i;
	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	int a=0;
	for (int i=2; i<=N; ++i) 
		if (S[i] == S[1]) ++a;
	cout << a << endl;

	return 0;
}


