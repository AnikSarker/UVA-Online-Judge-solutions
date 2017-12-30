#include<bits/stdc++.h>
using namespace std;
#define MAX 105
char ara[MAX][MAX];
char now;
int r,c;
int M,N;

bool check(int n){
    if(r-n<0) return false;
    if(r+n>=M) return false;
    if(c-n<0) return false;
    if(c+n>=N) return false;
    for(int i=r-n;i<=r+n;i++) if(ara[i][c-n]!=now) return false;
    for(int i=r-n;i<=r+n;i++) if(ara[i][c+n]!=now) return false;
    for(int i=c-n;i<=c+n;i++) if(ara[r-n][i]!=now) return false;
    for(int i=c-n;i<=c+n;i++) if(ara[r+n][i]!=now) return false;
    return true;
}

int main(){
    int t,Q;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&M,&N,&Q);
        for(int i=0;i<M;i++){
            scanf("%s ",ara[i]);
        }
        printf("%d %d %d\n",M,N,Q);
        for(int i=1;i<=Q;i++){
            scanf("%d %d",&r,&c);
            now=ara[r][c];
            int cnt=1;
            while(check(cnt)) cnt++;
            printf("%d\n",2*cnt-1);
        }
    }
}
