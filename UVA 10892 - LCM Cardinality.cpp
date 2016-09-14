#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAX 100005

bool check[MAX];
vector<LL>primes;
vector<LL>powers;
LL n,m;
LL mod=1000000007;

void sieve(){
    for(int i=2;i<MAX;i++){
        if(check[i]==0){
            primes.push_back(i);
            for(int j=2*i;j<MAX;j+=i)  check[j]=1;
        }
    }
}

void solve(){
    powers.clear();
    LL p=sqrt(n);
    for(int i=0;i<primes.size();i++){
        LL val=primes[i];
        int cnt=0;
        while(n%val==0){
            n=n/val;
            cnt++;
        }
        powers.push_back(cnt);
    }
    if(n!=1)  powers.push_back(1);
}

int main(){
    sieve();

    while(1){
        scanf("%lld",&n);
        m=n;
        if(n==0) break;
        solve();

        LL ans=1;
        for(int j=0;j<powers.size();j++){
            ans=ans*(2*powers[j]+1);
        }
        ans=(ans+1)/2;

        printf("%lld %lld\n",m,ans);

    }
}
