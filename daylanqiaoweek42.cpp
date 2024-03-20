#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
struct point{
	int x,y,z;
}q[N];
int p[N];
int find(int x){
	if(p[x] != x){
		p[x] = find(p[x]);
	}
	return p[x];
}
int t;
int main(){
	cin>>t;
	while(t--){
		int n,h,r;
		scanf("%d%d%d",&n,&h,&r);
		for(int i = 0; i <= n+1; ++i){
			p[i] = i;
		}
		for(int i = 1; i <= n; ++i){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			q[i].x = x;
			q[i].y = y;
			q[i].z = z;
			if(abs(z) < r)	p[find(i)] = p[find(0)];
			if(abs(z) + r >= h) p[find(i)] = p[find(n+1)];
		}
		for(int i = 1; i < n; ++i){
			for(int j = 1; j < n; ++j){
				ll dx = q[i].x - q[j].x;
				ll dy = q[i].y - q[j].y;
				ll dz = q[i].z - q[j].z;
				if(dx * dx + dy * dy + dz * dz <= 4 * (ll)r * r){
					p[find(i)] = find(j);
				}
			}
			if(find(0) == find(n+1)){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
