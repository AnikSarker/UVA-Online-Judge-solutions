#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >ara;
vector<int>length;
int main(){
    int n,x,y;
    while(1){
        ara.clear();
        length.clear();
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            length.push_back((y-x)/2+1);
            ara.push_back(make_pair(y-length[i],x));           // pair of the middle point and the starting point.
        }

        sort(ara.begin(),ara.end());
        int limit=-100,flag=1;
        for(int i=0;i<n;i++){
            limit=max(limit,ara[i].second);
            if(limit>ara[i].first) {flag=0; break;}
            limit+=length[i];
        }
        if(flag==1) printf("YES\n");
        else printf("NO\n");
    }
}
