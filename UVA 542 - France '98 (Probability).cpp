#include <bits/stdc++.h>
using namespace std;
double ara[20][20];
char s[20][100];
double prob[20];
double temp[20];

int main(){
    for(int i=1;i<=16;i++) scanf("%s",s[i]);
    for(int i=1;i<=16;i++){
        for(int j=1;j<=16;j++){
            scanf("%lf",&ara[i][j]);
        }
    }

    for(int i=1;i<=16;i++) prob[i]=1;

    for(int rnd=1;rnd<=4;rnd++){
        for(int i=1;i<=16;i++) temp[i]=0;
        int sze=1<<(rnd-1);

        for(int i=1;i<=16;i++){
            int val=(i-1)/sze+1;
            int st,en;
            if(val%2==0) {st=(val-2)*sze+1; en=(val-1)*sze;}
            else {st=val*sze+1; en=(val+1)*sze;}

            for(int j=st;j<=en;j++){
                temp[i]+=(prob[j]*(ara[i][j]/100));
            }
        }
        for(int i=1;i<=16;i++) prob[i]*=temp[i];
    }

    for(int i=1;i<=16;i++){
        printf("%-10s ",s[i]);
        printf("p=%.2lf%%\n",prob[i]*100);
    }
}
