#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main(){
    LL n;
    while(scanf("%lld",&n)==1){
        LL ans=n*n*(n+1)*(n+1);
        printf("%lld\n",ans/4);
    }
}
