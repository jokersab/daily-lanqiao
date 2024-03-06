#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int N = 100001;
int num[N],b[N];
int n,m;
long long int ans = 0,sum = 0;
int main(){
	cin>>n;
	for(int i = 1; i <= n; ++i)	scanf("%d",&num[i]);
	cin>>m;
	int x1,x2;
	while(m--){
		scanf("%d%d",&x1,&x2);
		b[x1] += 1;
		b[x2+1] -= 1;
	}
	for(int i = 1; i <= n; ++i){
		b[i] += b[i-1];
		sum += (long long) num[i] * b[i];
	}
	sort(num+1,num+n+1);
	sort(b+1,b+n+1);
	for(int i = 1; i <= n; ++i){
		ans += (long long) num[i]*b[i];
	}
	cout<<ans-sum;
	return 0;
}
