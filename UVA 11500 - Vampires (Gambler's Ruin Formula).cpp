#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

int main(){
    double ev1,ev2,at,d;
    while(1){
        scanf("%lf %lf %lf %lf",&ev1,&ev2,&at,&d);
        if(ev1==0 && ev2==0 && at==0 && d==0) break;
        double p=at/6;
        double q=1-p;
        double n1=(ceil)(ev1/d);
        double n2=(ceil)(ev2/d);
        double ans=0;
        if(fabs(p-q)<EPS) ans=n1/(n1+n2);
        else ans=(1-pow(q/p,n1))/(1-pow(q/p,n1+n2));   //Gambler's Ruin Formula
        printf("%0.1lf\n",ans*100);
    }
}
