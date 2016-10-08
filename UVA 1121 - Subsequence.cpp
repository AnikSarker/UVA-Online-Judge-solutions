#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int ara[MAX];
int n,s;

int solve(){
    int lo=1,hi=0;
    int sum=0;
    int ans=n+1;

    while(lo<=n){
        while(sum<s && hi<n) sum+=ara[++hi];
        if(sum>=s) ans=min(ans,hi-lo+1);
        sum-=ara[lo++];
    }
    return ans;
}

int main(){
    while(scanf("%d %d",&n,&s)==2){
        for(int i=1;i<=n;i++) scanf("%d",&ara[i]);
        int ret=solve();
        if(ret==n+1) printf("0\n");
        else printf("%d\n",ret);
    }
}
