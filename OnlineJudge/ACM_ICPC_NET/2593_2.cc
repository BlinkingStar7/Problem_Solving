#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
 
using namespace std;
 
int n,m;
bool f_visited[100001];
pair<int,int> parent[100001]; // 목적지, 쓰는 엘리베이터
vector<pair<int,int> > ele;
int start,end;
const int INF=987654321;
 
int bfs(int floor)
{
    if(floor == end)    return 0;
    queue<pair<int,int> > q;    //목적지,횟수
 
    q.push(make_pair(floor,0));
    while(!q.empty())
    {
        int cur_floor=q.front().first , dis=q.front().second;
        q.pop();
        if(cur_floor == end)    return dis;
        dis++;
 
        for(int i=0;i<m;i++)
        {
            if(ele[i].first <= cur_floor && (cur_floor-ele[i].first)%ele[i].second == 0)
            {
                for(int j=ele[i].first;j<=n;j+=ele[i].second)
                {
                    if(f_visited[j])    continue;
                    q.push(make_pair(j,dis));
                    parent[j]=make_pair(cur_floor,i);
                    f_visited[j]=true;
                }
            }
        }
    }
     
    return INF;
}
 
int main()
{
    scanf("%d %d",&n,&m);
    int a,b;    
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        ele.push_back(make_pair(a,b));
    }
    scanf("%d %d",&start,&end);
 
    int num=bfs(start);
    if(num == INF)
    {
        printf("-1");
        return 0;
    }
     
    printf("%d\n",num);
    vector<int> result;
    int temp=end;
    while(temp!=start)
    {
        result.push_back(parent[temp].second+1);
        temp=parent[temp].first;
    }
 
    for(int i=result.size()-1;i>=0;i--)
        printf("%d\n",result[i]);
}
