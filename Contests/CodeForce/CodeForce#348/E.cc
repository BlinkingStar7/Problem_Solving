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

map<int, int> m;
int n;

struct ss {
	int t, m, v, ind;
}s[100001];

struct Node {
	pii key;
	int priority, size;
	Node *left, *right;

	Node(const pii& _key) : key(_key), priority(rand()),
	size(1), left(NULL), right(NULL) {
	}

	void setLeft(Node *n) { left = n; calcSize(); }
	void setRight(Node *n) { right = n; calcSize(); }
	void calcSize() {
		size = 1;
		if(left) size += left->size;
		if(right) size += right->size;
	}

};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, pii& key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splited = split(root, node->key);
		node->setLeft(splited.first);
		node->setRight(splited.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

Node* erase(Node* root, pii& key) {
	if (root == NULL) return root;
	if (root ->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key<root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

int query(Node* root, pii& key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return query(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls+1+query(root->right, key);
}

bool cmp (const struct ss& a, const struct ss& b) {
	return a.m < b.m;
}

int main () {
	scanf("%d", &n);
	Node* plus = NULL, *minus = NULL;
	memset(s, 0, sizeof(s));

	for (int i=0; i<n; ++i) {
		scanf("%d%d%d", &s[i].t, &s[i].m, &s[i].v);
		s[i].ind = i;
	}

	sort(s, s+n, cmp);

	for (int i=0; i<n; ++i) {
		int type=s[i].t, index=s[i].ind, var=s[i].v;
		pii tt = make_pair(var, index);
		if (type == 1) {
			m[var]++;
			plus = 	insert(plus, new Node(tt));
		}
		else if (type == 2) {
			m[var]--;
			minus = insert(minus,new Node(tt));
		}
		else {
			int cur = m[var];
			pii ttt = make_pair(var+1, -1);
			cur += query(plus, tt) - query(plus, ttt);
			cur -= query(minus, tt) - query(minus, ttt);
			printf("%d\n", cur);
		}
	}
	return 0;
}


