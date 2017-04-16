#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;
set<pii>HULL;
int n;
pii a[1000000];
int side_of_convex_hull(pii p1,pii p2,pii p)
{
	int val=(p.S-p1.S)*(p2.F-p1.F)-(p2.S-p1.S)*(p.F-p1.F);
	if(val>0)
		return 1;
	if(val<0)
		return -1;
	return 0;
}
int dist(pii p,pii q)
{
	int res=0;
	res+=(p.S-q.S);
	res*=res;
	int tes=(p.F-q.F);
	tes*=tes;
	res+=tes;
	return res;
}
double linedistance(pii p1,pii p2,pii p)
{
	int val=abs((p.S-p1.S)*(p2.F-p1.F)-(p2.S-p1.S)*(p.F-p1.F));
	double temp=sqrt(dist(p1,p2));
	double res=1.0*val/temp;
	return res;
}
void ans(pii p1,pii p2,int num)
{
	//cout<<"("<<p1.F<<","<<p1.S<<")"<<"("<<p2.F<<","<<p2.S<<")"<<num<<endl;
	int ind=-1;
	double max_dist=0.0;
	for(int i=0;i<n;i++)
	{
		double temp=linedistance(p1,p2,a[i]);
		if(side_of_convex_hull(p1,p2,a[i])==num&&temp>max_dist)
		{
			//cout<<i<<" ";
			ind=i;
			max_dist=temp;
		}
	}
	//cout<<endl;
	if(ind==-1)
	{
		HULL.insert(p1);
		HULL.insert(p2);
		//cout<<"done\n";
		return;
	}
	ans(a[ind],p1,-side_of_convex_hull(a[ind],p1,p2));
	ans(a[ind],p2,-side_of_convex_hull(a[ind],p2,p1));

}
int main()
{

    cin>>n;

    for(int i=0;i<n;i++)
    	cin>>a[i].F>>a[i].S;
    int minimum_x=0,maximum_x=0;
    for(int i=1;i<n;i++)
    {
    	if(a[i].F<a[minimum_x].F)
    		minimum_x=i;
    	if(a[i].F>a[maximum_x].F)
    		maximum_x=i;
    }

    cout<<"the points in convex HULL are:\n";
    ans(a[minimum_x],a[maximum_x],1);
    ans(a[minimum_x],a[maximum_x],-1);
    while(!HULL.empty())
    {
    	cout<<"("<<(*HULL.begin()).F<<","<<(*HULL.begin()).S<<")";
    	HULL.erase(HULL.begin());
    }
    return 0;
}
