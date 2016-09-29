#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
int Parent[5010];
int Rank[5010];

int Find(int x){
    if (x==Parent[x]) return x;
    Parent[x]=Find(Parent[x]);
    return Parent[x];
}

void Union(int x, int y){
    x=Find(x);
    y=Find(y);

    if(x!= y)  {Parent[x]=y; Rank[y]+=Rank[x];}
}

int main(){
    int C,R;
    string s,a,b;
    while(1){
        cin>>C>>R;
        if (C==0 && R==0) break;

        mp.clear();
        for (int i=1;i<=C;i++)  {cin>>s; mp[s]=i; Parent[i]=i; Rank[i]=1;}
        for(int i=1;i<=R;i++){
            cin>>a>>b;
            Union(mp[a], mp[b]);
        }
        int mx=0;
        for(int i=1;i<=C;i++) mx=max(mx,Rank[i]);
        printf("%d\n",mx);
    }
}
