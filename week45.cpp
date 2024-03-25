#include<bits/stdc++.h>
using namespace std;
const int N = 3001; 
int n,m,q;
int x,y,top;
int g[N][N],h[N][N],sta[N];
int l[N],r[N];

int work(int h[]){
	h[0] = h[m+1] = -1;
	top = 0;
	sta[++top] = 0;
	for(int i =1; i <= m; ++i){
		while(top&&h[sta[top]] >= h[i]) top--;
		l[i] = sta[top];
		sta[++top] = i; 
	}
	top = 0;
	sta[++top] = m+1;
	for(int i = m; i >= 1; --i){
		while(top&&h[sta[top]] >= h[i]) top--;
		r[i] = sta[top];
		sta[++top] = i; 
	}
	int ret = 0;
	for(int i = 1; i <= m; ++i){
		ret = max(ret,h[i] * (r[i] - l[i] - 1));
	}
	return ret;
}
int main(){
	cin>>n>>m>>q;
	while(q--){
		cin>>x>>y;
		g[x][y] = -1;
	}
	for(int i =1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(g[i][j] == -1){
				h[i][j] = 0;
			}else{
				h[i][j] = h[i-1][j]+1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = max(ans,work(h[i]));
	}
	cout<<ans;
	return 0;
}
