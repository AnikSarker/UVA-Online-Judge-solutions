#include<bits/stdc++.h>
using namespace std;
#define MAX 46500
bool check[MAX];
vector<int>initial;
vector<int>modified;

void sieve(){
    check[1]=1;
    for(int i=2;i<MAX;i++){
        if(check[i]==0){
            initial.push_back(i);
            for(int j=2*i;j<MAX;j+=i){
                check[j]=1;
            }
        }
    }
}

bool isprime(int n){
    if(n<MAX) return !check[n];
    for(int i=0;i<initial.size();i++){
        if(n%initial[i]==0) return 0;
    }
    return 1;
}

void solve(int lo,int hi){
    modified.clear();
    for(long long int i=lo;i<=hi;i++){
        if(isprime(i)) modified.push_back(i);
    }
}

int main(){
    sieve();
    int lo,hi;
    int lmin,hmin,lmax,hmax;
    while(scanf("%d %d",&lo,&hi)!=EOF){
        solve(lo,hi);
        if(modified.size()<=1) printf("There are no adjacent primes.\n");
        else{
            int mx=0,mn=2e9;
            for(int i=1;i<modified.size();i++){
                int diff=modified[i]-modified[i-1];
                if(diff>mx) {mx=diff;lmax=modified[i-1];hmax=modified[i];}
                if(diff<mn) {mn=diff;lmin=modified[i-1];hmin=modified[i];}
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",lmin,hmin,lmax,hmax);
        }
    }
}
