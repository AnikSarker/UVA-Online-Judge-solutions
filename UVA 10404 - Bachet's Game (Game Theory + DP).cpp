#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
bool dp[MAX];
int moves[15];
int n,m;

bool solve(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        if(dp[i]==0){
            for(int j=1;j<=m;j++)
                if(moves[j]+i<=n) dp[moves[j]+i]=true;
        }
    }
    return dp[n];
}

int main(){
    while(scanf("%d %d",&n,&m)==2){
        for(int i=1;i<=m;i++) scanf("%d",&moves[i]);
        if(solve()) printf("Stan wins");
        else printf("Ollie wins");
        printf("\n");
    }
}
