#include<bits/stdc++.h>
using namespace std;
struct cube{
    int x;
    int y;
    int z;
    cube(int a,int b,int c) {x=a;y=b;z=c;}
};

vector<cube>ara;
int graph[105][105];
int dist[105][105];

bool buildable(int i,int j){
    cube p=ara[i];
    cube q=ara[j];
    return (p.x<q.x && p.y<q.y) || (p.x<q.y && p.y<q.x);
}

void calc(){
    for(int i=0;i<ara.size();i++){
        for(int j=0;j<ara.size();j++){
            if(buildable(i,j)) graph[i][j]=ara[i].z;
            else graph[i][j]=-1e9;
            dist[i][j]=graph[i][j];
        }
    }
}

void floyd_warshall(){
    for (int k=0;k<ara.size();k++){
        for (int i=0;i<ara.size();i++){
            for (int j=0;j<ara.size();j++){
                dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int solve(){
    int mx=-1e9;
    for(int i=0;i<ara.size();i++){
        for(int j=0;j<ara.size();j++){
            mx=max(mx,dist[i][j]+ara[j].z);
        }
    }
    return mx;
}

int main(){
    int n,a,b,c;
    int cse=0;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        ara.clear();
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a,&b,&c);
            ara.push_back(cube(a,b,c));
            ara.push_back(cube(b,c,a));
            ara.push_back(cube(c,a,b));
        }
        calc();
        floyd_warshall();
        printf("Case %d: maximum height = %d\n",++cse,solve());
    }
}
