#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int a[105][105], p[105];
 
int Find(int x){
    return (p[x]!=x) ? p[x] = Find(p[x]) : x;
}
 
void Union(int u, int v){
    if( Find(v) < Find(u) ) swap( u, v );
    p[Find(v)] = Find(u);
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        p[i] = i;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            if( i!=j && !a[i][j] ) Union( i, j );
        }
    }
 
    bool ok = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if( i!=j && a[i][j] && Find(i) == Find(j) )
                ok = 0;
 
    if( ok ){
        int s = 0;
        for(int i=1; i<=n; i++)
            if( p[i] == i )
                ++s;
 
        printf("%d\n", s);
        for(int i=1; i<=n; i++){
            if( p[i] == i ){
                for(int j=1; j<=n; j++)
                    if( Find(j) == i )
                        printf("%d ", j);
                puts("");
            }
        }
    }
    else
        puts("0");
}
