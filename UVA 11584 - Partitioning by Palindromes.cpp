#include<bits/stdc++.h>
using namespace std;
bool pal[1005][1005];
int part[1005];
int n;
string s;

void palindromeSubstr(){
    for(int i=0;i<n;i++) pal[i][i]=true;
    for(int i=0;i<n-1;i++) pal[i][i+1]=(s[i]==s[i+1]);

    for(int p=2;p<n;p++){
        for(int i=0,j=p; j<n; i++,j++){
            pal[i][j]=(s[i]==s[j]);
            if(pal[i+1][j-1]==false) pal[i][j]=false;
        }
    }
}

void findPartition(){
    for(int i=0;i<n;i++) part[i]=1e9;
    for(int i=0;i<n;i++){
        if(pal[0][i]==true) part[i]=1;
        else{
            for(int j=0;j<i;j++){
                if(pal[j+1][i]==true) part[i]=min(part[i],part[j]+1);
            }
        }
    }
}


int main(){
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        cin>>s;
        n=s.size();
        palindromeSubstr();
        findPartition();

        printf("%d\n",part[n-1]);
    }
}
