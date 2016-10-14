#include<bits/stdc++.h>
using namespace std;
#define MAX 25
double p[MAX];
double dp[MAX][MAX];
double ans[MAX];
int n,r;

void solve(int chosen){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(j) dp[i][j]+=p[i]*dp[i-1][j-1];
            if(chosen==i) continue;
            dp[i][j]+=(1-p[i])*dp[i-1][j];
        }
    }
    ans[chosen]=dp[n][r];
}

int main(){
    int cse=0;
    while(1){
        scanf("%d %d",&n,&r);
        if(n==0 & r==0) break;
        for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
        printf("Case %d:\n",++cse);

        solve(0);
        for(int chosen=1;chosen<=n;chosen++){
            solve(chosen);
            printf("%lf\n",ans[chosen]/ans[0]);
        }
    }
}
