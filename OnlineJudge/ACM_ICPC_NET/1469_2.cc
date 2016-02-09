#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define NM 1005
#define INF 0x7fffffff
#define MIN(x,y) ((x)<(y)?(x):(y))
FILE *in = stdin, *out = stdout;
//FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
int n,a[105];
int visit[105];
int b[105];
int flag;
void pro(int x){ 
	if (flag==1) return;
	if (x==n*2+1){
		FOR (i,1,n*2) fprintf(out,"%d ",b[i]);
		flag=1;         
		return;
	}
	if (b[x]!=-1) pro(x+1);
	/*FOR (i,1,n){
	  if (visit[i]) continue;
	  if (x+a[i]+1 > n*2) return;
	  }*/
	FOR (i,1,n){
		if (visit[i]) continue;
		if (b[x+a[i]+1]!=-1) continue;
		visit[i]=1;
		b[x+a[i]+1]=a[i];
		b[x]=a[i];
		if (b[4] == 3)
			printf("a");
		pro(x+1);
		if (flag==1) return;
		visit[i]=0;
		b[x+a[i]+1]=b[x]=-1;
	}
}
int main(){
	si(n);
	FOR (i,1,n) si(a[i]);
	std::sort(a+1,a+1+n);
	FOR (i,1,n*2) b[i]=-1;
	flag=0;
	pro(1);
	if (flag==0) fprintf(out,"-1");
	puts("");
	return 0;
}
