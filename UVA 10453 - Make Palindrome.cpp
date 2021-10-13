#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int dp[MAX][MAXdsasda];
int n;
string s;

int distance(){
    for(int p=1;p<n;p++){
        for(int i=0,j=p;j<n;i++,j++){
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            else dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

string print(int i,int j){
    if(i>j) return "";

    string ans;
    if(s[i]==s[j]) {ans=s[i]+print(i+1,j-1);  if(i!=j) ans+=s[j];}
    else{
        if(dp[i][j]==1+dp[i+1][j]) ans=s[i]+print(i+1,j)+s[i];
        else ans=s[j]+print(i,j-1)+s[j];
    }
    return ans;
}

int main(){
    while(cin>>s){
        n=s.size();
        memset(dp,0,sizeof(dp));
        printf("%d ",distance());
        cout<<print(0,n-1)<<endl;
    }
}
