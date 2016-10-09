#include <bits/stdc++.h>
using namespace std;
#define MAX 505

double prob[MAX];
double dp[MAX][MAX];
int n;
double p;

void go(){
    prob[0]=1;
    for(int i=1;i<=n;i++) prob[i]=p*prob[i-1];
}

double solve(){
    for(int j=0;j<=n;j++) dp[0][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j>=i) dp[i][j]=1;
            else if(j==i-1) dp[i][j]=1-prob[i];
            else dp[i][j]=dp[i-1][j] - dp[i-j-2][j]*(1-p)*prob[j+1];
        }
    }

    double ans=0;
    for(int j=1;j<=n;j++) ans+=j*(dp[n][j]-dp[n][j-1]);
    return ans;
}

int main(){
    while(1){
        scanf("%d %lf",&n,&p);
        if(n==0) break;

        go();
        printf("%lf\n",solve());
    }
}
