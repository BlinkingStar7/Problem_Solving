#include<cstdio>
#define isp(a,b,c,d)  (ccw(a,b,c)*ccw(a,b,d)==-1)
#define eq(a,b)     (a[0]==b[0]&&a[1]==b[1])
typedef long long ll;
 
ll c[2]={-1,1397657};
ll b[10000][2];
ll a[3][3];
 
int
ccw(ll *a, ll *b, ll *c)
{
    ll t=a[0]*b[1]+b[0]*c[1]+c[0]*a[1];
    t-=a[1]*b[0]+b[1]*c[0]+c[1]*a[0];
    if(t>0)return 1;
    else if(t==0) return 0;
    else return -1;
}
 
int
main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%lld %lld",&b[i][0],&b[i][1]);
    for(int i=0; i<3; i++)
        scanf("%lld %lld",&a[i][0],&a[i][1]);
    for(int i=0; i<3; i++){
        int cnt=0,onbound=0;
        for(int j=0; j<n; j++){
            ll *b1=b[j],*b2=b[(j+1)%n];
            if(isp(a[i],c,b1,b2) && isp(b1,b2,a[i],c)){
                cnt++;
            }
            if(ccw(b1,b2,a[i])==0
                    && (isp(a[i],c,b1,b2)||eq(a[i],b1)||eq(a[i],b2))){
                onbound=1;
                break;
            }
        }
        if((n>2&&cnt%2)||onbound)
            a[i][2]=1;
    }
    for(int i=0; i<3; i++)
        printf("%lld\n",a[i][2]);
    return 0;
}
