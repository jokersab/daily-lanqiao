#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000001;
int d[N],w[N],l[N],r[N];
long long int b[N];
int n,m;
bool check(int pos){
	memset(b,0,sizeof b);
	for(int i = 1; i <= pos; ++i){
		b[l[i]] += d[i];
		b[r[i]+1] -= d[i];
	}
	for(int i = 1; i <= n; ++i){
		b[i] += b[i-1];
		if(b[i] > w[i]) return false;
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)	cin>>w[i];
	for(int i = 1; i <= m; ++i)	cin>>d[i]>>l[i]>>r[i];
	int l = 0,r = m;
	while(l < r){
		int mid = (l+r+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	if(r == m){
		cout<<0;
	}else{
		cout<<-1<<endl<<r+1;
	}
	return 0;
}
