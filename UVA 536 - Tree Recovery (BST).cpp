#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int inorder[50];
int preorder[50];
map<int,char>BST;

string s1;
string s2;
long long int pre=0;

char construct(int start,int last,int i){
    if(start>last) return 0;
    char now=s1[pre++];
    int in=inorder[now-'A'];
    BST[2*i]=construct(start,in-1,2*i);
    BST[2*i+1]=construct(in+1,last,2*i+1);
    return now;
}


void postorder(int i){
    if(!BST[i]) return;
    postorder(2*i);
    postorder(2*i+1);
    printf("%c",BST[i]);
}

int main(){

    while(cin>>s1>>s2){
        BST.clear();
        for(int i=0;s1[i];i++) preorder[s1[i]-'A']=i;
        for(int i=0;s2[i];i++) inorder[s2[i]-'A']=i;

        BST[1]=construct(0,s1.size()-1,1);
        pre=0;
        postorder(1);
        printf("\n");
    }
}
