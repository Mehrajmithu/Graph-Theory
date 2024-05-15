/*In this problem we need to find the minimum number of roads required to built so that there is a route between any two cities*/

 /*If there are multiple connected cities then we need to store at least one city from each connected cities.
 After checking or visiting all city we just construct a road between a connected city to other connected cities.*/

 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>ar[200000];
ll  vis[200000];
void dfs(ll node){
    vis[node]=1;
    for(auto child:ar[node]){
        if(vis[child]==0)
        dfs(child);
    }
}
int main(){

   vector<ll>p;
   ll n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
       ll x,y;
        cin>>x>>y;
        ar[x].push_back(y);
        ar[y].push_back(x);
   }
   for(int i=1;i<=n;i++){
       if(vis[i]==0){
           p.push_back(i);
           dfs(i);
       }
   }
   cout<<p.size()-1<<endl;
   for(int i=1;i<p.size();i++)
   cout<<p[0]<<" "<<p[i]<<endl;
   cout<<endl;

}
