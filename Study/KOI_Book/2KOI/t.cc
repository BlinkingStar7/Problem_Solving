#include <cstdio>
int n, W, G[21], A, B, C, ans=987654321;
bool DT[21][2001][2001];
int main()
{
 scanf("%d", &n);
 for(int i=1; i<=n; i++)
 scanf("%d", G+i), W+=G[i];

 DT[0][0][0]=true;
 for(int i=1; i<=n; i++)
 for(int a=0; a<=2000; a++)
 for(int b=0; b<=2000; b++)
 DT[i][a][b]=(DT[i-1][a][b] ||
 (a-G[i]<0?false:DT[i-1][a-G[i]][b]) ||
 (b-G[i]<0?false:DT[i-1][a][b-G[i]]));
 for(int a=0; a<=2000; a++)
 for(int b=0; b<=2000; b++)
 if(DT[n][a][b])
 {
 if(W-(a+b)>=a && a>=b && W-(a+b)-b<=ans)
 ans=W-(a+b)-b, A=W-(a+b), B=a, C=b;
 }
 printf("%d %d %d\n", A, B, C);
 return 0;
}
