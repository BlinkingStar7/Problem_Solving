#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <numeric>
using namespace std;


struct TrieNode {
	TrieNode *child[28], *most;
	int num;
	TrieNode () : num(0) {
		memset (child, 0, sizeof(child));
		most = NULL;
		num = 0;
	}
	~TrieNode () {
		for (int i=0; i<28; ++i)
			if (child[i])
				delete child[i];
	}

	void insert(const char* key, int n) {
		if (*key==0)
			num = n;
		else {
			int next = (*key)-'A';
			if (child[next]==0)
				child[next] = new TrieNode();
			child[next]->insert(key+1, n);
		}
	}

	TrieNode* find(const char* key) {
		if (*key==0) return this;
		int next = (*key)-'A';
		if(child[next]==NULL) return NULL;
		return child[next]->find(key+1);
	}

	TrieNode* calcMost () {
		int cand = 0;
		if (num != 0) {
			most = this;
			cand = num;
		}
		for (int i=0; i<28; ++i) {
			if (child[i] != NULL && child[i]->calcMost()->num > cand) {
				cand = child[i]->most->num;
				most = child[i]->most;
			}
		}
		return most;
	}

	int Solve(const char* key, TrieNode* toFind) {
		if (*key==0) return 0;
		if (toFind == most) return 1;
		int next = (*key)-'A';
		return 1+child[next]->Solve(key+1, toFind);
	}

};


int testNum, N, M;
char str[11];

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> M;
		TrieNode tri;
		for (int i=0; i<N; ++i) {
			int num;
			cin >> str >> num;
			tri.insert(str, num);
		}

		tri.calcMost();
		tri.most = NULL;
		int ans = M-1;

		for (int i=0; i<M; ++i) {
			cin >> str;
			TrieNode* found = tri.find(str);
			if (found == NULL) {
				cout << str << " " << strlen(str) << endl;
				ans += strlen(str);
			}
			else {
				cout << str << " " <<tri.Solve(str,found) << endl;
				ans += tri.Solve(str, found);
			}
		}

		cout << ans << endl;
	}


	return 0;
}

