#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int ara[1005];

int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;

        for(int i=0;i<n;i++) scanf("%d",&ara[i]);
        sort(ara,ara+n);

        int flag=0;
        int ans;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int k=0,l=n-1;

                if(i==j) continue;
                while(k<l){
                    while(k==i || k==j) k++;
                    while(l==i || l==j) l--;

                    if(k<l){
                        int val=ara[k]+ara[l]+ara[j];
                        if(val==ara[i]){
                            flag=1;
                            ans=ara[i];
                            break;
                        }
                        else if(val<ara[i]) k++;
                        else l--;
                    }
                }
            }
            if(flag==1) break;
        }
        if(flag==0) printf("no solution\n");
        else printf("%d\n",ans);
    }
}
