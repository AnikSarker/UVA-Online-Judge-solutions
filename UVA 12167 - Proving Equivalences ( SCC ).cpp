#include<bits/stdc++.h>
using namespace std;
#define MAX 20005
#define pii pair<int,int>
#define pb push_back

int n,m;
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

//Transpose DFS
int cnt;
int comp[MAX];
int sizeOfComp[MAX];

int dfs2(int u){
	vis[u]=true;
    comp[u]=cnt;
    sizeOfComp[cnt]++;

	for(int i=0;i<rev[u].size();i++){
		int v=rev[u][i];
		if(vis[v]==false) dfs2(v);
	}
}

int indegree[MAX];
int outdegree[MAX];
int findMinEdges(){
        if(cnt==1) return 0;

        for(int i=1;i<=n;i++) indegree[i]=0;
        for(int i=1;i<=n;i++) outdegree[i]=0;

        for(int u=1;u<=n;u++){
            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];
                if(comp[u]!=comp[v]){
                    outdegree[comp[u]]++;
                    indegree[comp[v]]++;
                }
            }
        }

        //find the number of SCCs with 0 indegree or 0 outdegree
        int IN=0;
        int OUT=0;
        for(int i=1;i<=cnt;i++){
            if(indegree[i]==0) IN++;
            if(outdegree[i]==0) OUT++;
        }
        return max(IN,OUT);
}

int main(){
    int t,a,b;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n;i++) rev[i].clear();
        for(int i=1;i<=n;i++) vis[i]=false;

        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
            rev[b].push_back(a);
        }

        for(int i=1;i<=n;i++){
            if(vis[i]==false) dfs1(i);
        }

        for(int i=1;i<=n;i++) vis[i]=false;

        cnt=0;
        while(!stk.empty()){
            int u=stk.top();
			stk.pop();
			if(vis[u]==false){
                cnt++;
                dfs2(u);
            }
        }

        printf("%d\n",findMinEdges());
    }
}
