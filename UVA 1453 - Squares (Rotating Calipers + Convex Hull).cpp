#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;

    Point(double a,double b){x=a;y=b;}
    Point(){}

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

Point H[100000];
vector<Point>P;
int k;

double cross(const Point &O, const Point &A, const Point &B){
	return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

double dist(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void convex_hull(){
	int n=P.size();
	k=0;

	sort(P.begin(),P.end());

	for (int i=0;i<n; ++i) {
		while(k >= 2 && cross(H[k-2],H[k-1],P[i])<=0) k--;
		H[k++]=P[i];
	}

	for(int i=n-2,t=k+1;i>=0;i--){
		while (k>= t && cross(H[k-2],H[k-1],P[i])<=0) k--;
		H[k++]=P[i];
	}
}

//rotating calipers technique
double diameter(){
    double mx=0;
    for(int i=0,j=0;i<k;){
        double d1=dist(H[i],H[j]);
        double d2=dist(H[i],H[j+1]);

        if(d2>d1 && j<k-1) j++;
        else {mx=max(mx,d1);i++;}
    }
    return mx;
}

int main(){
    int t;
    scanf("%d",&t);

    for(int p=1;p<=t;p++){
        P.clear();
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            double a,b,c;
            scanf("%lf %lf %lf",&a,&b,&c);
            P.push_back(Point(a,b));
            P.push_back(Point(a+c,b));
            P.push_back(Point(a,b+c));
            P.push_back(Point(a+c,b+c));
        }

        convex_hull();
        double ret=diameter();
        printf("%0.0lf\n",ret);
    }
}
