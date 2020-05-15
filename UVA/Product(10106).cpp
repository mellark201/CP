#include<bits/stdc++.h>
using namespace std;

string mult(string a, int x)
{
    if(x==0)
    {
        return string(a.size(), '0');
    }
    if(x==1)
        return a;
    reverse(a.begin(), a.end());
    string temp="";
    int carry=0;
    for(int i=0; i<a.size(); i++)
    {
        int z = (a[i]-48)*x + carry;
        carry = z/10;
        if(z>9)
            z%=10;
        temp+=to_string(z);
    }
    if(carry>0)
        temp+=to_string(carry);
    reverse(temp.begin(), temp.end());
    return temp;
}

string ad(string a, string b)
{
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
	if(a.size()<b.size())
	{
	    string temp=a;
	    a=b;
	    b=temp;
	}
	string ans="0";
	reverse(b.begin(), b.end());
	for(int i=0; i<b.size(); i++)
	{
	    string temp = mult(a, b[i]-48);
	    for(int j=0; j<i; j++)
	        temp+="0";
	    ans=ad(temp, ans);
	}
	cout<<ans<<'\n';
}

int main()
{
	solve();
    // cout<<ad("526", "239");
}
