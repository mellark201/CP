#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(pair<int, int>start, vector<vector<bool>>&visit, vector<vector<int>>arr, vector<int>&count)
{
    stack<pair<int, int>>st;
    st.push(start);
    visit[start.first][start.second]=true;
    count[0]++;
    while(st.size()>0)
    {
        pair<int, int>temp = st.top();
        st.pop();
        for(int i=0; i<dir.size(); i++)
        {
            int new_x = temp.first + dir[i].first;
            int new_y = temp.second + dir[i].second;
            // cout<<new_x<<' '<<new_y<<'\t';
            if(new_y==arr[0].size())
                new_y = 0;
            else if(new_y == -1)
                new_y = arr[0].size()-1;
            // cout<<new_x<<' '<<new_y<<'\n';
            if(new_x>=0 && new_y>=0 && new_x<arr.size() && new_y<arr[0].size())
            {
                if(visit[new_x][new_y]==false && arr[new_x][new_y]==1)
                {
                    count[0]++;
                    visit[new_x][new_y]=true;
                    st.push({new_x, new_y});
                }
            }
        }
    }
    // cout<<'\n';
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>arr(n, vector<int>(m));
    vector<vector<bool>>visit(n, vector<bool>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char c;
            cin>>c;
            if(c=='l')
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    int x, y;
    cin>>x>>y;
    pair<int, int>start = {x, y};
    vector<int>count={0};
    dfs(start, visit, arr, count);
    // cout<<count[0]<<'\n';
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]==1 && visit[i][j]==false)
            {
                // cout<<i<<' '<<j<<'\n';
                count[0]=0;
                pair<int, int>temp = {i, j};
                dfs(temp, visit, arr, count);
                ans = max(ans, count[0]);
            }
        }
    }
    cout<<ans<<'\n';
}
