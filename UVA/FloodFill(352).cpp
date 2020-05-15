#include<bits/stdc++.h>
using namespace std;

bool inside(int x, int y, int n)
{
    if(x>=0 && y>=0 && x<n && y<n)
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n, vector<int>(n));
    vector<pair<int, int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            char c;
            cin>>c;
            arr[i][j]=c-48;
        }
    int counter=0;
    vector<vector<bool>>vis(n, vector<bool>(n, false));
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
            if(vis[i][j] || arr[i][j]==0)
                continue;
            counter++;
            stack<pair<int, int>>st;
            st.push({i, j});
            vis[i][j]=true;
            while(st.empty()==false)
            {
                pair<int, int>a = st.top();
                st.pop();
                for(int i=0; i<dir.size(); i++)
                {
                    int new_x = a.first+dir[i].first;
                    int new_y = a.second+dir[i].second;
                    if(inside(new_x, new_y, n) && !vis[new_x][new_y] && arr[new_x][new_y]==1)
                    {
                        st.push({new_x, new_y});
                        vis[new_x][new_y]=true;
                    }
                }
            }
        }
    }
    cout<<counter;
}
