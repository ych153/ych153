#include<bits/stdc++.h>
using namespace std;
#define R register
#define forup(i,a,b,n) for(int i=a;i<=b;i+=n)
#define fordown(i,a,b,n) for(int i=a;i>=b;i-=n)
#define forup_q(i,a,b,n) for(R int i=a;i<=b;i+=n)
#define fordown_q(i,a,b,n) for(R int i=a;i>=b;i-=n)
#define lowbit(i) (i&-i)
int n,m;
int t[530000];
void update(int a,int i){
	while(i<=n)t[i]+=a,i+=lowbit(i);
}
int sum(int i){
	int sum=0;
	while(i)sum+=t[i],i-=lowbit(i);
	return sum;
}
int main(){
	cin>>n>>m;
	forup_q(i,1,n,1){
		int a;
		scanf("%d",&a);
		update(a,i);
	}
	forup_q(i,1,m,1){
		int a,x,y;
		scanf("%d%d%d",&a,&x,&y);
		if(a==1){
			update(y,x);
		}
		else{
			cout<<sum(y)-sum(x-1)<<endl;
		}
	}
	return 0;
}
/******\
|ych153|
\******/

