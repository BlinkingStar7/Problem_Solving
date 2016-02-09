#include <cstdio>
int dx[4] = {1,0,-1,0}, dy[4]={0,1,0,-1}, h, w, S[110][110], res;
bool inside(int a, int b) {
	return ((0<=a && a<h) && (0<=b && b<w));
}

bool done() {
	int cnt =0;
	for (int i=0; i<h; ++i) for (int j=0; j<w; ++j)
		if (S[i][j] == -1 || S[i][j] >2) S[i][j]=0;
		else if (S[i][j] == 2 || S[i][j] == 1)
			S[i][j]=1, cnt ++;
	return cnt == 0;
}

int solve(int a, int b)
{
	S[a][b]=-1;
	for (int i=0; i<4; ++i) {
		if (inside(a+dx[i], b+dy[i]))
		{
			if(S[a+dx[i]][b+dy[i]] == 0)
				solve(a+dx[i],b+dy[i]);
			else if(S[a+dx[i]][b+dy[i]]>0)
				S[a+dx[i]][b+dy[i]]++;
		}
	}


