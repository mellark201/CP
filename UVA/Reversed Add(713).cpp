#include<bits/stdc++.h>
using namespace std;

string ad(string a, string b)
{
    if(a.size()<b.size())
    {
        string temp=a;
        a=b;
        b=a;
    }
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string temp="";
	int carry=0;
	for(int i=0; i<b.size(); i++)
	{
		int x = a[i]-48 + b[i]-48 + carry;
		carry=x/10;
		if(x>9)
			x=x%10;
		temp+=to_string(x);
	}
	if(b.size()!=a.size())
	{
	    for(int i=b.size(); i<a.size(); i++)
	    {
	        int x = a[i]-48 + carry;
	        if(x>9)
	            x=x%10;
	        temp+=to_string(x);
	        carry=x/10;
	    }
	}
	if(carry>0)
	    temp+=to_string(carry);
	reverse(temp.begin(), temp.end());
	return temp;
}

void solve()
{
    string a, b;
    cin>>a>>b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string temp = ad(a, b);
    reverse(temp.begin(), temp.end());
    while(temp[0]=='0')
        temp.erase(temp.begin());
    cout<<temp<<'\n';
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
