#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100005
int ara[1000],adj[1000];

int h[MAX],w[MAX];
int small[MAX];
int big[MAX];
int ans1,ans2;

int main(){
    int t,n;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        scanf("%d",&n);
        ans1=0,ans2=0;
        for(int i=0;i<n;i++) scanf("%d",&h[i]);
        for(int i=0;i<n;i++) scanf("%d",&w[i]);

        for(int i=0;i<n;i++){
            int mx1=0,mx2=0;
            for(int j=0;j<i;j++){
                if(h[i]>h[j])   mx1=max(mx1,small[j]);
                if(h[i]<h[j])   mx2=max(mx2,big[j]);
            }
            small[i]=w[i]+mx1;
            big[i]=w[i]+mx2;

            ans1=max(ans1,small[i]);
            ans2=max(ans2,big[i]);
        }

        printf("Case %d. ",k);
        if(ans1>=ans2) printf("Increasing (%d). Decreasing (%d).\n",ans1,ans2);
        else printf("Decreasing (%d). Increasing (%d).\n",ans2,ans1);
    }
}
