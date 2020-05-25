#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime[10000010];

map<ll, bool>mp;

void sieve()
{
    for(int i=4; i<=10000000; i+=2)
        prime[i]=false;
    for(int i=3; i*i<=10000000; i+=2)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=10000000; j+=i+i)
                prime[j]=false;
        }
    }
    mp[2]=true;
    for(ll i=3; i<=10000000; i++)
    {
        if(prime[i])
        {
            // if(i<100)
                // cout<<i<<'\n';
            mp[i]=true;
        }
    }
}

void solve(ll n)
{
    for(auto s : mp)
    {
        if(mp.find(n-s.first)!=mp.end())
        {
            cout<<s.first<<' '<<n-s.first<<'\n';
            return;
        }
    }
}

int main()
{
    memset(prime, true, sizeof(prime));
    sieve();
    ll n;
    while(cin>>n)
    {
        if(n<8)
            cout<<"Impossible.";
        else
        {
            if(n%2==0)
            {
                cout<<2<<' '<<2<<' ';
                n-=4;
            }
            else
            {
                cout<<2<<' '<<3<<' ';
                n-=5;
            }
            solve(n);
        }
    }
}
