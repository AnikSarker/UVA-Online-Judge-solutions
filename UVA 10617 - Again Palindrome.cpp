#include<bits/stdc++.h>
using namespace std;
#define MAX 65
#define LL long long int
string s;
int Size;
LL dp[MAX][MAX];

void solve(){
    memset(dp,0,sizeof(dp));
    for(int i=0;s[i];i++) dp[i][i]=1;
    Size=s.size();

    for(int len=1;len<Size;len++){
        for(int i=0;s[i+len];i++){
            dp[i][i+len]=dp[i][i+len-1]+dp[i+1][i+len];
            if(s[i]==s[i+len]) dp[i][i+len]+=1;
            else dp[i][i+len]-=dp[i+1][i+len-1];
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        cin>>s;
        solve();
        printf("%lld\n",dp[0][s.size()-1]);
    }
}
