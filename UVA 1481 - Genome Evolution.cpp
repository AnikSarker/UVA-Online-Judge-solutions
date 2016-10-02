#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
#define inf 1e9
#define pb push_back
#define f first
#define s second
#define pii pair<int,int>
#define piii pair<int,pii>

piii ara[MAX];

int main() {
	int t,n,m;
	scanf("%d", &t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
		    scanf("%d %d",&ara[i].s.f,&ara[i].f);
		    ara[i].s.s=0;
        }

		scanf("%d", &m);
		for (int i=n;i<m+n;i++){
		    scanf("%d %d",&ara[i].s.f,&ara[i].f);
		    ara[i].s.s=1;
        }
		sort(ara,ara+m+n);

		int mx=-inf;
		int ret=inf;
		for (int i=0; i<m+n;i++) {
            int val=ara[i].s.f+ara[i].f;
			if(ara[i].s.s==1) ret=min(ret,val- mx);
			else mx=max(mx,val);
		}

		mx=-inf;
		for (int i=m+n-1;i>=0;i--){
            int val=ara[i].s.f-ara[i].f;
			if (ara[i].s.s==1) ret=min(ret,val-mx);
			else mx=max(mx,val);
		}
		printf("%d\n", ret);
	}
}
