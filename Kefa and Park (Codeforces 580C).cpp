/*In this problem we need to find number of resturants situated at leaf nodes in which we face not more than k cats consecutively from root node*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> ar[200003];
ll vis[200003];
ll val[200004];
ll cons[200004];
ll c=0,k,ans=0;
ll dfs(ll node,ll st)
{

    vis[node]=1;
   cons[node]=st;

    for(auto child:ar[node])
    {
        if(vis[child]==0)
        {
            if(cons[node]==k && val[child]==1)
                continue;

             if(val[child]==1)
            dfs(child,cons[node]+1);
            else
                dfs(child,0);
            if(cons[child]<=k && ar[child].size()==1)
                 ans++;
        }
    }
    return ans;

}
int main()
{
    ll n;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

if(val[1]==1)
    c=1;
    ll f=dfs(1,c);
    cout<<f<<endl;

}
