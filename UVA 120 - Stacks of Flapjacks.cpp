#include<bits/stdc++.h>
using namespace std;
vector<int>ara;
int mirror[105];
int indx[105];
int n;

void getAra(string s){
    ara.clear();
    int i=0,temp=0;
    while(1){
        if(s[i]==' ') {ara.push_back(temp);temp=0;}
        else if(!s[i])  {ara.push_back(temp); break;}
        else temp=temp*10+s[i]-'0';
        i++;
    }
}

void flip(int x){
    for(int i=0;i<=x/2;i++) swap(ara[x-i],ara[i]);
}

int main(){
    string s;
    while(getline(cin,s)){
        cout<<s<<endl;
        getAra(s);
        n=ara.size();

        for(int i=0;i<n;i++) mirror[i]=ara[i];
        sort(mirror,mirror+n);
        for(int i=0;i<n;i++) {int val=mirror[i]; indx[val]=i;}
        for(int i=0;i<n;i++) {int val=ara[i]; ara[i]=indx[val];}

        for(int i=n-1;i>=0;i--){
            int curr=i;
            int j;
            for(j=n-1;j>=0;j--) if(ara[j]==curr) break;

            if(i==j) continue;
            printf("%d ",n-j); flip(j);
            printf("%d ",n-i); flip(i);
        }
        printf("0\n");
    }


}
