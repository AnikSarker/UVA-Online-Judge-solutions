#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(string a,string b){
    if(a<b) return 1;
    else return 0;
}

map<string,int>m;
vector<string>v;
int main(){
    int t;
    scanf("%d\n\n",&t);
    string s;

    while(t--){
        v.clear();
        m.clear();
        int cnt=0;
        while(getline(cin,s)){
            if(s.size()==0) break;
            if(!m[s]) v.push_back(s);
            m[s]++;
            cnt++;
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            printf(" %.4lf\n",m[v[i]]*100.0/cnt);
        }
        if(t>0) printf("\n");
    }
}
