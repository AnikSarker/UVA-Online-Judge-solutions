#include<bits/stdc++.h>
using namespace std;
#define MAX 50005
#define pb push_back

bool vis[MAX];
vector<int>adj[MAX];
vector<int>rev[MAX];
stack<int>stk;

//Normal DFS
int dfs1(int u){
	vis[u]=true;
	for (int i=0;i<adj[u].size();i++) {
		int v=adj[u][i];
		if(vis[v]==false) dfs1(v);
	}
	stk.push(u);
}

int cnt;
int comp[MAX];
int minOfComp[MAX];
int sizeOfComp[MAX];

//Transpose DFS
int dfs2(int u){
	vis[u]=true;
    comp[u]=cnt;
	sizeOfComp[cnt]++;
	minOfComp[cnt]=min(u,minOfComp[cnt]);

	for(int i=0;i<rev[u].size();i++){
		int v=rev[u][i];
		if(vis[v]==false) dfs2(v);
	}
}

//DFS in SCC DAG
vector<int>scc[MAX];
int totalSize;
int dfs3(int u){
    //No visited mark, as it is a DAG
    //to find all possible paths from each node
	totalSize+=sizeOfComp[u];

	for (int i=0;i<scc[u].size();i++) {
		int v=scc[u][i];
        dfs3(v);
	}
}


int main(){
	int t;
	scanf("%d", &t);

	for (int p=1;p<=t;p++){
        int n;
		scanf("%d", &n);

		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<=n;i++) rev[i].clear();
		for(int i=1;i<=n;i++) scc[i].clear();
		for(int i=1;i<=n;i++) vis[i]=false;

		for(int i=1;i<=n;i++){
            int a,b;
			scanf("%d %d", &a,&b);
			adj[a].pb(b);
			rev[b].pb(a);
		}

		for (int i=1;i<=n;i++){
			if(vis[i]==false) dfs1(i);
        }

		for(int i=1;i<=n;i++) vis[i]=false;

        cnt=0;
		while(!stk.empty()){
			int u=stk.top();
			stk.pop();
			if(vis[u]==false){
                cnt++;
                minOfComp[cnt]=u;
                sizeOfComp[cnt]=0;
                dfs2(u);
            }
		}

        //to form SCC DAG
        for(int u=1;u<=n;u++){
            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];
                if(comp[u]!=comp[v]){
                    scc[comp[u]].pb(comp[v]);
                }
            }
        }

        int mx=-1;
        int idx=100000;
        for(int i=1;i<=cnt;i++){
            totalSize=0;
            dfs3(i);

            if(totalSize>mx) {mx=totalSize;  idx=minOfComp[i];}
            else if(totalSize==mx) idx=min(minOfComp[i],idx);
        }

        printf("Case %d: %d\n",p,idx);
	}
}
