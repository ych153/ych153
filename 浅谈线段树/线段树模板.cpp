#include<bits/stdc++.h>
using namespace std;
#define R register
#define forup(i,a,b,n) for(int i=a;i<=b;i+=n)
#define fordown(i,a,b,n) for(int i=a;i>=b;i-=n)
#define forup_q(i,a,b,n) for(R int i=a;i<=b;i+=n)
#define fordown_q(i,a,b,n) for(R int i=a;i>=b;i-=n)
int n,m;
struct node{
	int x,y,s,tag;
}st[400010];
int a[100010];
void pushup(int r){
	st[r].s=st[r*2].s+st[r*2+1].s;
}
void build(int x=1,int y=n,int r=1){
	st[r].x=x,st[r].y=y;
	if(x==y){
		st[r].s=a[x];
		return;
	}
	int mid=(x+y)/2;
	build(x,mid,r*2);
	build(mid+1,y,r*2+1);
	pushup(r);
}
void tag(int k,int r){
	st[r].tag+=k,st[r].s+=(st[r].y-st[r].x+1)*k;
}
void pushdown(int r){
	int mid=(st[r].x+st[r].y)/2;
	tag(st[r].tag,r*2);
	tag(st[r].tag,r*2+1);
	st[r].tag=0;
}
void update(int x,int y,int k,int r=1){
	if(x>st[r].y||y<st[r].x)return;
	if(x<=st[r].x&&y>=st[r].y){
		tag(k,r);
		return;
	}
	pushdown(r);
	update(x,y,k,r*2);
	update(x,y,k,r*2+1);
	pushup(r);
}
int sum(int x,int y,int r=1){
	if(x>st[r].y||y<st[r].x)return 0;
	if(x<=st[r].x&&y>=st[r].y)return st[r].s;
	pushdown(r);
	return sum(x,y,r*2)+sum(x,y,r*2+1);
}
int main(){
	cin>>n>>m;
	forup(i,1,n,1)cin>>a[i];
	build();
	forup(i,1,m,1){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y,k;
			cin>>x>>y>>k;
			update(x,y,k);
		}
		else{
			int x,y;
			cin>>x>>y;
			cout<<sum(x,y)<<endl;
		}
	}
	return 0;
}
/******\
|ych153|
\******/
//17分钟码完并通过样例测试 
