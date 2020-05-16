#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binexp(ll a, ll b, ll c)
{
    a%=c;
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}

void solve(ll a, ll b, ll c)
{
    ll ans = binexp(a, b, c);
    cout<<ans<<'\n';
}

int main()
{
    ll a, b, c;
    while(cin>>a)
    {
        cin>>b>>c;
        solve(a, b, c);
    }
}
