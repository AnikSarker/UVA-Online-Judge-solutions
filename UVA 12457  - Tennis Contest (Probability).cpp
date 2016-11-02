#include <bits/stdc++.h>
using namespace std;
#define MAX 60
long long int nCr[MAX][MAX];

void process(){
    for(int i=0;i<MAX;i++) nCr[i][0]=1;
    for(int i=1;i<MAX;i++) nCr[0][i]=0;

    for(int i=1;i<MAX;i++){
        for(int j=1;j<MAX;j++){
            nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
        }
    }
}

int main(){
    process();

    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        int n;
        double p,sum=0;
        scanf("%d %lf",&n,&p);
        for(int i=n;i<=2*n-1;i++){
            sum+=nCr[2*n-1][i]*pow(p,i)*pow(1-p,2*n-1-i);
        }
        printf("%.2lf\n",sum);
    }
}
