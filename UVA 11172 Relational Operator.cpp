#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d %d",&a,&b);
        if(a==b) printf("=");
        else if(a>b) printf(">");
        else printf("<");
        printf("\n");
    }
}
