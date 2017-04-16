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
pii p0;
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
pii next_top(stack<pii>s)
{
	s.pop();
	return s.top();
}
int ans(pii p,pii q,pii r)
{
	int res=(q.S-p.S)*(r.F-q.F)-(r.S-q.S)*(q.F-p.F);
	if(res==0)
		return 0;//collinear
	if(res<0)
		return 2;//counter-clockwise
	return 1;// clockwise
}
bool COMP(pii p1,pii p2)
{
	int val=(p1.S-p0.S)*(p2.F-p0.F)
			-(p1.F-p0.F)*(p2.S-p0.S);
	if(val<0)
		return 1;
	if(val>0)
		return 0;
	return (dist(p1,p0)<=dist(p2,p0));
}
int main()
{



    int n;
    cin>>n;
    pii a[n];

    for(int i=0;i<n;i++)
    	cin>>arr[i].F>>arr[i].S;
    if(n<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	int mini=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i].S<arr[mini].S)
			mini=i;
		else if(arr[i].S==arr[mini].S)
			if(arr[i].F<arr[mini].F)
				mini=i;
	}
	p0=arr[mini];
	swap(arr[mini],arr[0]);
	sort(arr,arr+n,COMP);

	vector<pii>ready;
	ready.pb(arr[0]);
	for(int i=1;i<n;i++)
	{
		while(i+1<n&&ans(p0,arr[i],arr[i+1])==0)
			i++;
		ready.pb(arr[i]);
	}
	if(sz(ready)<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	stack<pii>stk;
	stk.push(ready[0]);
	stk.push(ready[1]);
	stk.push(ready[2]);
	for(int i=3;i<sz(ready);i++)
	{
		while(ans(next_top(s),s.top(),ready[i])!=2)
			stk.pop();
		stk.push(ready[i]);
	}
	cout<<"the points in convex hull are:\n";
	while(!stk.empty())
	{
		pii temp=stk.top();
		cout<<"("<<temp.F<<","<<temp.S<<")";
		stk.pop();
	}

    return 0;
}
