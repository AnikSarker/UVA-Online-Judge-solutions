#include<bits/stdc++.h>
using namespace std;
#define pii pair<double,double>
#define f first
#define s second

struct line{
    double a;
    double b;
    double c;
    line(pii m,pii n){
        a=n.s-m.s;
        b=m.f-n.f;
        c=m.f*n.s-m.s*n.f;
    }
};

pii third(pii a,pii b){
    double p=(2*a.f+b.f)/3;
    double q=(2*a.s+b.s)/3;
    return make_pair(p,q);
}

pii solve(line m,line n){
    double det=m.a*n.b-n.a*m.b;
    double x=(m.c*n.b-n.c*m.b)/det;
    double y=(m.a*n.c-n.a*m.c)/det;
    return make_pair(x,y);
}

pii section(pii a,pii b,pii c,pii d){
    line m(a,b);
    line n(c,d);
    return solve(m,n);
}

double area(pii a,pii b,pii c){
    double ans=a.f*b.s+b.f*c.s+c.f*a.s-a.s*b.f-b.s*c.f-c.s*a.f;
    return ans/2;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        double ax,ay,bx,by,cx,cy;
        scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);

        pii a=make_pair(ax,ay);
        pii b=make_pair(bx,by);
        pii c=make_pair(cx,cy);

        pii d=third(b,c);
        pii e=third(c,a);
        pii f=third(a,b);

        pii p=section(b,e,a,d);
        pii q=section(c,f,b,e);
        pii r=section(a,d,c,f);
        printf("%0.0lf\n",area(p,q,r));
    }


}
