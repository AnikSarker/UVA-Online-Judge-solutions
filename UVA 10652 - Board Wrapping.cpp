#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define pii pair<double,double>
#define mp make_pair
#define pb push_back
#define f first
#define s second

double pi=acos(-1);
vector<pii>Vertex;
pii ConvexHull[MAX];
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

    Vertex.pb(a);
    Vertex.pb(b);
    Vertex.pb(c);
    Vertex.pb(d);
}

double monotone_chain() {
    sort(Vertex.begin(), Vertex.end());
    m=0;
    for(int i=0;i<Vertex.size();i++) {
        while(m>=2 && cross(ConvexHull[m-2],ConvexHull[m-1],Vertex[i])<=0) m--;
        ConvexHull[m++]=Vertex[i];
    }
    for(int i=Vertex.size()-1,t=m+1; i>=0; i--) {
        while(m>=t && cross(ConvexHull[m-2],ConvexHull[m-1],Vertex[i])<= 0) m--;
        ConvexHull[m++]=Vertex[i];
    }
}

double area(){
    double ans=0;
    int Size=m;
    for(int i=0;i<Size-1;i++){
        ans+=ConvexHull[i].f*ConvexHull[i+1].s-ConvexHull[i].s*ConvexHull[i+1].f;
    }
    ans+=ConvexHull[Size-1].f*ConvexHull[0].s-ConvexHull[Size-1].s*ConvexHull[0].f;
    return fabs(ans)/2;
}

int main(){
    int n,t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++){
        Vertex.clear();

        scanf("%d",&n);
        double x,y,w,h,phi,ans=0;

        for(int i=1;i<=n;i++){
            scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&phi);
            findVertex(x,y,w,h,phi);
            ans+=w*h;
        }

        monotone_chain();
        printf("%.1lf %%\n",ans/area()*100);
    }
}


