#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool inside(int x, int y, pair<int, int>dim)
{
    if(x>=0 && y>=0 && x<dim.first && y<dim.second)
        return true;
    return false
;
}
void dfs(pair<int, int>start, vector<pair<char, vector<pair<int, int>>>>&adj, vector<vector<char>>arr, pair<int, int>dim)
{
    vector<vector<bool>>vis(dim.first, vector<bool>(dim.second));
    char c = arr[start.first][start.second];
    vector<pair<int, int>>vect;
    stack<pair<int, int>>st;
    st.push(start);
    vis[start.first][start.second]==true;
    while(st.empty()==false)
    {
        pair<int, int> temp = st.top();
        st.pop();
        if(!(temp.first == dim.first - 1 || arr[temp.first+1][temp.second]==c))
            vect.push_back(temp);
        for(int i=0; i<dir.size(); i++)
        {
            int new_x = dir[i].first + temp.first;
            int new_y = dir[i].second + temp.second;
            if(inside(new_x, new_y, dim) && arr[new_x][new_y]==c && vis[new_x][new_y]==false)
            {
                st.push({new_x, new_y});
                vis[new_x][new_y]=true;
            }
        }
    }
    adj.push_back(make_pair(c, vect));
}

void change(vector<vector<char>>arr, vector<pair<char, vector<pair<int, int>>>>&adj)
{
    for(int i=0; i<adj.size(); i++)
    {
        char c = adj[i].first;
        for(int j=0; j<adj[i].second.size(); j++)
        {
            int x = adj[i].second[j].first;
            int y = adj[i].second[j].second;
            if(arr[x+1][y]=='0')
            {
                adj[i].second.erase(adj[i].second.begin()+j);
                j--;
            }
        }
    }
}

void place(char c, vector<vector<char>>&arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[0].size(); j++)
        {
            if(arr[i][j]==c)
                arr[i][j]='0';
        }
    }
}

bool mycomp(pair<char, vector<pair<int, int>>>&a, pair<char, vector<pair<int, int>>>&b)
{
    return a.second.size()<b.second.size();
}

void solve()
{
    int r, c;
    cin>>r>>c;
    vector<vector<char>>arr(r, vector<char>(c));
    map<char, pair<int, int>>mp;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>arr[i][j];
            if(mp.find(arr[i][j])==mp.end())
                mp[arr[i][j]]={i, j};
        }
    }
    vector<pair<char, vector<pair<int, int>>>>adj;
    for(auto s : mp)
        dfs(s.second, adj, arr, {r, c});
    sort(adj.begin(), adj.end(), mycomp);
    bool flag=false;
    for(int i=0; i<adj.size(); i++)
    {
        if(adj[i].second.size()==0)
            flag= flag || true;
    }
    if(!flag)
    {
        cout<<-1<<'\n';
        return;
    }
    vector<char>ans;
    while(adj[0].second.size()==0 && adj.size()>0)
    {
        place(adj[0].first, arr);
        ans.push_back(adj[0].first);
        adj.erase(adj.begin());
        reverse(adj.begin(), adj.end());
        change(arr, adj);
        sort(adj.begin(), adj.end(), mycomp);
    }
    if(adj.size()!=0)
    {
        cout<<-1<<'\n';
        return;
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i];
        if(i+1<ans.size())
            continue;
        else
            cout<<'\n';
    }
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
