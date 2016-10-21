#include<bits/stdc++.h>
using namespace std;

char num[2005];
int n;
int mod(){
    int i,y=0;
    for (i=0;num[i];i++){
        y=y*10+num[i]-'0';
        y=y%n;}
    return y;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf(" %d %s",&n,num);
        printf("%d\n",mod());
    }
}
