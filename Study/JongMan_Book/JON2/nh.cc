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
#include <map>
#include <numeric>
using namespace std;

const int MOD = 10007;
int testNum, N, M, whole[101], Memo[1001][101];

struct TrieNode {
	TrieNode *child[26], *fail;
	bool terminal;
	TrieNode () : terminal(false) {
		memset(child, 0, sizeof(child));
		fail = NULL;
	}

	void insert (const char* key) {
		if (*key == 0) {
			terminal = true;
			return;
		}
		int next = (*key) - 'a';
		if (child[next] == NULL)
			child[next] = new TrieNode();
		child[next]->insert(key+1);
	}
};

map<TrieNode*, int> toNum;

void computreFailFunc (TrieNode* root) {
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);
	int num = 0;
	
	while (!q.empty()) {
		TrieNode* here = q.front();
		q.pop();

		if (toNum.find(here) == toNum.end())
			toNum[here] = num++;

		for (int i=0; i<26; ++i) {
			TrieNode* ch = here->child[i];
			if (!ch) continue;
			if (here == root)
				ch->fail = root;
			else {
				TrieNode* t = here->fail;
				while (t->child[i] == NULL && t != root)
					t = t->fail;
				if (t->child[i]) t = t->child[i];
				ch->fail = t;
			}
			q.push(ch);
		}
	}
}

int Solve (TrieNode* t, int n) {
	int &ret = Memo[toNum[t]][n];
	if (ret != -1) return ret;

	if (t->terminal) return ret = whole[n];
	if (n == 0) return ret = 0;

	ret = 0;
	for (int i=0; i<26; ++i)
		if (t->child[i]) ret = (ret + Solve (t->child[i], n-1))%MOD;
		else {
			TrieNode* next = t;
			while (next != next->fail && next->child[i] == NULL)
				next = next->fail;
			if (next->child[i]) next = next->child[i];
			ret += Solve (next, n-1);
			ret %= MOD;
		}


	return ret;
}

int main () {
	cin >> testNum;

	whole[0] = 1;
	for (int i=1; i<=100; ++i)
		whole[i] = (whole[i-1]*26)%MOD;
		
	while (testNum--) {
		memset(Memo, -1, sizeof(Memo));
		toNum.clear();
		TrieNode Tri;
		cin >> N >> M;
		for (int i=0; i<M; ++i) {
			char S[11];
			cin >> S;
			Tri.insert(S);
		}

		computreFailFunc(&Tri);

		cout << (whole[N] - Solve(&Tri, N) + MOD)%MOD << endl;

	}


	return 0;
}

