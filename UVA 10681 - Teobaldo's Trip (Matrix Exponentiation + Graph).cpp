#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int n;

struct Matrix{
    bool m[MAX][MAX];
};

Matrix multiply(Matrix A,Matrix B){
    Matrix ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.m[i][j]=0;
            for(int k=1;k<=n;k++){
                ans.m[i][j]|=A.m[i][k]&B.m[k][j];
            }
        }
    }
    return ans;
}

Matrix power(Matrix mat,int p){
    Matrix res;
    Matrix ans;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans.m[i][j]=0;
            res.m[i][j]=mat.m[i][j];
        }
        ans.m[i][i]=1;
    }

    while(p){
        if(p%2==1) ans=multiply(ans,res);
        res=multiply(res,res);
        p=p/2;
    }
    return ans;
}

Matrix adj;
int main(){
     int e,a,b;
     while(1){
            scanf("%d %d",&n,&e);
            if(n==0 && e==0) break;
            memset(adj.m,0,sizeof(adj.m));
            for(int i=1;i<=e;i++){
                scanf("%d %d",&a,&b);
                adj.m[a][b]=1;
                adj.m[b][a]=1;
            }
            int s,e,d;
            scanf("%d %d %d",&s,&e,&d);
            Matrix ret=power(adj,d);


            if(ret.m[s][e]!=0) printf("Yes, Teobaldo can travel.");
            else printf("No, Teobaldo can not travel.");
            printf("\n");
    }
}
