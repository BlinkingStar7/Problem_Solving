#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Prime;
typedef struct Node {int num, height; vector<Node> child;} Node;
queue <Node*> Q;
int C[4] = {1, 3, 7, 9};

void findPrime(int num) {
	for (int i=3; i<num; i+=2) {
		bool flag = true;
		for (int k=0; k<Prime.size(); ++k)
			if (i % Prime[k] == 0) {
				flag = false;
				break;
			}
		if (flag) Prime.push_back(i);
	}
}

bool isPrime(int num) {
	if (num == 1) return false;
	for (int i=0; i<Prime.size() && Prime[i]*Prime[i] <= num; ++i) {
		if (num % Prime[i] == 0)
			return false;
	}
	return true;
}

int main() {
	findPrime (100000);
	Node* root = new Node();
	root->child.push_back((Node) {2, 1});
	Q.push(root); Q.push(&root->child[0]);
	
	while (1) {
		Node* cur = Q.front(); Q.pop();
		cout << cur->num << endl;

		if (cur->height > 10) break;

		for (int c=0; c<4; ++c) {
			int cand = cur->num * 10 + C[c];
			
			if (isPrime(cand)) {
				Node* newNode = &(Node) {cand, cur->height};
				cur->child.push_back(*newNode);
				Q.push(newNode);
			}
		}
	}

	
	return 0;
}


