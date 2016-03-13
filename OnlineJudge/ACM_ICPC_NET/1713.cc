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

int n, c;
struct cand {
	int vote, id, date;
	cand (int _id, int _date) {
		id = _id;
		date = _date;
	}
};

vector<cand> pic;

bool compare (const cand& a, const cand& b) {
	return a.vote != b.vote ? a.vote < b.vote : a.date < b.date;
}

int main () {
	scanf("%d%d", &n, &c);
	for (int i=0; i<c; ++i) {
		int t, found = -1;
		scanf("%d", &t);
		for (int j=0; j<pic.size(); ++j)
			if (pic[j].id == t) {
				found = j;
				break;
			}
		if (found == -1) {
			if (pic.size() == n)
				pic.erase(pic.begin());
			pic.push_back(cand(t, i));
		}
		else
			++pic[found].vote;

		sort(pic.begin(), pic.end(), compare);
	}

	vi ans;
	for (int i=0; i<pic.size(); ++i) ans.push_back(pic[i].id);
	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);

	return 0;
}


