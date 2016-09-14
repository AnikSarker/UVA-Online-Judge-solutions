#include<cstdio>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#define f first
#define s second
using namespace std;
int ara[1005];

int main(){
    int n,p;
    while(cin>>n && n!=0){
        while(cin>>ara[0] && ara[0]!=0){
            for(int i=1;i<n;i++) cin>>ara[i];
            queue<int>q;
            stack<int>stk;
            for(int i=1;i<=n;i++) q.push(i);
            int i;
            for(i=0;i<n;i++){
                int flag=0;
                if(!stk.empty()){
                    if(stk.top()==ara[i]) {flag=1;stk.pop();}
                }
                if(!flag){
                    while(!q.empty()){
                        if(q.front()==ara[i]) break;
                        stk.push(q.front());
                        q.pop();
                    }
                    if(q.empty())  {}
                    else if(q.front()==ara[i]) {q.pop();flag=1;};
                }
                if(flag==0) break;
            }
            if(i==n) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;
    }
}
