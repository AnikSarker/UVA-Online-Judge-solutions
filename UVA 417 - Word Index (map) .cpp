#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;


string func(int i){char p='a'+i; string s; s=s+p; return s;}

void preprocess(){
    string temp;
    int cnt=0;
    for(int i=0;i<26;i++) {temp=func(i); mp[temp]=++cnt;}
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++){temp=func(i)+func(j); mp[temp]=++cnt;}

    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            for(int k=j+1;k<26;k++){temp=func(i)+func(j)+func(k); mp[temp]=++cnt;}

    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            for(int k=j+1;k<26;k++)
                for(int l=k+1;l<26;l++) {temp=func(i)+func(j)+func(k)+func(l); mp[temp]=++cnt;}

    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            for(int k=j+1;k<26;k++)
                for(int l=k+1;l<26;l++)
                    for(int m=l+1;m<26;m++){temp=func(i)+func(j)+func(k)+func(l)+func(m); mp[temp]=++cnt;}
}

int main(){
    preprocess();
    string s1,s2;
    while(cin>>s1){
        s2=s1;
        sort(s2.begin(),s2.end());
        if(s2!=s1){printf("0\n");}
        else printf("%d\n",mp[s1]);
    }
}
