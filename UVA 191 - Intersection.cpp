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

pii solve(line m,line n){
    double det=m.a*n.b-n.a*m.b;
    double x=(m.c*n.b-n.c*m.b)/det;
    double y=(m.a*n.c-n.a*m.c)/det;
    return make_pair(x,y);
}

bool section(pii a,pii b,pii c,pii d){
    line m(a,b);
    line n(c,d);
    pii sect=solve(m,n);

    bool flag=(min(a.f,b.f)<=sect.f && sect.f<=max(a.f,b.f)) && (min(a.s,b.s)<=sect.s && sect.s<=max(a.s,b.s));
    flag&=(min(c.f,d.f)<=sect.f && sect.f<=max(c.f,d.f)) && (min(c.s,d.s)<=sect.s && sect.s<=max(c.s,d.s));
    return flag;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        double x1,x2,y1,y2;
        double xL,yT,xR,yB;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        pii p1=make_pair(x1,y1);
        pii p2=make_pair(x2,y2);

        scanf("%lf %lf %lf %lf",&xL,&yT,&xR,&yB);
        pii LT=make_pair(xL,yT);
        pii LB=make_pair(xL,yB);
        pii RT=make_pair(xR,yT);
        pii RB=make_pair(xR,yB);

        // if at least one point is outside
        bool flag=0;
        flag|=section(p1,p2,LT,LB);
        flag|=section(p1,p2,LT,RT);
        flag|=section(p1,p2,RT,RB);
        flag|=section(p1,p2,LB,RB);

        //if both points are inside
        if(xL>xR) swap(xL,xR);
        if(yB>yT) swap(yB,yT);
        if(xL<=x1 && x1<=xR && yB<=y1 && y1<=yT) flag=1;
        if(xL<=x2 && x2<=xR && yB<=y2 && y2<=yT) flag=1;

        if(flag==1) printf("T\n");
        else printf("F\n");
    }
}
