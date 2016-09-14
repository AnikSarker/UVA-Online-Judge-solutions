#include<bits/stdc++.h>
using namespace std;
#define MAX 2005
int ara[MAX];

int main(){
    int n,p,q;
    while(1){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) ara[i]=-1;
        if(n==0) break;

        bool flag=1;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p,&q);
            int pos=n+1-i-q;
            if(flag==1 && pos>=1 && pos<=n && ara[pos]==-1) ara[pos]=p;
            else flag=0;
        }
        if(flag==0) printf("-1\n");
        else for(int i=n;i>=1;i--){
            printf("%d",ara[i]);
            if(i>1) printf(" ");
            else printf("\n");
        }
    }
}
