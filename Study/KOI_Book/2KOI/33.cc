#include <cstdio>
#include <cstring>
int N, M[511][511], chk[511][511];
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, lb, ub, m;
int max(int a, int b) { return a>b ? a:b;}
int abs(int a) { return a>0 ? a:-a;}
bool can(int a, int b) { return (0<=a&&a<N)&&(0<=b&&b<N);}
int dfs(int a, int b, int h)
{
 int area=1;
 chk[a][b]=true;
 for(int i=0; i<4; i++)
 if(can(a+dx[i],b+dy[i]) && !chk[a+dx[i]][b+dy[i]] &&
 abs(M[a][b]-M[a+dx[i]][b+dy[i]])<=h)
 area+=dfs(a+dx[i],b+dy[i],h);
 return area;
}
bool f(int h)
{
 int mcnt=0, cnt;
 for(int i=0; i<N; i++)
 for(int j=0; j<N; j++)
 if(!chk[i][j])
 {
 cnt=dfs(i,j,h);
 mcnt=max(cnt, mcnt);
}
 return (mcnt>=(int)(N*N*0.75));
}
int main()
{
 scanf("%d",&N);
 for(int i=0; i<N; i++)
 for(int j=0; j<N; j++)
 {
 scanf("%d", &M[i][j]);
 ub=max(ub, M[i][j]);
 }
 while(lb<ub)
 {
 memset(chk, false, sizeof(chk));
 m=(lb+ub-1)/2;
 if(f(m)) ub=m;
 else lb=m+1;
 }
 printf("%d\n", ub);
 return 0;
}
