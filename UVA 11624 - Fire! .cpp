#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
int r,c;
string s[MAX];
queue<pii>que;
int dist[MAX][MAX];
int joe[MAX][MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int jX,jY;

bool valid (int x,int y){
    return x>=0 && y>=0 && x<=r-1 && y<=c-1 && s[x][y]!='#';
}

void process(){
    while(!que.empty()){
        pii v=que.front();
        que.pop();

        for(int i=0;i<4;i++){
            int x=v.f+dir[i][0];
            int y=v.s+dir[i][1];

            if(valid(x,y) && dist[x][y]==1e8){
                que.push(mp(x,y));
                dist[x][y]=dist[v.f][v.s]+1;
            }
        }
    }
}

int bfs(pii u){
    int ans=-1;
    que.push(u);
    joe[u.f][u.s]=0;
    while(!que.empty()){
        pii v=que.front();
        if((v.f==0 || v.s==0 || v.f==r-1 || v.s==c-1)&& ans==-1) ans=1+joe[v.f][v.s];

        que.pop();
        for(int i=0;i<4;i++){
            int x=v.f+dir[i][0];
            int y=v.s+dir[i][1];

            if(valid(x,y) && joe[x][y]==1e8){
                joe[x][y]=joe[v.f][v.s]+1;
                if(joe[x][y]<dist[x][y]){
                    que.push(mp(x,y));
                }
            }
        }
    }
    return ans;
}


int main(){
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d %d",&r,&c);
        for(int j=0;j<r;j++) cin>>s[j];

        for(int p=0;p<r;p++){
            for(int q=0;q<c;q++){
                dist[p][q]=1e8;
                joe[p][q]=1e8;
                if(s[p][q]=='F'){
                    que.push(mp(p,q));
                    dist[p][q]=0;
                }
                else if(s[p][q]=='J') {jX=p;jY=q;}
            }
        }

        process();

        int ret=bfs(mp(jX,jY));
        if(ret==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",ret);
    }

}
