#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;

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


int main(){
    int t;
    scanf("%d",&t);

    for(int p=1;p<=t;p++){
        P.clear();
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            Point now;
            scanf("%lf %lf",&now.x,&now.y);
            P.push_back(now);
        }

        convex_hull();

        double mn=1e9;
        for(int i=0;i<k-1;i++){
            double p=H[i].x-H[i+1].x;
            double q=H[i].y-H[i+1].y;

            double ans=0;
            if(p==0){
                for(int j=0;j<n;j++){
                    ans+=(P[j].x-H[i%k].x);
                }
            }
            else{
                double m=q/p;
                double c=H[i%k].y-m*H[i%k].x;

                for(int j=0;j<n;j++){
                    double temp=fabs(m*P[j].x-P[j].y+c);
                    temp/=sqrt(m*m+1);
                    ans+=temp;
                }
            }
            if(ans<0) ans=-ans;
            if(ans<mn) mn=ans;
        }

        if(n==1) mn=0;
        printf("Case #%d: %0.3lf\n",p,mn/n);
    }
}
