#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
double n,p,I;

double solve(){
    double ans=0;
    double res=pow(1-p,I-1)*p;
    double cycle=pow(1-p,n);

    while(res>EPS){
        ans+=res;
        res=res*cycle;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%lf %lf %lf",&n,&p,&I);
        printf("%0.4lf\n",solve());
    }
}
