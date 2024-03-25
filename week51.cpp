#include<bits/stdc++.h>
using namespace std;
const int N = 32010;
int a[N],ans[N];
int n,x,y;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int m){
	for(int i = x; i <= N; i+=lowbit(i)){
		a[i] += m;
	}
}
int ask(int x){
	int ret = 0;
	for(int i = x; i; i -= lowbit(i)){
		ret += a[i];
	}
	return ret;
}
int main(){
	cin>>n;
	memset(a,0,sizeof a);
	memset(ans,0,sizeof ans);
	for(int i = 1; i <= n; ++i){
		cin>>x>>y;
		add(x+1,1);
		ans[ask(x+1)]++;
	} 
	for(int i = 1; i <= n; ++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}
