#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define pii pair<double,double>
#define mp make_pair
#define pb push_back
#define f first
#define s second

double pi=acos(-1);
vector<pii>V;
pii H[MAX];
int m;

double cross(pii o, pii a, pii b) {
    return (a.f-o.f)*(b.s-o.s)-(a.s-o.s)*(b.f-o.f);
}

void findVertex(double midX,double midY,double w,double h,double ang){
    pii a,b,c,d;
    ang=-ang*pi/180;

    a.f=midX-w/2*cos(ang)+h/2*sin(ang);
    a.s=midY-w/2*sin(ang)-h/2*cos(ang);

    b.f=midX+w/2*cos(ang)+h/2*sin(ang);
    b.s=midY+w/2*sin(ang)-h/2*cos(ang);

    c.f=midX+w/2*cos(ang)-h/2*sin(ang);
    c.s=midY+w/2*sin(ang)+h/2*cos(ang);

    d.f=midX-w/2*cos(ang)-h/2*sin(ang);
    d.s=midY-w/2*sin(ang)+h/2*cos(ang);

    V.pb(a);
    V.pb(b);
    V.pb(c);
    V.pb(d);
}

double convex_hull() {
    sort(V.begin(), V.end());
    m=0;
    for(int i=0;i<V.size();i++) {
        while(m>=2 && cross(H[m-2],H[m-1],V[i])<=0) m--;
        H[m++]=V[i];
    }
    for(int i=V.size()-1,t=m+1; i>=0; i--) {
        while(m>=t && cross(H[m-2],H[m-1],V[i])<= 0) m--;
        H[m++]=V[i];
    }
}

double area(){
    double ans=0;
    int Size=m;
    for(int i=0;i<Size-1;i++){
        ans+=H[i].f*H[i+1].s-H[i].s*H[i+1].f;
    }
    ans+=H[Size-1].f*H[0].s-H[Size-1].s*H[0].f;
    return fabs(ans)/2;
}

int main(){
    int n,t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        V.clear();

        scanf("%d",&n);
        double x,y,w,h,phi,ans=0;

        for(int i=1;i<=n;i++){
            scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&phi);
            findVertex(x,y,w,h,phi);
            ans+=w*h;
        }

        convex_hull();
        printf("%.1lf %%\n",ans/area()*100);
    }
}


