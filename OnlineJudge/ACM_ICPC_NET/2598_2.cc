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

const int face[6][5] = {
	{1, 5, 3, 4, 2},
	{0, 4, 2, 5, 3},
	{4, 1, 5, 3, 0},
	{4, 0, 5, 2, 1},
	{0, 3, 2, 1, 5},
	{0, 1, 2, 3, 4}};
char cube[4][6], code[17], record[10000][17];
int ans;

void rotate() {
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			swap(code[4*i+j], code[4*i+(j+1)%4]);
}

void checkDup() {
	bool flag = false;
	int num = 0;
	for (int i=0; i<ans; ++i) {
		for (int j=0; j<4; ++j, rotate()) {
			int ii;
			for (ii=0; ii<17; ++ii) 
				if (code[ii] != record[i][ii]) break;
			if (ii == 17) ++num;
		}
	}
	if (!flag) {
		for (int ii=0; ii<17; ++ii)
			record[ans][ii] = code[ii];
		++ans;
	}
}

void solve(int cubeNum) {
	for (int i=0; i<cubeNum; ++i)
		for (int j=i+1; j<cubeNum; ++j)
			for (int s=0; s<4; ++s)
				if (code[i*4+s] == code[j*4+s]) break;
	
	if (cubeNum == 4) checkDup();
	else {
		for (int bot=0; bot<6; ++bot) {
			for (int dir=0; dir<4; ++dir) {
				for (int side=0; side<4; ++side) {
					code[cubeNum*4+side] = cube[cubeNum][face[cubeNum][(side+dir)%4]];
				}
				if (cubeNum == 3) code[16] = cube[cubeNum][face[cubeNum][5]];
				solve(cubeNum+1);
				/*
				   if (cube[cubeNum][0] == cube[cubeNum][1] && cube[cubeNum][1] == cube[cubeNum][2] &&
					cube[cubeNum][2] == cube[cubeNum][3]) break;
				if (cube[cubeNum][0] == cube[cubeNum][2] && cube[cubeNum][1] == cube[cubeNum][3] &&
					dir == 1) break;
					*/
			}
		}
	}
}

int main () {
	char input[7];
	for (int i=0; i<4; ++i) {
		gets(input);
		for (int j=0; j<6; ++j)
			cube[i][j] = input[j];
	}

	solve(0);
	printf("%d\n", ans);
	return 0;
}


