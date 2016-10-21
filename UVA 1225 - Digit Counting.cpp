#include<bits/stdc++.h>
using namespace std;
int cnt[10];

void go(int n){
    while(n){
        cnt[n%10]++;
        n=n/10;
    }
}

void solve(int n){
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        go(i);
    }
    printf("%d",cnt[0]);
    for(int i=1;i<10;i++) printf(" %d",cnt[i]);
    printf("\n");
}

int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        solve(n);
    }
}


