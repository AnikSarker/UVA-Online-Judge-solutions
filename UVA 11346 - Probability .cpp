#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);

    double a,b,s;
    double ans;
    for(int i=1;i<=t;i++){
        scanf("%lf %lf %lf",&a,&b,&s);

        if(a*b<s) ans=0;
        else if(s==0) ans=100;
        else{
            ans=4*s*log((a*b)/s)+4*s;
            ans=1-ans/(4*a*b);
            ans*=100;
        }
        printf("%.6lf%%\n",ans);
    }
}
