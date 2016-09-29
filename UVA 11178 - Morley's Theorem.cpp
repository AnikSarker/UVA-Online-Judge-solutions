#include<bits/stdc++.h>
using namespace std;
#define pii pair<double,double>
#define mp make_pair
#define f first
#define s second

double pi=acos(-1);

struct line{
    double a;
    double b;
    double c;
    double ang;

    line(double x,double y,double z){a=x;b=y;c=z;}
    line(pii m,pii n){
        a=n.s-m.s;
        b=m.f-n.f;
        c=m.f*n.s-m.s*n.f;
        ang=atan2(m.s-n.s,m.f-n.f);
    }
};

line TrisectorOfAngle(line p,line q,pii common){
     double ang1=p.ang;
     double ang2=q.ang;
     double diff=ang1-ang2;

     if(fabs(diff)>pi){
        if(ang1<0) ang1+=2*pi;
        if(ang2<0) ang2+=2*pi;
     }

     double ang=ang1-(ang1-ang2)/3;

     if(fabs(ang*2)==pi) return line(1,0,0);
     double m=tan(ang);
     return line(m,-1,m*common.f-common.s);
}

pii solve(line m,line n){
    double det=m.a*n.b-n.a*m.b;
    double x=(m.c*n.b-n.c*m.b)/det;
    double y=(m.a*n.c-n.a*m.c)/det;
    return make_pair(x,y);
}

int main(){
    int t;
    scanf("%d",&t);

        for(int i=1;i<=t;i++){
            pii a,b,c;
            scanf("%lf %lf %lf %lf %lf %lf",&a.f,&a.s,&b.f,&b.s,&c.f,&c.s);

            line AB(b,a);
            line BA(a,b);

            line BC(c,b);
            line CB(b,c);

            line CA(a,c);
            line AC(c,a);

            pii D=solve(TrisectorOfAngle(BC,BA,b),TrisectorOfAngle(CB,CA,c));
            pii E=solve(TrisectorOfAngle(AC,AB,a),TrisectorOfAngle(CA,CB,c));
            pii F=solve(TrisectorOfAngle(BA,BC,b),TrisectorOfAngle(AB,AC,a));

            printf("%lf %lf %lf %lf %lf %lf\n",D.f,D.s,E.f,E.s,F.f,F.s);
        }
}




