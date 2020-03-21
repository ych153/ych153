#include<bits/stdc++.h>
using namespace std;
#define R register
#define forup(i,a,b,n) for(int i=a;i<=b;i+=n)
#define fordown(i,a,b,n) for(int i=a;i>=b;i-=n)
#define forup_q(i,a,b,n) for(R int i=a;i<=b;i+=n)
#define fordown_q(i,a,b,n) for(R int i=a;i>=b;i-=n)
#define ll long long
ll n,m;
ll a[100010];
struct t{
	ll s,lazy,x,y;
}st[400010];
void push_up(ll q){st[q].s=st[q*2].s+st[q*2+1].s;}
void build(ll q,ll x,ll y){
	st[q].x=x;
	st[q].y=y;
	if(x==y){st[q].s=a[x];return;}
	build(q*2,x,(x+y)/2);
	build(q*2+1,(x+y)/2+1,y);
	push_up(q);
}
void tag(ll q,ll k){st[q].lazy+=k;st[q].s+=(st[q].y-st[q].x+1)*k;}
void push_down(ll q){
	tag(q*2,st[q].lazy);
	tag(q*2+1,st[q].lazy);
	st[q].lazy=0;
}
void update(ll q,ll x,ll y,ll k){
	if(x<=st[q].x&&y>=st[q].y){tag(q,k);return;}
	if(x>st[q].y||y<st[q].x)return;
	push_down(q);
	update(q*2,x,y,k);
	update(q*2+1,x,y,k);
	push_up(q);
}
ll sum(ll q,ll x,ll y){
	if(x<=st[q].x&&y>=st[q].y)return st[q].s;
	if(x>st[q].y||y<st[q].x)return 0;
	push_down(q);
	return sum(q*2,x,y)+sum(q*2+1,x,y);
}
int main(){
	scanf("%lld%lld",&n,&m);
	forup_q(i,1,n,1)scanf("%lld",a+i);
	build(1,1,n);
	forup_q(i,1,m,1){
		ll cho,x,y,k;
		scanf("%lld",&cho);
		if(cho==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			update(1,x,y,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",sum(1,x,y));
		}
	}
	return 0;
}
/******\
|ych153|
\******/
