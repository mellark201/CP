#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool chk(ll step, ll mod)
{
    map<ll, bool>mp;
    ll start=5;
    for(int i=0; i<mod; i++)
    {
        start = (start + step)%mod;
        if(mp.find(start)!=mp.end())
            return false;
        else mp[start]=true;
    }
    return true;
}

int main()
{
    ll step, mod;
    while(cin>>step)
    {
        cin>>mod;
        int x = 10-to_string(step).size();
        for(int i=0; i<x; i++)
            cout<<" ";
        cout<<step<<' ';
        x = 10-to_string(mod).size();
        for(int i=0; i<x; i++)
            cout<<" ";
        cout<<mod<<' ';
        if(chk(step, mod))
            cout<<"Good Choice\n";
        else
            cout<<"Bad Choice\n";
    }
}
