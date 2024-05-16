/*In this problem we need to find a shortest path by transforming n to m .
In the process of transforming n to m we can perform any of two operation.

i.We can multiply the current number by 2. x=x*2 .
ii. We can append the digit 1 to the right of current number (that is, replace the number x by 10·x+1).

So we can perform use bfs to solve this problem.Here we can perform each operation into the queue and check
we can get the target value m or not and every time we can store the value where the current number comes
if we can reach at target value then we just need to find the path by keep track of previous number */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<string,string>par;
map<string,ll>sp;
int main()
{
    ll n,m;
    cin>>n>>m;
    string s;
    s=to_string(n);
    queue<ll>q;
    q.push(n);
    while(!q.empty())
    {
        ll f=q.front();
        q.pop();
        s=to_string(f);
        if(f>m)
            continue;
        else{
        ll x=f*2;
        ll y=f*10+1;
        if(x<=m)
        {
            string d;
            d=to_string(x);
            par[d]=s;
            q.push(x);
            sp[d]++;
        }
        if(y<=m)
        {
            string d;
            d=to_string(y);
            par[d]=s;
            q.push(y);
            sp[d]++;
        }
        if(x==m || y==m)
            break;}
    }
    s=to_string(m);
    if(sp[s]==0)
        cout<<"NO\n";
    else
    {
        vector<string>up;
        up.push_back(s);
        string x;
        x=to_string(n);
        while(s!=x)
        {
             s=par[s];
            up.push_back(s);

        }
        //up.push_back(s);
        cout<<"YES\n";
        reverse(up.begin(),up.end());
        cout<<up.size()<<endl;
        for(auto it:up)
            cout<<it<<" ";
        cout<<endl;
    }
}
