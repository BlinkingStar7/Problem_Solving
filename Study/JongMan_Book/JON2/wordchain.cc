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

int testNum, N, G[27][27], out[27], in[27];
string Word[101];
bool Visited[101];

void buildEulerian (int here, vector<int> &eulerian) {
	for (int i=0; i<26; ++i)
		while (G[here][i] > 0) {
			--G[here][i];
			buildEulerian (i, eulerian);
		}
	eulerian.push_back(here);
}


int main () {
	cin >> testNum;

	while (testNum--) {
		memset(G, 0, sizeof(G));
		memset(out, 0, sizeof(out));
		memset(in, 0, sizeof(in));
		memset(Visited, 0, sizeof(Visited));
		cin >> N;
		for (int i=0; i<N; ++i) {
			cin >> Word[i];
			++G[Word[i][0]-'a'][Word[i].back()-'a'];
			++out[Word[i][0]-'a'];
			++in[Word[i].back()-'a'];
		}

		bool flag = true;
		int start=-1, end=-1;
		for (int i=0; i<26; ++i) {
			int cur = out[i] - in[i];
			if (cur == 0) continue;
			else if (cur == 1) {
				if (start == -1) start = i;
				else {
					flag = false;
					break;
				}
			}
			else if (cur == -1) {
				if (end == -1) end = i;
				else {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
		}

		if ((start == -1 && end != -1) || (start != -1 && end == -1))
			flag = false;

		if (flag) {
			vector<int> eulerian;
			buildEulerian (start == -1 ? Word[0][0]-'a' : start, eulerian);
			if (eulerian.size() != N+1) {
				flag = false;
			}
			else {
				reverse (eulerian.begin(), eulerian.end());
				int cur = eulerian[0];
				for (int i=1; i<eulerian.size(); ++i) {
					for (int w=0; w<N; ++w) {
						if (Word[w][0]-'a'==cur && Word[w].back()-'a'==eulerian[i] && !Visited[w]) {
							Visited[w] = true;
							cout << Word[w] << " ";
							cur = eulerian[i];
						}
					}
				}
				puts("");
			}
		}
		if (!flag)
			cout << "IMPOSSIBLE" << endl;






	}


	return 0;
}

