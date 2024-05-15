/* This is a simple DFS (Depth First Search) Algorithm */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>ar[200003];
ll vis[200003];
void dfs(ll node)
{
    vis[node]=1;
    cout<<node<<" ";
    for(auto child:ar[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);

        }
        cout<<endl;
    }
}
