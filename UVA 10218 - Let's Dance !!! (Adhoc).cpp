#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        double m,w;
        int c;
        scanf("%lf %lf %d",&m,&w,&c);
        if(m==0 && w==0) break;

        double sum=0;
        double p=m/(m+w);
        for(int i=0;i<=c;i+=2){
            double val=pow(p,i)*pow(1-p,c-i);
            for(int j=i+1;j<=c;j++) val=(val*j)/(j-i);
            sum+=val;
        }
        printf("%.7lf\n",sum);
    }
}
