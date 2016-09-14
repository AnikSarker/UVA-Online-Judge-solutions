#include<bits/stdc++.h>
using namespace std;
vector<int>ara;
int check[10005][2];


int main(){
    int t,n,p;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        ara.clear();
        ara.push_back(0);

        for(int j=1;j<=2*n;j++){
            scanf("%d",&p);
            ara.push_back(p);
            if(!check[p][0]) check[p][0]=j;
            else check[p][1]=j;
        }

        int ans=0;
        for(int j=1;j<=2*n;j+=2){
            int p=ara[j];
            int q=ara[j+1];
            if(ara[j]==ara[j+1]) continue;

            ara[check[p][1]]=q;
            ara[j+1]=p;

            int temp1=check[q][1];
            int temp2=check[p][1];
            check[q][0]=min(temp1,temp2);
            check[q][1]=max(temp1,temp2);
            ans++;
        }
        printf("%d\n",ans);
    }


}
