#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int ar[] = {1, -1, 1, -1, 2, 2, -2, -2};
int br[] = {2, 2, -2, -2, 1, -1, 1, -1};
int vis[20][20];
int cost[20][20];
char c1[10], c2[10];

int bsf(int a1, int b1, int a2, int b2)
{
    queue<pii>q;
    memset(vis, 0, sizeof(vis));
    q.push(pii(a1, b1));
    vis[a1][b1]=1;
    cost[a1][b1]=0;
    while(!q.empty())
    {
        pii top = q.front();
        q.pop();
        if(top.first==a2 && top.second==b2)
        {
            cout<<"To get from "<<c1<<" to "<<c2<<" takes "<<cost[a2][b2]<<" knight moves."<<endl;
            return 0;
        }
        for(int i=0; i<8; i++)
        {
            int x = top.first + ar[i];
            int y = top.second + br[i];
            if(x>0 && x<=8 && y>0 && y<=8 && vis[x][y]==0)
            {
                q.push(pii(x, y));
                vis[x][y]=1;
                cost[x][y]=cost[top.first][top.second]+1;
            }
        }
    }
    return 0;
}

int main()
{
    int i, j, a1, a2, b1, b2;
    while(cin>>c1>>c2)
    {
        a1 = c1[0]-96;
        b1 = c1[1]-'0';
        a2 = c2[0]-96;
        b2 = c2[1]-'0';
        bsf(a1, b1, a2, b2);
    }
    return 0;
}
