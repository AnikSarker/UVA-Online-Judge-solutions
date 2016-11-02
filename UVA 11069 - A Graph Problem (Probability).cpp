#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int dp[MAX];

int main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=2;
    for(int i=4;i<=76;i++) dp[i]=dp[i-2]+dp[i-3];

    int n;
    while(scanf("%d",&n)==1){
        printf("%d\n",dp[n]);
    }
}
