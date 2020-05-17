#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int counter=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==k)
        {
            int j=1;
            bool flag=true;
            for(j; j<k; j++)
            {
                if(arr[i+j]!=k-j)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                counter++;
            j--;
            i+=j;
        }
    }
    cout<<counter<<'\n';
}

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
}
