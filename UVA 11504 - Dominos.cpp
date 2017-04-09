#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
bool vis[100005];
stack<int>STK;

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==0) dfs(v);
    }
    STK.push(u);
}

int main(){
    int t,n,m;

    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) adj[i].clear();

        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
        }

        for(int i=1;i<=n;i++){
            if(vis[i]==0) dfs(i);
        }

        int ans=0;
        for(int i=1;i<=n;i++) vis[i]=0;
        while(!STK.empty()){
            int v=STK.top();
            STK.pop();
            if(vis[v]==0){
                ans++;
                dfs(v);
            }
        }
        printf("%d\n",ans);
    }
}
