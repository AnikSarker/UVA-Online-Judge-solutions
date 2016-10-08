#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define INF 1e9
int ara[MAX];
int I1[MAX],I2[MAX];
int n;
int lis[MAX],lds[MAX];

int Lis_Lds(){
    I1[0]=I2[0]=-INF;
    for(int i=1;i<=n;i++)  I1[i]=I2[i]=INF;

    int len1=0;
    int len2=0;
    for(int i=1;i<=n;i++ ){
        int pos1=lower_bound(I1,I1+len1+1,ara[i])-I1;
        int pos2=lower_bound(I2,I2+len2+1,ara[n+1-i])-I2;
        I1[pos1]=ara[i];
        I2[pos2]=ara[n+1-i];
        lis[i]=pos1;
        lds[n+1-i]=pos2;

        len1=max(len1,pos1);
        len2=max(len2,pos2);
    }
}

int main(){
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) scanf("%d",&ara[i]);
        Lis_Lds();

        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,min(n,2*min(lis[i],lds[i])-1));
        printf("%d\n",mx);
    }
}
