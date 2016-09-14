#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	bool endmark;
	node *next[10+1];
	node()
	{
		endmark=false;
		for(int i=0;i<10;i++) next[i]=NULL;
	}
}*root;

void insert(char *str)
{
	node *curr=root;
	for(int i=0;str[i];i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=true;

}

bool search(char *str)
{	node *curr=root;
	for(int i=0;str[i];i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]->endmark==1 && str[i+1]) return true;
		curr=curr->next[id];
	}
	return false;
}

void del(node *cur)
{
      for(int i=0;i<10;i++){
             if(cur->next[i])
                  del(cur->next[i]) ;
      }
         delete(cur) ;
}

int main(){

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
    {
        root=new node();
        int num;
        cin>>num;
        char str[num][11];
        for(int i=0; i<num; i++)
        {
            scanf("%s",str[i]);
            insert(str[i]);
        }

        bool flag=0;
        for(int i=0; i<num; i++)
        {
            flag=flag|search(str[i]);
        }
        del(root);
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
	return 0;
}

