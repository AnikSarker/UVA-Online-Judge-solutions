#include <bits/stdc++.h>
using namespace std;
#define MAX 105
double prob[MAX];
int tme[MAX];
int n;

double solve(int tt){
    double ret=0;
    double val=1;
    bool check=0;

    for(int i=0;i<n;i++){
        ret+=prob[i]*fabs(tme[i]);
        if(tme[i]<0) val-=prob[i];
        else check=1;
    }

    printf("Case %d: ",tt);
    if(check==0) printf("God! Save me\n");
    else printf("%.2lf\n",ret/val);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int p=1;p<=t;p++){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d %lf",&tme[i],&prob[i]);
        solve(p);
    }
}
