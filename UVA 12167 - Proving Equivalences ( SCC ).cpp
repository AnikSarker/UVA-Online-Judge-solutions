#include<bits/stdc++.h>
using namespace std;
#define MAX 20005
#define pii pair<int,int>

vector<int>adj[MAX];
vector<int>rev[MAX];

int col[MAX];
int pre[MAX];
int s[MAX];
int f[MAX];

struct my{
    bool operator()(const pii a,const pii b)const{
        return a>b;
    }
};

set<pii,my>pq;
vector<int>scc[MAX];
int pos[MAX];

int tme=0;
void dfs(int u){
    col[u]=1;
    tme++;
    s[u]=tme;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(col[v]==0){
            pre[v]=u;
            dfs(v);
        }
    }
    tme++;
    f[u]=tme;
    col[u]=2;
}

int cnt=0;
void solve(int u){
    col[u]=1;
    for(int i=0;i<rev[u].size();i++){
        int v=rev[u][i];
        if(col[v]==0){
            solve(v);
            scc[cnt].push_back(v);
            pq.erase(make_pair(f[v],v));
            pos[v]=cnt;
        }
    }
    col[u]=2;
}

int main(){
    int t,n,m,a,b;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        tme=0;
        for(int i=1;i<=n;i++) {adj[i].clear();rev[i].clear();}
        for(int i=1;i<=n;i++) col[i]=0;
        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            rev[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            if(col[i]==0) dfs(i);
            pq.insert(make_pair(f[i],i));
        }

        for(int i=1;i<=n;i++) col[i]=0;

        for(int i=1;i<=cnt;i++) scc[i].clear();
        cnt=0;
        while(!pq.empty()){
            cnt++;
            pii temp=*pq.begin();
            pq.erase(temp);

            scc[cnt].push_back(temp.second);
            pos[temp.second]=cnt;
            solve(temp.second);
        }

        int indegree=0;
        int outdegree=0;
        if(cnt==1) {printf("0\n"); continue;}

        for(int i=1;i<=cnt;i++){
            bool flagIn=1;
            bool flagOut=1;

            for(int j=0;j<scc[i].size();j++){
                int val=scc[i][j];

                for(int k=0;k<adj[val].size();k++){
                    int x=adj[val][k];
                    if(pos[x]!=pos[val]) flagOut=0;
                }
                for(int k=0;k<rev[val].size();k++){
                    int x=rev[val][k];
                    if(pos[x]!=pos[val]) flagIn=0;
                }

            }
            indegree+=flagIn;
            outdegree+=flagOut;
        }
        printf("%d\n",max(indegree,outdegree));
    }
}
