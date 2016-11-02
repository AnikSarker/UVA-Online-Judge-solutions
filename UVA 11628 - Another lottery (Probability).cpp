#include <bits/stdc++.h>
using namespace std;
#define MAX 10005
int ara[MAX];

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(){
    int n,m,p;
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) scanf("%d",&p);
            sum+=p;
            ara[i]=p;
        }
        for(int i=0;i<n;i++){
            if(ara[i]==0) {printf("0 / 1\n"); continue;}
            int g=gcd(sum,ara[i]);
            printf("%d / %d\n",ara[i]/g,sum/g);
        }
    }
}
