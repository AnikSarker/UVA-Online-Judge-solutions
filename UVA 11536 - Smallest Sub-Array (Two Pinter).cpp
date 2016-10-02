#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int n,m,k,check[MAX], X[MAX];
int solve() {
    int cnt=0;
	int ans=n+1;
	int lo=1;
	for(int hi=1; hi<=n;hi++){
		int t=X[hi];
		check[t]++;
		if (t<=k && check[t]==1) cnt++;

		while (lo<=hi && cnt==k) {
			ans=min(ans,hi-lo+1);
			int p=X[lo++];
			check[p]--;
			if (p<=k && check[p]==0) cnt--;
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
        for(int j=1;j<MAX;j++) {check[j]=0; X[j]=0;}
        scanf("%d %d %d",&n,&m,&k);

        X[1]=1;
        X[2]=2;
        X[3]=3;
        for(int j=4;j<=n;j++)   X[j]=(X[j-1]+X[j-2]+X[j-3])%m+1;

        printf("Case %d: ", i);
		int ret=solve();
		if(ret<=n) printf("%d\n",ret);
		else printf("sequence nai\n");
	}
}
