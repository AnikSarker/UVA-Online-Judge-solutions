#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    bool mark=0;
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            n=n/i;
            if(mark==1) printf(" x");
            else mark=1;
            printf(" %d",i);
        }
    }
    if(n!=1){
        if(mark==1) printf(" x");
        printf(" %d",n);
    }
}

int main(){
    int n;
    bool mark=0;
    while(1){
        if(mark==1) printf("\n");
        else mark=1;

        scanf("%d",&n);
        if(n==0) break;

        printf("%d =",n);
        if(n<0) printf(" -1 x");
        solve(abs(n));
    }

}
