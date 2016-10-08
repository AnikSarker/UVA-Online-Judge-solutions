#include<bits/stdc++.h>
using namespace std;
#define MAX 251*251+5
int PosA[MAX];
multiset<int>LIS;
multiset<int>:: iterator it;

int main(){
    int n,p,x,t,a,b;
    scanf("%d",&t);

    for(int k=1;k<=t;k++){
        scanf("%d %d %d",&n,&a,&b);

        memset(PosA,0,sizeof(PosA));
        for(int i=1;i<=a+1;i++)  {scanf("%d",&p); PosA[p]=i;}

        LIS.clear();
        for(int i=1;i<=b+1;i++){
            scanf("%d",&x);
            if(PosA[x]==0) continue;

            LIS.insert(PosA[x]);
            it=LIS.lower_bound(PosA[x]);
            it++;
            if(it!=LIS.end()) LIS.erase(it);
        }
        printf("Case %d: %d\n",k,LIS.size());
    }
}
