#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

int solve(int n){
    int prev;
    while(1){
        prev=n;
        n=func(n);
        if(prev==n) break;
    }
    return n;
}

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",solve(n));
    }
}
