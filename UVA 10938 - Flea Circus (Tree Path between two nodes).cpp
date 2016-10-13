#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define pb push_back

vector<int>adj[MAX];
int first,second;
vector<int>path;
bool vis[MAX];
bool PathStore(int u){
    vis[u]=true;
    if(u==second) {path.pb(u); return true;}

    bool ret=false;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==false) ret=PathStore(v);
        if(ret==true) {path.pb(u);return true;}
    }
    return false;
}

int main()
{
    int n,a,b;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n-1;i++){
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            path.clear();
            for(int i=1;i<=n;i++) vis[i]=false;

            scanf("%d %d",&first,&second);
            PathStore(first);

            int Size=path.size();
            if(Size%2==1) printf("The fleas meet at %d.\n",path[Size/2]);
            else printf("The fleas jump forever between %d and %d.\n",min(path[Size/2],path[Size/2-1]),max(path[Size/2],path[Size/2-1]));
        }
    }
}
