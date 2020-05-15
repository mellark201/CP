#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n, ll m, ll c)
{
    if(n==8 && m==8)
    {
        if(c==1)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
        return;
    }
    long long ans=0;
    for(int i=8; i<=m; i++)
    {
        bool flag=c;
        if((m-i)%2==0)
        {
            int curr = flag ? 8 : 9;
            ans+=(n-curr)/2 + 1;
        }
        else
        {
            flag=!flag;
            int curr = flag ? 8 : 9;
            ans+=(n-curr)/2 + 1;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ll n, m, c;
    cin>>n>>m>>c;
    while(!(n==0 && m==0 && c==0))
    {
        solve(n, m, c);
        cin>>n>>m>>c;
    }
}
