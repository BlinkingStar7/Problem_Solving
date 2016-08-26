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
typedef long long ll;
typedef unsigned long long ull;


struct Node {
	int val, pos;
	Node *left, *right;
	
	Node (int v, int p, Node *l, Node *r) : val(v), pos(p), left(l), right(r) {}
};

int N, Q;
queue<Node*> A[300005];
bool V[300005];

int main () {
	scanf("%d%d", &N, &Q);
	
	Node *head = new Node(INF, 0, NULL, NULL);
	Node *tail = new Node(INF, INF, head, NULL);
	head->right = tail;

	int cnt = 1, num = 0;
	for (int i=0; i<Q; ++i) {
		int cmd, x;
		scanf("%d%d", &cmd, &x);
		
		if (cmd == 1) {
			Node *temp = new Node(x, cnt, tail->left, tail);
			tail->left->right = temp;
			tail->left = temp;

			A[x].push(temp);
			V[cnt] = true;

			++num;
			++cnt;
		}
		else if (cmd == 2) {
			while (!A[x].empty()) {
				Node *cur = A[x].front(); A[x].pop();
				if (!V[cur->pos]) continue;

				cur->left->right = cur->right;
				cur->right->left = cur->left;

				V[cur->pos] = false;
				--num;
			}
		}
		else {
			for (Node *cur = head->right; cur->pos <= x; cur = cur->right) {
				if (!V[cur->pos]) continue;

				cur->left->right = cur->right;
				cur->right->left = cur->left;

				V[cur->pos] = false;
				--num;
			}
		}
		printf("%d\n", num);
	}

	return 0;
}


