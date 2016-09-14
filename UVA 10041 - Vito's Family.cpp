#include<bits/stdc++.h>
using namespace std;
int ara[505];
int main(){
    int t,r;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&r);
        for(int i=0;i<r;i++) scanf("%d",&ara[i]);
        sort(ara,ara+r);
        int distance=0;
        for(int i=0;i<r;i++) distance+=abs(ara[i]-ara[r/2]);
        printf("%d\n",distance);
    }
}
