#include<bits/stdc++.h>
using namespace std;
stack<char>stk;

bool solve(string s){
        while(!stk.empty()) stk.pop();

        for(int i=0;s[i];i++){
            char p=s[i];
            if(p=='(' || p=='{' || p=='[' ) stk.push(p);
            else{
                if(stk.empty()) return false;
                char q=stk.top();
                if((p==')' && q=='(') || (p=='}' && q=='{') || (p==']' && q=='['))   stk.pop();
                else return false;
            }
        }

        if(!stk.empty()) return false;
        return true;
}

int main(){
    int t;
    scanf("%d ",&t);
    string s;

    for(int i=1;i<=t;i++){
        getline(cin,s);
        if(solve(s)==false) printf("No\n");
        else printf("Yes\n");
    }
}
